/*
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, b, c, d, x, y;
	cout << "Введите первое число\n";
	cin >> a;
	cout << "Введите второе число\n";
	cin >> b;
	cout << "Введите третье число\n";
	cin >> c;
		/*d = (a % 10) / 2;
		x = (b % 10) / 2;
		y = (c % 10) / 2;*/
	/* if ((d = (a / 2) % 10) != 0)
		cout << "Неверно\n" << d << "\n";
	else cout << "Верно";
	system("pause");
	return 0;
}
*/

#include <iostream>
using namespace std;
int main()
{
	int a, b, c;
	cout << "Enter 3 numbers. Press ENTER after each\n";
	cin>>a>>b>>c;
	if (a % 2 == 0 && b % 2 == 0 && c % 2 == 0)
	{
		if (a >= b && a >= c)
			cout<<"the biggest even number is "<<a;
		if (b >= c && b>= a)
			cout<<"the biggest even number is "<<b;
		if (c >= a && c >= b)
			cout<<"the biggest even number is "<<c;

	}
	   
	if (a % 2 == 0 && b % 2 == 0)
	{
		if (a > b)
			cout<<"the biggest even number is "<<a;
		else
			cout<<"the biggest even number is "<<b;
	}


	if (b % 2 == 0 && c % 2 == 0)
	{
		if (b > c)
			cout<<"the biggest even number is "<<b;
		else
			cout<<"the biggest even number is "<<c;
	}



	if (a % 2 == 0 && c % 2 == 0)
	{
		if (a > c)
			cout<<"the biggest even number is "<<a;
		else
			cout<<"the biggest even number is "<<c;
	}


	if (a % 2 == 0 && c % 2 != 0 && b % 2 != 0)
		cout<<"the biggest even number is "<<a;

	if (b % 2 == 0 && c % 2 != 0 && a % 2 != 0)
		cout<<"the biggest even number is "<<b;

	if (c % 2 == 0 && c % 2 != 0 && b % 2 != 0)
		cout<<"the biggest even number is "<<c;

	if (a % 2 != 0 && b % 2 != 0 && c % 2 != 0)
		cout<<"All of the the numbers are uneven ";
	cout << ".\n";
	system("pause");
	return 0;
}
