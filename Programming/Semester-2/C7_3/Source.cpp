#include "MyClass.h"
#include <iostream>
#include <fstream>
#include <string>
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
	{
			ifstream fIntTxt_1("ArrInt1.txt");
			int NumOfPersInt1 = AmountOfRows("ArrInt1.txt");
			int* arrInt1 = new int[NumOfPersInt1];

			for (int i = 0; i < NumOfPersInt1; i++) {
				fIntTxt_1 >> arrInt1[i];
			}
			fIntTxt_1.close();

		/*for (int i = 0; i < NumOfPersInt1; i++)
			cout << arrInt1[i] << " ";
		cout << endl;*/




		ofstream fOutBinInt1("1Int.bin", ios::binary);
		fOutBinInt1.write((char*)&NumOfPersInt1, sizeof(NumOfPersInt1));

		for (int i = 0; i < NumOfPersInt1; i++) {
			fOutBinInt1.write((char*)&arrInt1[i], 4);
		}
		fOutBinInt1.close();
	}


/////////////////////////////////////////////////////////////////////////////////////////////////
	{
		ifstream fIntTxt_2("ArrInt2.txt");
		int NumOfPersInt2 = AmountOfRows("ArrInt2.txt");
		int* arrInt2 = new int[NumOfPersInt2];

		for (int i = 0; i < NumOfPersInt2; i++) {
			fIntTxt_2 >> arrInt2[i];
		}
		fIntTxt_2.close();

		/*for (int i = 0; i < NumOfPersInt2; i++)
			cout << arrInt2[i] << " ";
		cout << endl;*/




		ofstream fOutBinInt2("2Int.bin", ios::binary);
		fOutBinInt2.write((char*)&NumOfPersInt2, sizeof(NumOfPersInt2));

		for (int i = 0; i < NumOfPersInt2; i++) {
			fOutBinInt2.write((char*)&arrInt2[i], 4);
		}
		fOutBinInt2.close();
	}



/////////////////////////////////////////////////////////////////////////////////////////////////
	{
		ifstream fStrTxt_1("ArrStr1.txt");
		int NumOfPersStr1 = AmountOfRows("ArrStr1.txt");
		string* arrStr1 = new string[NumOfPersStr1];

		for (int i = 0; i < NumOfPersStr1; i++) {
			fStrTxt_1 >> arrStr1[i];
		}
		fStrTxt_1.close();

		/*for (int i = 0; i < NumOfPersStr1; i++)
			cout << arrStr1[i] << " ";
		cout << endl;*/




		ofstream fOutBinStr1("1Str.bin", ios::binary);
		fOutBinStr1.write((char*)&NumOfPersStr1, sizeof(NumOfPersStr1));
		int len;
		for (int i = 0; i < NumOfPersStr1; i++) {
			len = arrStr1[i].length() + 1;
			fOutBinStr1.write((char*)&len, sizeof(len));

			fOutBinStr1.write((char*)arrStr1[i].c_str(), len);
		}
		fOutBinStr1.close();
	}


/////////////////////////////////////////////////////////////////////////////////////////////////
	{
		ifstream fStrTxt_2("ArrStr2.txt");
		int NumOfPersStr2 = AmountOfRows("ArrStr2.txt");
		string* arrStr2 = new string[NumOfPersStr2];

		for (int i = 0; i < NumOfPersStr2; i++) {
			fStrTxt_2 >> arrStr2[i];
		}
		fStrTxt_2.close();

		/*for (int i = 0; i < NumOfPersStr2; i++)
			cout << arrStr2[i] << " ";
		cout << endl;*/




		ofstream fOutBinStr2("2Str.bin", ios::binary);
		fOutBinStr2.write((char*)&NumOfPersStr2, sizeof(NumOfPersStr2));
		int len2;
		for (int i = 0; i < NumOfPersStr2; i++) {
			len2 = arrStr2[i].length() + 1;
			fOutBinStr2.write((char*)&len2, sizeof(len2));

			fOutBinStr2.write((char*)arrStr2[i].c_str(), len2);
		}
		fOutBinStr2.close();
	}


