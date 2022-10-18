#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;





//Бусько Егор
//Всё, кроме графического интерфейса





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
	int NumOfInt1 = AmountOfRows("ArrInt1.txt");
	int* arrInt1 = new int[NumOfInt1];

	for (int i = 0; i < NumOfInt1; i++) {
		fIntTxt_1 >> arrInt1[i];
	}
	fIntTxt_1.close();


	/*for (int i = 0; i < NumOfInt1; i++)
		cout << arrInt1[i] << " ";
	cout << endl;*/





	ifstream fIntTxt_2("ArrInt2.txt");
	int NumOfInt2 = AmountOfRows("ArrInt2.txt");
	int* arrInt2 = new int[NumOfInt2];

	for (int i = 0; i < NumOfInt2; i++) {
		fIntTxt_2 >> arrInt2[i];
	}
	fIntTxt_2.close();


	/*for (int i = 0; i < NumOfInt2; i++)
		cout << arrInt2[i] << " ";
	cout << endl;*/





	ifstream fStrTxt_1("ArrStr1.txt");
	int NumOfStr1 = AmountOfRows("ArrStr1.txt");
	string* arrStr1 = new string[NumOfStr1];

	for (int i = 0; i < NumOfStr1; i++) {
		fStrTxt_1 >> arrStr1[i];
	}
	fStrTxt_1.close();

	/*for (int i = 0; i < NumOfStr1; i++)
		cout << arrStr1[i] << " ";
	cout << endl;*/





	ifstream fStrTxt_2("ArrStr2.txt");
	int NumOfStr2 = AmountOfRows("ArrStr2.txt");
	string* arrStr2 = new string[NumOfStr2];

	for (int i = 0; i < NumOfStr2; i++) {
		fStrTxt_2 >> arrStr2[i];
	}
	fStrTxt_2.close();

	/*for (int i = 0; i < NumOfStr2; i++)
		cout << arrStr2[i] << " ";
	cout << endl;*/



/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////


	cout << "THERE'S ALSO COUT IN FILES !" << endl << endl << endl;

	
	Int_deque<int> IntDeque1;
	for (int i = 0; i < NumOfInt1; i++)
		IntDeque1.push_back(arrInt1[i]);
	cout << "1st Int Deque: ";
	view_the_list(IntDeque1);


	Int_deque<int> IntDeque2;
	for (int i = 0; i < NumOfInt2; i++)
		IntDeque2.push_back(arrInt2[i]);
	cout << "2nd Int Deque: ";
	view_the_list(IntDeque2);





	IntDeque1.Union(IntDeque2);
	cout << "Union Deque:   ";
	view_the_list(IntDeque1);


	Int_deque<int> IntDeque3;
	IntDeque3.Copy(IntDeque2);
	cout << "Copy Deque:   ";
	view_the_list(IntDeque3);





	int NumForBinUnion = NumOfInt1 + NumOfInt2;
	int* BinArrIntUnion = new int[NumForBinUnion];
	for (int i = 0; i < NumForBinUnion; i++)
	{
		BinArrIntUnion[i] = IntDeque1[i];
	}


	int NumForBinCopy = NumOfInt2;
	int* BinArrIntCopy = new int[NumForBinCopy];
	for (int i = 0; i < NumForBinCopy; i++)
	{
		BinArrIntCopy[i] = IntDeque3[i];
	}
	

	//В бинарном файле: ("кол-во эл-тов объединения") ("массив union") ("кол-во эл-тов копирования") ("массив copy")

	ofstream fOutBinInt1("Int.bin", ios::binary);
	fOutBinInt1.write((char*)&NumForBinUnion, sizeof(NumForBinUnion));
	for (int i = 0; i < NumForBinUnion; i++) {
		fOutBinInt1.write((char*)&BinArrIntUnion[i], 4);
	}
	fOutBinInt1.write((char*)&NumForBinCopy, sizeof(NumForBinCopy));
	for (int i = 0; i < NumForBinCopy; i++) {
		fOutBinInt1.write((char*)&BinArrIntCopy[i], 4);
	}
	fOutBinInt1.close();


/////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////


	cout << endl;

	Str_deque<string> StrDeque1;

	for (int i = 0; i < NumOfStr1; i++)
		StrDeque1.push_front(arrStr1[i]);
	cout << "1st Str Deque: ";
	view_the_list(StrDeque1);



	Str_deque<string> StrDeque2;

	for (int i = 0; i < NumOfStr2; i++)
		StrDeque2.push_front(arrStr2[i]);
	cout << "2nd Str Deque: ";
	view_the_list(StrDeque2);



	StrDeque1.Union(StrDeque2);
	cout << "Union Deque:   ";
	view_the_list(StrDeque1);


	Str_deque<string> StrDeque3;
	StrDeque3.Copy(StrDeque2);
	cout << "Copy Deque:   ";
	view_the_list(StrDeque3);



	int strNumBinUnion = NumOfStr1 + NumOfStr2;
	string* BinArrStrUnion = new string[strNumBinUnion];
	for (int i = 0; i < strNumBinUnion; i++)
	{
		BinArrStrUnion[i] = StrDeque1[i];
	}


	int strNumBinCopy = NumOfStr2;
	string* BinArrStrCopy = new string[strNumBinCopy];
	for (int i = 0; i < strNumBinCopy; i++)
	{
		BinArrStrCopy[i] = StrDeque3[i];
	}





	ofstream OutStrFile("OutputStr.txt");
	OutStrFile << "Union of 2 arrays         :     ";
	for (int i = 0; i < strNumBinUnion; i++) {
		OutStrFile << BinArrStrUnion[i] << " ";
	}
	OutStrFile << endl;

	OutStrFile << "Copy of 2nd array into 3rd:     ";
	for (int i = 0; i < strNumBinCopy; i++) {
		OutStrFile << BinArrStrCopy[i] << " ";
	}
	OutStrFile.close();
	






	try {
		int iEl;
		cout << endl << "Enter index to cout element: ";
		cin >> iEl;
		cout << StrDeque1[iEl];
	}

	catch (BadIndex)	{
		cout << " Bad Index\n";
		system("pause");
		return 0;
	}
	

	cout << endl;
	system("pause");
	return 0;
}