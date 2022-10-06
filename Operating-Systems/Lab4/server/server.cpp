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
	Journal myJournal;

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



	//  just test
	ofstream fOutBin54((fBinName), ios::binary);
	fOutBin54 << myJournal;
	fOutBin54.close();
	if (!rename("binFile.csv", "Kate.csv")) {
		//has renamed
		return 0;
	}
	//


	typedef pair <const int, int> cInt2Int;
	unordered_map <int, int> mapModifingStuds;
	mapModifingStuds.clear();
	int numClients = 1;
	//cout << "\n\nEnter the numClients: ";
	//cin >> numClients; 
	cout << endl;

	char lpszComLine[80];
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	SECURITY_ATTRIBUTES sa;
	HANDLE hWritePipe, hReadPipe;
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
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	if (!CreatePipe(&hReadPipe, &hWritePipe, &sa, 0)) {
		_cputs("Create pipe failed.\n");
	}

	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);


	char CreatorProcPath[] = "..\\..\\client\\Debug\\client.exe";

	for (int i = 1; i <= numClients; i++) {
		wsprintf(lpszComLine, "..\\..\\client\\Debug\\client.exe %d %d %d", (int)hWritePipe, (int)hReadPipe, i);
		if (!CreateProcess(CreatorProcPath, lpszComLine, NULL, NULL, TRUE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi)) {
			cout << "processCREATE, handle " << pi.hProcess << " " << GetLastError() << endl;
		}
		CloseHandle(pi.hProcess);
		CloseHandle(pi.hThread);
	}

	int flag = numClients;
	toSend nData;
	DWORD dwBytesRead;
	int i = 0;

	while (structEnd.flag!= 0) {
		cout << "hReadPipe:" << hReadPipe << "\n";
		if (!ReadFile(hReadPipe, &nData, sizeof(nData), &dwBytesRead, NULL)) {
			cout << "Read from the pipe failed.\n";
		}
		i++;
		switch (nData.command) {
		case 0: {
			if (mapModifingStuds.find(nData.st.num) == mapModifingStuds.end()) {
				if (myJournal.getIndexbyId(nData.st.num) == -1) {
					nData.error = 1;
					DWORD dwBytesWritten;
					cout << "hWritePipe:" << hWritePipe << "\n";
					if (!WriteFile(hWritePipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
						cout << "Write to file failed.\n";
					}
				}
				else {
					mapModifingStuds.insert(cInt2Int(nData.st.num, nData.st.num));
					strncpy(nData.st.name, myJournal.getStud(nData.st.num)->name, 20);
					nData.st.grade = myJournal.getStud(nData.st.num)->grade;

					DWORD dwBytesWritten;
					cout << "hWritePipe:" << hWritePipe << "\n";
					if (!WriteFile(hWritePipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
						cout << "Write to file failed.\n";
					}
				}
			}
			else {
				nData.error = 2;
				DWORD dwBytesWritten;
				if (!WriteFile(hWritePipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
					cout << "Write to file failed.\n";
				}
			}
			break;
		}
		case 1: {
			if (mapModifingStuds.find(nData.st.num) != mapModifingStuds.end()) {
				if (myJournal.getIndexbyId(nData.st.num) != -1) {
					myJournal.changeStud(nData.st.num, nData.st.name, nData.st.grade);
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
					cout << "hWritePipe:" << hWritePipe << "\n";
					if (!WriteFile(hWritePipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
						cout << "Write to file failed.\n";
					}
				}
				else {
					strncpy(nData.st.name, myJournal.getStud(nData.st.num)->name, 20);
					nData.st.grade = myJournal.getStud(nData.st.num)->grade;

					DWORD dwBytesWritten;
					cout << "hWritePipe:" << hWritePipe << "\n";
					if (!WriteFile(hWritePipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
						cout << "Write to file failed.\n";
					}
				}
			}
			else {
				nData.error = 2;
				DWORD dwBytesWritten;
				if (!WriteFile(hWritePipe, &nData, sizeof(nData), &dwBytesWritten, NULL)) {
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
	

	ofstream fOutBin2((path + fBinName), ios::binary);
	fOutBin2 << myJournal;
	fOutBin2.close();

	Journal myJournal3;
	ifstream fInBin2((path + fBinName), ios::binary);
	fInBin2 >> myJournal3;
	fInBin2.close();
	cout << "\n\n----Modified file---- \n";
	myJournal3.wrConcole();


	mapModifingStuds.clear();
	CloseHandle(hReadPipe);
	CloseHandle(hWritePipe);
	CloseHandle(mutex_is_busy);


	_cputs("Press any key to exit.\n");
	_getch();
	//system("pause");
	return 0;
}


void isEnd(void *lParam) {
	ended *obj = (ended*)lParam;
	int ind = 0;
	WaitForMultipleObjects(obj->num, obj->hThreadsReady,TRUE,INFINITE);
	obj->flag = 0;
	Sleep(10);
}