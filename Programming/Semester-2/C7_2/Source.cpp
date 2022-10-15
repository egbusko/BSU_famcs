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
	ifstream fIntTxt_1("ArrInt1.txt");

	int NumOfElem1 = AmountOfRows("ArrInt1.txt");
	Array_<int> iArr1(NumOfElem1);

	for (int i = 0; i < iArr1.GetSize(); i++) {
		fIntTxt_1 >> iArr1.GetArray()[i];
	}
	fIntTxt_1.close();




	ifstream fIntTxt_2("ArrInt2.txt");

	int NumOfElem2 = AmountOfRows("ArrInt2.txt");
	Array_<int> iArr2(NumOfElem2);

	for (int i = 0; i < iArr2.GetSize(); i++) {
		fIntTxt_2 >> iArr2.GetArray()[i];
	}
	fIntTxt_2.close();




	ifstream fStrTxt_1("ArrStr1.txt");

	int NumOfElem3 = AmountOfRows("ArrStr1.txt");
	Array_<string> sArr1(NumOfElem3);

	for (int i = 0; i < sArr1.GetSize(); i++) {
		fStrTxt_1 >> sArr1.GetArray()[i];
	}
	fStrTxt_1.close();




	ifstream fStrTxt_2("ArrStr2.txt");

	int NumOfElem4 = AmountOfRows("ArrStr2.txt");
	Array_<string> sArr2(NumOfElem4);

	for (int i = 0; i < sArr2.GetSize(); i++) {
		fStrTxt_2 >> sArr2.GetArray()[i];
	}
	fStrTxt_2.close();


	




	cout << "1-st Int Arr:  " << iArr1 << endl
		 << "2-nd Int Arr:  " << iArr2 << endl << endl;
	Array_<int> iArr3, iArr4, iArr5;
	
	iArr3 = iArr1 + iArr2;
	cout << "Union: " << iArr3 << endl;

	iArr4 = iArr1 * iArr2;
	cout << "Cross: " << iArr4 << endl;

	iArr5 = iArr1 - iArr2;
	cout << "SySub: " << iArr5 << endl << endl << endl << endl;


	

	/*
	//Array_<int>  iArr3, iArr4, iArr5;
	////Array_<int> * iArr9 = Array_<int>::_union(iArr1, iArr2);
	////cout << endl << *iArr9 << endl;
	//iArr3.Union(iArr1, iArr2);
	//cout << "Union: " << iArr3 << endl;

	//iArr4.intersection(iArr1, iArr2);
	//cout << "Cross: " << iArr4 << endl;

	//iArr5.symrazn(iArr1, iArr2);
	//cout << "SySub: " << iArr5 << endl << endl << endl << endl;
	*/




	cout << "1-st Str Arr:  " << sArr1 << endl
		 << "2-nd Str Arr:  " << sArr2 << endl << endl;
	Array_<string> sArr3, sArr4, sArr5;

	sArr3 = sArr1 + sArr2;
	cout << "Union: " << sArr3 << endl;

	sArr4 = sArr1 * sArr2;
	cout << "Cross: " << sArr4 << endl;

	sArr5 = sArr1 - sArr2;
	cout << "SySub: " << sArr5 << endl;



	/*
	//Array_<string> sArr3, sArr4, sArr5;
	//sArr3.Union(sArr1, sArr2);
	//cout << "Union: " << sArr3 << endl;

	//sArr4.intersection(sArr1, sArr2);
	//cout << "Cross: " << sArr4 << endl;

	//sArr5.symrazn(sArr1, sArr2);
	//cout << "SySub: " << sArr5 << endl;


	*/
	
	system("pause");
	return 0;
}

