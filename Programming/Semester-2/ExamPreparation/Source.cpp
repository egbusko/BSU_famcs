#include "MyClass.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;




int main()
{
	Med A;

	ifstream fInTxt_1("1inFile.txt");
	A.In(fInTxt_1);
	fInTxt_1.close();

	A.SortDown();

	ofstream fOutTxt_1("1outFile.txt");
	A.Out(fOutTxt_1);
	fOutTxt_1.close();


	A.CmpFunc();

	char tmpname1[35];
	cout << " Enter name: " << endl;
	cin >> tmpname1;
	try	{
		A.poiskstudent(tmpname1,cout);
	}
	catch (nenaiden)	{
		cout << "nenaiden" << endl;
	}






	Price B;

	ifstream fInTxt_2("2inFile.txt");
	B.In(fInTxt_2);
	fInTxt_2.close();

	B.SortDown();

	ofstream fOutTxt_2("2outFile.txt");
	B.Out(fOutTxt_2);
	fOutTxt_2.close();


	B.CmpFunc();

	char tmpname[35];
	cout << " Enter name: " << endl;
	cin >> tmpname;
	try	{
		B.poiskstudent(tmpname,cout);
	}
	catch (nenaiden)	{
		cout << "nenaiden" << endl;
	}





	



	cout << endl;
	system("pause");
	return 0;
}