/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////



	int  tmp;
	int numLetters = 0;
	char s[1024];




	ifstream fInBinInt1("1Int.bin", ios::binary);
	int InumElBin1 = 0;
	fInBinInt1.read((char*)&InumElBin1, 4);
	int* BinArrInt1 = new int[InumElBin1];

	for (int i = 0; i < InumElBin1; i++) {
		fInBinInt1.read((char*)&tmp, 4);
		BinArrInt1[i] = tmp;
	}
	fInBinInt1.close();
	
	
	//cout << endl;
	cout << "1st Int Arr:   ";
	for (int i = 0; i < InumElBin1; i++)
		cout << BinArrInt1[i] << " ";
	cout << endl;

/////////////////////////////////////////////////////////////////////////////////////////////////



	ifstream fInBinInt2("2Int.bin", ios::binary);
	int InumElBin2 = 0;
	fInBinInt2.read((char*)&InumElBin2, 4);
	int* BinArrInt2 = new int[InumElBin2];

	for (int i = 0; i < InumElBin2; i++) {
		fInBinInt2.read((char*)&tmp, 4);
		BinArrInt2[i] = tmp;
	}
	fInBinInt2.close();




	//cout << endl;
	cout << "2nd Int Arr:   ";
	for (int i = 0; i < InumElBin2; i++)
		cout << BinArrInt2[i] << " ";
	cout << endl;

/////////////////////////////////////////////////////////////////////////////////////////////////



	ifstream fInBinStr1("1Str.bin", ios::binary);
	int StNumElBin1 = 0;
	fInBinStr1.read((char*)&StNumElBin1, 4);
	string* BinArrStr1 = new string[StNumElBin1];

	for (int i = 0; i < StNumElBin1; i++) {
		fInBinStr1.read((char*)&numLetters, 4);
		fInBinStr1.read((char*)s, numLetters);
		BinArrStr1[i] = s;
	}
	fInBinStr1.close();




	//cout << endl;
	cout << "1st Str Arr:   ";
	for (int i = 0; i < StNumElBin1; i++)
		cout << BinArrStr1[i] << " ";
	cout << endl;

/////////////////////////////////////////////////////////////////////////////////////////////////



	ifstream fInBinStr2("2Str.bin", ios::binary);
	int StNumElBin2 = 0;
	fInBinStr2.read((char*)&StNumElBin2, 4);
	string* BinArrStr2 = new string[StNumElBin2];

	for (int i = 0; i < StNumElBin2; i++) {
		fInBinStr2.read((char*)&numLetters, 4);
		fInBinStr2.read((char*)s, numLetters);
		BinArrStr2[i] = s;
	}
	fInBinStr2.close();



	//cout << endl;
	cout << "2nd Str Arr:   ";
	for (int i = 0; i < StNumElBin2; i++)
		cout << BinArrStr2[i] << " ";
	cout << endl;


/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////


	cout << endl << endl << endl;

	Int_num<int> iNum;
	iNum.SetSize(InumElBin1, InumElBin2);

	for (int i = 0; i < iNum.GetSize1(); i++)
		iNum.GetArray1()[i] = BinArrInt1[i];

	for (int i = 0; i < iNum.GetSize2(); i++)
		iNum.GetArray2()[i] = BinArrInt2[i];


	//iNum.Printing();

	cout << "Int union  :  ";
	iNum.Union();
	iNum.PrintArr();
	cout << "Int intets :  ";
	iNum.intersection();
	iNum.PrintArr();
	cout << "Int SymRazn:  ";
	iNum.symrazn();
	iNum.PrintArr();
	cout << endl;




	Strings<string> sStr;
	sStr.SetSize(StNumElBin1, StNumElBin2);

	for (int i = 0; i < sStr.GetSize1(); i++)
		sStr.GetArray1()[i] = BinArrStr1[i];

	for (int i = 0; i < sStr.GetSize2(); i++)
		sStr.GetArray2()[i] = BinArrStr2[i];


	cout << "Str union  :  ";
	sStr.Union();
	sStr.PrintArr();
	cout << "Str intets :  ";
	sStr.intersection();
	sStr.PrintArr();
	cout << "Str SymRazn:  ";
	sStr.symrazn();
	sStr.PrintArr();

/////////////////////////////////////////////////////////////////////////////////////////////////


	cout << endl;
	system("pause");
	return 0;
}