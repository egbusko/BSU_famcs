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
	HANDLE e_reporter = CreateEvent(NULL, FALSE, TRUE, "reporter_ev");
	HANDLE e_rep_ended = CreateEvent(NULL, FALSE, FALSE, "reporter_ended");

	WaitForSingleObject(e_reporter, INFINITE);
	

	string path = "..\\..\\";
	string binName;
	string fileReport;
	int minAmount;
	int minPrice;

	char * pch = strtok(argv[argc - 1], "#");
	binName = pch;
	pch = strtok(NULL, "#");
	fileReport = pch;
	pch = strtok(NULL, "#");
	minAmount = atoi(pch);
	pch = strtok(NULL, "#");
	minPrice = atoi(pch);
	pch = strtok(NULL, "#");
	


	
	int numStructs = 0;
	ifstream fInBinInt1(path+binName, ios::binary);
	fInBinInt1.read((char*)&numStructs, 4);
	order* masOrds = new order[numStructs];

	for (int i = 0; i < numStructs; i++){
		fInBinInt1.read((char*)&masOrds[i].name, 10);
		fInBinInt1.read((char*)&masOrds[i].amount, 4);
		fInBinInt1.read((char*)&masOrds[i].price, 8);
	}
	/*for (int i = 0; i < numStructs; i++) {
		cout << masOrds[i].name << " ";
		cout << masOrds[i].amount << " ";
		cout << masOrds[i].price << " ";
		cout << endl;
	}*/




	ofstream OutFileReport(path + fileReport);
	OutFileReport << "Report by file " << binName << "\n";
	for (int i = 0; i < numStructs; i++) {
		if ((masOrds[i].amount <= minAmount) && (masOrds[i].amount * masOrds[i].price <= minPrice)) {
			OutFileReport << masOrds[i].name << " "
				<< masOrds[i].amount << " "
				<< masOrds[i].price << "\n";
		}
	}
	SetEvent(e_rep_ended);
	OutFileReport.close();
	cout << "*have done the report\n\n";

	
	CloseHandle(e_reporter);
	CloseHandle(e_rep_ended);
	//ExitProcess(0);
	system("pause");
	return 0;
}