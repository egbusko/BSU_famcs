//5lab

#include "pch.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <mutex>
#include <unordered_map>
#include "StrHeader.h"
using namespace std;

void isEnd(void *lParam);

struct toSend {
	int id;
	int command;
	Student st;
	int error;			//0-noError  1-noneStud  2-busyStud
	char errDisc[20];
};


struct ended {
	int flag;
	int num;
	HANDLE *hThreadsReady;
};



int main()
{
	int numStud = 6;
	Journal myJournal(numStud);

	string path = "..\\..\\";
	string fBinName = "binFile.csv";
	ofstream fOutBin((path + fBinName), ios::binary);
	fOutBin << myJournal;
	fOutBin.close();

	Journal myJournal2;
	ifstream fInBin((path + fBinName), ios::binary);
	fInBin >> myJournal2;
	fInBin.close();
	cout << "----NOT modified file---- \n";
	myJournal2.wrConcole();




	typedef pair <const int, int> cInt2Int;
	unordered_map <int, int> mapModifingStuds;
	mapModifingStuds.clear();
	int numClients = 2;
	//cout << "\n\nEnter the numClients: ";
	//cin >> numClients; 
	cout << endl;


	BOOL   fConnected;
	HANDLE hNamedPipe;
	char  lpszPipeName[] = "\\\\.\\pipe\\MyPipe";

	hNamedPipe = CreateNamedPipe(lpszPipeName, PIPE_ACCESS_DUPLEX,
		PIPE_TYPE_MESSAGE | PIPE_READMODE_MESSAGE | PIPE_WAIT,
		PIPE_UNLIMITED_INSTANCES, 512, 512, 5000, NULL);

	if (hNamedPipe == INVALID_HANDLE_VALUE) {
		cout << "#CreateNamedPipe_Error";
	}


	char lpszComLine[80];
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);

	char CreatorProcPath[] = "..\\..\\client\\Debug\\client.exe";
	for (int i = 1; i <= numClients; i++) {
		wsprintf(lpszComLine, "..\\..\\client\\Debug\\client.exe %d", i);
		if (!CreateProcess(CreatorProcPath, lpszComLine, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
			cout << "processCREATE, handle " << pi.hProcess << " " << GetLastError() << endl;
		}
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	
	
	HANDLE mutex_is_busy = CreateMutex(NULL, FALSE, "isPipeBusy");

	ended structEnd;
	structEnd.num = numClients;
	structEnd.flag = 1;
	structEnd.hThreadsReady = new HANDLE[numClients];
	for (int i = 0; i < numClients; i++) {
		structEnd.hThreadsReady[i] = CreateEvent(NULL, TRUE, FALSE, "ended" + i);
	}
	if (CreateThread(NULL, 1024, (LPTHREAD_START_ROUTINE)isEnd, &structEnd, NULL, NULL) == NULL) {
		cout << "#Error thread";
	}


	int flag = numClients;
	toSend nData;
	DWORD dwBytesRead;
	int i = 0;

	while (structEnd.flag != 0) {
		i > 0? DisconnectNamedPipe(hNamedPipe):i++;

		cout << i++ << " Waiting for connect...       :" << hNamedPipe << "\n";
		if (!ConnectNamedPipe(hNamedPipe, NULL)) {
			cout << "#ConnectNamedPipe_Error\n"<< hNamedPipe << "\n";
			CloseHandle(hNamedPipe);
			system("pause");
		}
		cout << "ConnectedNamedPipe - ";

		cout << "hReadPipe :" << hNamedPipe << "\n";
		if (!ReadFile(hNamedPipe, &nData, sizeof(nData), &dwBytesRead, NULL)){
			cout << "Read from the pipe failed.\n";
		}
		switch (nData.command) {
		case 0: {
			if (mapModifingStuds.find(nData.st.num) == mapModifingStuds.end()) {
				if (myJournal.getIndexbyId(nData.st.num) == -1) {
					nData.error = 1;
					DWORD dwBytesWritten;
					cout << "hWritePipe:" << hNamedPipe << "\n";
					if (!WriteFile(hNamedPipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
						cout << "Write to file failed.\n";
					}
				}
				else {
					mapModifingStuds.insert(cInt2Int(nData.st.num, nData.st.num));
					Student tmp = readStudBin(nData.st.num);
					strncpy(nData.st.name, tmp.name, 20);
					nData.st.grade = tmp.grade;

					DWORD dwBytesWritten;
					cout << "hWritePipe:" << hNamedPipe << "\n";
					if (!WriteFile(hNamedPipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
						cout << "Write to file failed.\n";
					}
				}
			}
			else {
				nData.error = 2;
				DWORD dwBytesWritten;
				if (!WriteFile(hNamedPipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
					cout << "Write to file failed.\n";
				}
			}
			break;
		}
		case 1: {
			if (mapModifingStuds.find(nData.st.num) != mapModifingStuds.end()) {
				if (myJournal.getIndexbyId(nData.st.num) != -1) {
					writeStudBin(nData.st, nData.st.num);
				}
				mapModifingStuds.erase(nData.st.num);
			}
			break;
		}
		case 2: {
			if (mapModifingStuds.find(nData.st.num) == mapModifingStuds.end()) {
				if (myJournal.getIndexbyId(nData.st.num) == -1) {
					nData.error = 1;
					DWORD dwBytesWritten;
					cout << "hWritePipe:" << hNamedPipe << "\n";
					if (!WriteFile(hNamedPipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
						cout << "Write to file failed.\n";
					}
				}
				else {
					Student tmp = readStudBin(nData.st.num);
					strncpy(nData.st.name, tmp.name, 20);
					nData.st.grade = tmp.grade;

					DWORD dwBytesWritten;
					cout << "hWritePipe:" << hNamedPipe << "\n";
					if (!WriteFile(hNamedPipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
						cout << "Write to file failed.\n";
					}
				}
			}
			else {
				nData.error = 2;
				DWORD dwBytesWritten;
				if (!WriteFile(hNamedPipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
					cout << "Write to file failed.\n";
				}
			}
			break;
		}
		default:
			Sleep(10);
			SetEvent(structEnd.hThreadsReady[nData.id - 1]);
			Sleep(10);
			break;
		}
	}


	Journal myJournal3;
	ifstream fInBin2((path + fBinName), ios::binary);
	fInBin2 >> myJournal3;
	fInBin2.close();
	cout << "\n\n----Modified file---- \n";
	myJournal3.wrConcole();


	mapModifingStuds.clear();
	CloseHandle(hNamedPipe);
	CloseHandle(mutex_is_busy);


	_cputs("Press any key to exit.\n");
	_getch();
	//system("pause");
	return 0;
}


void isEnd(void *lParam) {
	ended *obj = (ended*)lParam;
	int ind = 0;
	WaitForMultipleObjects(obj->num, obj->hThreadsReady, TRUE, INFINITE);
	obj->flag = 0;
	Sleep(10);
}