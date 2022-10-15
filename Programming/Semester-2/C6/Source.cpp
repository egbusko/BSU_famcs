#include <iostream>
#include <string>
#include "MyClass.h"
using namespace std;


int main()
{
	int num_type; int nCounter = 5;

	Int_num iNum;
	Doub_num dNum;
	Strings sStr;
	Chel cChel;

	Using_Lot lUser;
	
	
tryAgain:
	cout << "* int-1  double-2  string-3  your_own_class-4     ";
	cin >> num_type;

	switch (num_type)
	{
	case 1:
		lUser.UseIt(&iNum);
		break;
	case 2:
		lUser.UseIt(&dNum);
		break;
	case 3:
		lUser.UseIt(&sStr);
		break;
	case 4:
		lUser.UseIt(&cChel);
		break;
	default:
		lUser.UseIt(&iNum);
	}
	nCounter--;

if(nCounter >0)
	goto tryAgain;


	cout << endl;
	system("pause");
	return 0;
}