// Boss.cpp : This file contains the 'main' function. Program execution begins and ends there.
//


#include "pch.h"
#include <windows.h>
#include <iostream>


#include <stdio.h>
#include <conio.h>

using namespace std;

int main()
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;


	char czCommandLine[] = "C:\\Egor\\Univer\\Programming\\Visual Stud\\source\\repos\\4 ñåìåñòð\\C2\\Scout\\Debug\\Scout.exe";

	int numScouts;
	cout << "Enter number of Scounts: ";
	cin >> numScouts;

	DWORD dwEvent;
	HANDLE e_ready = CreateEvent(NULL, FALSE, TRUE, "ready_to_work");
	HANDLE e_dot = CreateEvent(NULL, FALSE, FALSE, "dot_entred");
	HANDLE e_hyphen = CreateEvent(NULL, FALSE, FALSE, "minus_entered");
	HANDLE e_other = CreateEvent(NULL, FALSE, FALSE, "other_symbol_entered");
		HANDLE ghEvents[3];
	ghEvents[0] = e_dot;
	ghEvents[1] = e_hyphen;
	ghEvents[2] = e_other;

	HANDLE mutex_is_busy = CreateMutex(NULL, TRUE, "is_busy");





	for (int i = 0; i < numScouts; i++)	{
		if (!CreateProcess(czCommandLine, NULL,NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &cif, &pi) == TRUE) {
			cout << "process, handle " << pi.hProcess << " " << GetLastError() << endl;					
		}
	}


	bool tmp;
	for (int i = 0; i < numScouts; i++) {
		tmp = false;
		SetEvent(e_ready);

		
		while (!tmp) {
			dwEvent = WaitForMultipleObjects(3, ghEvents, FALSE, INFINITE);
		
			switch (dwEvent)
			{
			case WAIT_OBJECT_0 + 0:
				cout << ".";
				break;

			case WAIT_OBJECT_0 + 1:
				cout << "-";
				break;

			case WAIT_OBJECT_0 + 2:
				cout << endl;
				tmp = true;
				break;
				
			default:
				printf("Wait error: %d\n", GetLastError());
				ExitProcess(0);
			}
		}
	}
	CloseHandle(e_ready);
	CloseHandle(e_dot);
	CloseHandle(e_hyphen);
	CloseHandle(e_other);

	system("pause");
	return 0;
}

/*
#include "pch.h"
#include <windows.h>
#include <conio.h>
#include <iostream>
using namespace std;

int main()
{
	char lpszAppName[] = "C:\\ConsoleProcess.exe";
	STARTUPINFO si;
	PROCESS_INFORMATION piApp;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(STARTUPINFO);
	// create a new console process
	if (!CreateProcess((LPCWSTR)"C:\\Egor\\Univer\\Programming\\Visual Stud\\source\\repos\\4 ñåìåñòð\\Boss\\Debug\\Boss.exe", NULL, NULL, NULL, FALSE,
		CREATE_NEW_CONSOLE, NULL, NULL, &si, &piApp))
	{
		_cputs("The new process is not created.\n");
		_cputs("Check a name of the process.\n");
		_cputs("Press any key to finish.\n");
		_getch();
		return 0;
	}
	_cputs("The new process is created.\n");
	// waiting for the end of the created process
	WaitForSingleObject(piApp.hProcess, INFINITE);
	// close the handles of this process in the current process
	CloseHandle(piApp.hThread);
	CloseHandle(piApp.hProcess);
	return 0;
}
*/
//ready
//.
//-
//any other symbol - end sending
//end sending
