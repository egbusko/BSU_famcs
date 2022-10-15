#include <iostream>  
#include <string>
#include "MyString.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, ".1251");

	string stroka_dlia_vvoda;
	int num_1, num_2;

	String_ Obj1("Hello");
	String_ Obj2(Obj1);
	//String_ Obj3("Friend");
	Obj2.ShowStr();

	int n;
	cout << "Number of strigs" << endl;
	cin >> n;
	cout << endl;
	String_ * mas_of_strok = new String_[n];
	
	
	for (int i = 0; i < n; i++)	{
		cout << "Введите строку № " << i + 1 << endl;
		cin >> stroka_dlia_vvoda;
		mas_of_strok[i].SetStr(stroka_dlia_vvoda);
	}

/////////////////////////////////////////////////////////////////////////
	cout << "Введите номер строки для сложения\n";
	cin >> num_1;
	Obj1.ShowStr();
	Obj1.Add(&mas_of_strok[num_1-1]);
	Obj1.ShowStr();
/////////////////////////////////////////////////////////////////////////

	cout << "Введите номера строк для сравнения\n";
	cin >> num_1>>num_2;
	int cmp_result = Obj1.Cmp_(&mas_of_strok[num_1-1], &mas_of_strok[num_2-1]);
	
	if (cmp_result > 1)	{
		cout << "Строка ";
		mas_of_strok[num_1-1].ShowStr();
		cout << " больше ";
		mas_of_strok[num_2-1].ShowStr();
	}
	else 
		if (cmp_result == 0) {
			cout << "Строка ";
			mas_of_strok[num_1-1].ShowStr();
			cout << " равна ";
			mas_of_strok[num_2-1].ShowStr();
		}
		else {
			cout << "Строка ";
			mas_of_strok[num_1-1].ShowStr();
			cout << " меньше ";
			mas_of_strok[num_2-1].ShowStr();
		}
	system("pause");
	system("cls");
/////////////////////////////////////////////////////////////////////////

	int num_cout;
	cout << "Введите сколько строк вы хотите вывести - ";
	cin >> num_cout;
	cout << endl;
	int * mas_num_cout = new int[num_cout];
	for (int i = 0; i < num_cout; i++)
	{
		cout << "Введите номер строки ";
		cin >> mas_num_cout[i];
	}

	for (int i = 0; i < num_cout; i++)	
	{
		mas_of_strok[mas_num_cout[i]-1].ShowStr();
		cout << endl;
	}
	cout << endl;
	delete[] mas_of_strok;
	system("pause");
	return 0;
}
