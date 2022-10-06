// Scout.cpp : This file contains the 'main' function. Program execution begins and ends there.

#include "pch.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
using namespace std;

int main()
{
	HANDLE e_ready = CreateEvent(NULL, FALSE, TRUE, "ready_to_work");
	HANDLE e_dot = CreateEvent(NULL, FALSE, FALSE, "dot_entred");
	HANDLE e_hyphen = CreateEvent(NULL, FALSE, FALSE, "minus_entered");
	HANDLE e_other = CreateEvent(NULL, FALSE, FALSE, "other_symbol_entered");
	HANDLE mutex_is_busy = CreateMutex(NULL, FALSE, "is_busy");


	cout << "Enter your SOS message: ";

	
	
	WaitForSingleObject(e_ready, INFINITE);

	char str_entered = ' ';
	
	while (true) {
		str_entered = _getch();
		
		if (str_entered == '.') {
			SetEvent(e_dot);
			cout << ".";
		}
		else if (str_entered == '-') {
			SetEvent(e_hyphen);
			cout << "-";
		}
		else {
			SetEvent(e_other);
			cout << "*other*" << endl;
			break;
		}
	}
	//ReleaseMutex(mutex_is_busy);


	ExitProcess(0);

	system("pause");
	return 0;

}