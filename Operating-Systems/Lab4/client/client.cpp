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
	return studNum % 10;
}



int main(int argc, char **argv)
{
	HANDLE hWritePipe, hReadPipe;
	HANDLE mutex_is_busy = CreateMutex(NULL,TRUE, "isPipeBusy");
	hWritePipe = (HANDLE)atoi(argv[1]);
	hReadPipe = (HANDLE)atoi(argv[2]);
	int idClient = (int)atoi(argv[3]);

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
			 

			DWORD dwBytesWritten;
			if (!WriteFile(hWritePipe, &myLetter, sizeof(myLetter), &dwBytesWritten, NULL)) {
				_cputs("Write to file failed.\n");
			}
			
			DWORD dwBytesRead;
			if (!ReadFile(hReadPipe, &myLetter, sizeof(myLetter), &dwBytesRead, NULL)) {
				_cputs("Read from the pipe failed.\n");
			}
			ReleaseMutex(mutex_is_busy);

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
				if (!WriteFile(hWritePipe, &myLetter, sizeof(myLetter), &dwBytesWritten, NULL)) {
					_cputs("Write to file failed.\n");
				}
				ReleaseMutex(mutex_is_busy);
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


			DWORD dwBytesWritten;
			if (!WriteFile(hWritePipe, &myLetter, sizeof(myLetter), &dwBytesWritten, NULL)) {
				_cputs("Write to file failed.\n");
			}
			
			DWORD dwBytesRead;
			if (!ReadFile(hReadPipe, &myLetter, sizeof(myLetter), &dwBytesRead, NULL)) {
				_cputs("Read from the pipe failed.\n");
			}
			ReleaseMutex(mutex_is_busy);

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
			DWORD dwBytesWritten;
			if (!WriteFile(hWritePipe, &myLetter, sizeof(myLetter), &dwBytesWritten, NULL)) {
				_cputs("Write to file failed.\n");
			}
			ReleaseMutex(mutex_is_busy);
			flag = false;
			cout << endl;
			break;
		}
	}

	CloseHandle(hWritePipe);
	CloseHandle(hReadPipe);
	CloseHandle(mutex_is_busy);

	system("pause");
	return 0;
}
