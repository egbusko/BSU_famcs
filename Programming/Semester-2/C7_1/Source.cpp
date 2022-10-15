#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>

#include <iomanip>
using namespace std;




int AmountOfRows(string filename) {
	ifstream in(filename);
	int amount = 0;
	string c;
	while (getline(in, c)) {
		amount++;
	}
	in.close();
	return amount;
}





int main() 
{
	ifstream InFile("Input.txt");

	int NumOfPers = AmountOfRows("Input.txt");
	Phone* masPhones = new Phone[NumOfPers];

	for (int i = 0; i < NumOfPers; i++) {
		masPhones[i].In(InFile);
	}
	InFile.close();
	
	



	ofstream OutFile("Output.txt");
	for (int i = 0; i < NumOfPers; i++) {
		masPhones[i].Out(OutFile);
	}
	OutFile.close();



	
	ofstream OutBinFile("Bin.bin", ios::binary);
	OutBinFile.write((char*)&NumOfPers, sizeof(NumOfPers));
	for (int i=0; i < NumOfPers; i++)	{
		masPhones[i].WriteToBin(OutBinFile);
	}
	OutBinFile.close();





	ifstream InBinFile("Bin.bin", ios::binary);
	int numPersBin = 0;
	InBinFile.read((char*)&numPersBin, 4);
	Phone* masPhonesBin = new Phone[numPersBin];

	for (int i = 0; i < numPersBin; i++) {
		masPhonesBin[i].ReadToBin(InBinFile);
	}


	ofstream FuncFileTxt("Out_func.txt");
	ofstream FuncFileBin("Out_func.bin", ios::binary);
		chast_c7(masPhonesBin, numPersBin, FuncFileTxt, FuncFileBin);
	FuncFileTxt.close();
	FuncFileBin.close();





	/*ofstream FileWidth("Out_width.txt");
	FileWidth.width(10);
	FileWidth.setf(ios::left);
	masPhones[0].SetSurname("123456789101112");

	for (int i = 0; i < NumOfPers; i++) {
		FileWidth.width(10);
		
		FileWidth << masPhones[i].GetSurname() << " ";
		FileWidth.width(10);
		FileWidth << masPhones[i].GetName() << " ";
		FileWidth.width(10);
		FileWidth << masPhones[i].GetPatron() << " ";

		FileWidth.width(10);
		FileWidth << masPhones[i].GetAdress() << " ";
		FileWidth.width(10);
		FileWidth << masPhones[i].GetNumber() << " ";

		FileWidth.width(10);
		FileWidth << masPhones[i].GetSpeechInHours() << " ";
		FileWidth.width(10);
		FileWidth << masPhones[i].GetSpeechInMin() << " ";

		FileWidth.width(10);
		FileWidth << masPhones[i].GetSpeechOutHours() << " ";
		FileWidth.width(10);
		FileWidth << masPhones[i].GetSpeechOutMin() << endl;
	}
	FileWidth.close();



	ifstream InWidth("Out_width.txt");
	int NumOfPersW = AmountOfRows("Out_width.txt");
	Phone* masPhonesW = new Phone[NumOfPersW];

	for (int i = 0; i < NumOfPersW; i++) {
		masPhonesW[i].In(InWidth);
	}
	InWidth.close();

	for (int i = 0; i < NumOfPersW; i++)
	{
		masPhonesW[i].ShowSurname();
		masPhonesW[i].ShowName();
	}*/

	system("pause");
	return 0;
}