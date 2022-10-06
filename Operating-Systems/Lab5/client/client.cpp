//5lab

#include "pch.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;


struct Student {
	int num;
	char name[20];
	double grade;
};

struct toSend {
	int id;
	int command;
	Student st;
	int error;				//0-noError  1-noneStud  2-busyStud
	char errDisc[20];
};


int hashFunc(int studNum) {
	return studNum % 100;
}


HANDLE connectClient() {
	HANDLE hNamedPipe;
	char  lpszPipeName[] = "\\\\.\\pipe\\MyPipe";
	hNamedPipe = CreateFile(lpszPipeName, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, 0, NULL);
	if (hNamedPipe == INVALID_HANDLE_VALUE) {
		cout << hNamedPipe << "#CreateNamedPipe_Error\n";
		system("pause");
	}
	return hNamedPipe;
}




int main(int argc, char **argv)
{
	HANDLE mutex_is_busy = CreateMutex(NULL, TRUE, "isPipeBusy");
	HANDLE hNamedPipe;
	DWORD  cbWritten;
	DWORD  cbRead;
	char   szBuf[256];
	int idClient;
	idClient = (int)atoi(argv[1]);
	cout << "idClient: " << idClient << "\n";

	bool flag = true;
	int action;

	while (flag) {
		cout << "1. modify record\n" <<
			"2. read record\n" <<
			"3. exit\n" <<
			"--select: ";
		cin >> action;

		switch (action) {
		case 1: {
			toSend myLetter;
			myLetter.id = idClient;
			myLetter.error = 0;
			myLetter.command = 0;
			int tmpId;
			cout << "id of the record to modify: ";
			cin >> tmpId;

			WaitForSingleObject(mutex_is_busy, INFINITE);
			myLetter.st.num = hashFunc(tmpId);

			hNamedPipe = connectClient();
			DWORD dwBytesWritten;
			if (!WriteFile(hNamedPipe, &myLetter, sizeof(myLetter), &dwBytesWritten, NULL)) {
				_cputs("Write to file failed.\n");
			}
			DWORD dwBytesRead;
			if (!ReadFile(hNamedPipe, &myLetter, sizeof(myLetter), &dwBytesRead, NULL)) {
				_cputs("Read from the pipe failed.\n");
			}
			ReleaseMutex(mutex_is_busy);
			CloseHandle(hNamedPipe);


			if (myLetter.error == 0) {
				cout << "Stud from server: ";
				cout << tmpId << " ";
				cout << myLetter.st.name << " ";
				cout << myLetter.st.grade << " ";
				cout << endl;

				myLetter.error = 0;
				myLetter.command = 1;
				cout << "new name: ";
				cin >> myLetter.st.name;
				cout << "new grade: ";
				cin >> myLetter.st.grade;

				WaitForSingleObject(mutex_is_busy, INFINITE);
				hNamedPipe = connectClient();
				if (!WriteFile(hNamedPipe, &myLetter, sizeof(myLetter), &dwBytesWritten, NULL)) {
					_cputs("Write to file failed.\n");
				}
				ReleaseMutex(mutex_is_busy);
				CloseHandle(hNamedPipe);
			}
			else if (myLetter.error == 1) {
				myLetter.error = 0;
				cout << "No student with such id, try again\n";
			}
			else if (myLetter.error == 2) {
				myLetter.error = 0;
				cout << "Student is now busy, try later\n";
			}
			else {
				myLetter.error = 0;
				cout << "Error, try again\n";
			}
			cout << endl;
			break;
		}
		case 2: {
			toSend myLetter;
			myLetter.id = idClient;
			myLetter.error = 0;
			myLetter.command = 2;
			int tmpId;
			cout << "id of the record to read:";
			cin >> tmpId;

			WaitForSingleObject(mutex_is_busy, INFINITE);
			myLetter.st.num = hashFunc(tmpId);

			hNamedPipe = connectClient();
			DWORD dwBytesWritten;
			if (!WriteFile(hNamedPipe, &myLetter, sizeof(myLetter), &dwBytesWritten, NULL)) {
				_cputs("Write to file failed.\n");
			}
			DWORD dwBytesRead;
			if (!ReadFile(hNamedPipe, &myLetter, sizeof(myLetter), &dwBytesRead, NULL)) {
				_cputs("Read from the pipe failed.\n");
			}
			ReleaseMutex(mutex_is_busy);
			CloseHandle(hNamedPipe);

			if (myLetter.error == 0) {
				cout << "Stud from server: ";
				cout << tmpId << " ";
				cout << myLetter.st.name << " ";
				cout << myLetter.st.grade << " ";
				cout << endl;
			}
			else if (myLetter.error == 1) {
				myLetter.error = 0;
				cout << "No student with such id, try again\n";
			}
			else if (myLetter.error == 2) {
				myLetter.error = 0;
				cout << "Student is now busy, try later\n";
			}
			else {
				myLetter.error = 0;
				cout << "Error, try again\n";
			}
			cout << endl;
			break;
		}
		default:
			toSend myLetter;
			myLetter.id = idClient;
			myLetter.command = 3;
			WaitForSingleObject(mutex_is_busy, INFINITE);
			hNamedPipe = connectClient();
			DWORD dwBytesWritten;
			if (!WriteFile(hNamedPipe, &myLetter, sizeof(myLetter), &dwBytesWritten, NULL)) {
				_cputs("Write to file failed.\n");
			}
			ReleaseMutex(mutex_is_busy);
			CloseHandle(hNamedPipe);
			flag = false;
			cout << endl;
			break;
		}
	}
	CloseHandle(mutex_is_busy);

	system("pause");
	return 0;
}
