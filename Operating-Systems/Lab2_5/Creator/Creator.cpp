
#include "pch.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
using namespace std;


struct order {
	char   name[10];	
	int    amount;    
	double price;    
};


int main(int argc, char** argv)
{
	HANDLE e_creater = CreateEvent(NULL, FALSE, TRUE, "creater_ev");
	HANDLE e_cr_ended = CreateEvent(NULL, FALSE, FALSE, "creater_ended");

	WaitForSingleObject(e_creater, INFINITE);


	   
	int numStructs = 0;
	cout << "Enter num of Structures: ";
	cin >> numStructs;
	cout << endl;
	order* masOrds = new order[numStructs];
	string path = "..\\..\\";
	path += argv[argc - 1];


	ofstream fOutBin(path, ios::binary);	
	fOutBin.write((char*)&numStructs, 4);

	for (int i = 0; i < numStructs; i++) {
		cout << "Enter  name  of " << i + 1 << " product: ";
		cin >> masOrds[i].name;
		cout << "Enter amount of " << i + 1 << " product: ";
		cin >> masOrds[i].amount;
		cout << "Enter price  of " << i + 1 << " product: ";
		cin >> masOrds[i].price;
		cout << endl;

		fOutBin.write((char*)&masOrds[i].name, 10);
		fOutBin.write((char*)&masOrds[i].amount, 4);
		fOutBin.write((char*)&masOrds[i].price, 8);
	}
	if(!SetEvent(e_cr_ended))
		cout<< "SetEv error: " << GetLastError() << endl;
	fOutBin.close();

	
	/*for (int i = 0; i < numStructs; i++) {
		cout << masOrds[i].name << " ";
		cout << masOrds[i].amount << " ";
		cout << masOrds[i].price << " ";
		cout << endl;
	}*/


	cout << endl;
	CloseHandle(e_creater);
	CloseHandle(e_cr_ended);
	//ExitProcess(0);
	system("pause");
	return 0;
}