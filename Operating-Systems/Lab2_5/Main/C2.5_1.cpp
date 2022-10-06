#include "pch.h"
#include "windows.h"
#include "process.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;


struct order {
	char   name[10];	
	int    amount;      
	double price;    
};


int main()
{
	STARTUPINFO cif;
	ZeroMemory(&cif, sizeof(STARTUPINFO));
	PROCESS_INFORMATION pi;
	char CreatorProcPath[] = "..\\..\\Creator\\Debug\\Creator.exe";
	char ReportProcPath[] = "..\\..\\Reporter\\Debug\\Reporter.exe";
	HANDLE e_creater = CreateEvent(NULL, FALSE, TRUE, "creater_ev");
	HANDLE e_reporter = CreateEvent(NULL, FALSE, TRUE, "reporter_ev");
	HANDLE e_cr_ended = CreateEvent(NULL, FALSE, FALSE, "creater_ended");
	HANDLE e_rep_ended = CreateEvent(NULL, FALSE, FALSE, "reporter_ended");


	int numStructs = 0;
	string path = "..\\..\\";
	char* binName = new char [100];
	cout << "Enter the name of binFile: ";
	cin >> binName;


	if (!CreateProcess(CreatorProcPath, binName, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &cif, &pi) == TRUE) {
		cout << "processCREATE, handle " << pi.hProcess << " " << GetLastError() << endl;
	}  
	cout << endl;
	WaitForSingleObject(e_cr_ended, INFINITE);
	
	

	
	cout << "--This is in Bin: \n";
	ifstream fInBin(path + binName, ios::binary);
	fInBin.read((char*)&numStructs, 4);
	order* masOrds = new order[numStructs];

	for (int i = 0; i < numStructs; i++) {
		fInBin.read((char*)&masOrds[i].name, 10);
		fInBin.read((char*)&masOrds[i].amount, 4);
		fInBin.read((char*)&masOrds[i].price, 8);
	}
	for (int i = 0; i < numStructs; i++) {
		cout << masOrds[i].name << " ";
		cout << masOrds[i].amount << " ";
		cout << masOrds[i].price << " ";
		cout << endl;
	}
	fInBin.close();
	




	char* toSend = new char[100];
	toSend = binName;
	string fileReport;
	int minAmount = 0;
	int minPrice = 0;
	char*tm = new char[100];
	cout << "\nEnter file report name: ";
	cin >> fileReport;
	cout << "Enter min amount of products: ";
	cin >> minAmount;
	cout << "Enter min total cost of products: ";
	cin >> minPrice;
	strcat(toSend, "#");
	strcat(toSend, fileReport.c_str());
	strcat(toSend, "#");
	strcat(toSend, _itoa(minAmount, tm,10));
	strcat(toSend, "#");
	strcat(toSend, _itoa(minPrice,tm,10));


	if (!CreateProcess(ReportProcPath, toSend, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &cif, &pi) == TRUE) {
		cout << "processREPORT, handle " << pi.hProcess << " " << GetLastError() << endl;
	}
	WaitForSingleObject(e_rep_ended, INFINITE);
	


	cout << endl;
	ifstream fInReport(path + fileReport);	
	while (fInReport) {
		string str;
		getline(fInReport, str);
		cout << str << endl;
	}
	fInReport.close();

	


	CloseHandle(e_creater);
	CloseHandle(e_reporter);
	CloseHandle(e_cr_ended);
	CloseHandle(e_rep_ended);
 
	system("pause");
	return 0;
}