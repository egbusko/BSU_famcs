
/*
//À1.0 Information about the dynamics of the day
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, b, c, d;
	cout << "Enter date: \n";
	cin >> a >>b >> c;
	if (b == 1 || b == 3 || b == 5 || b == 7 || b == 8 || b == 10) {
		d = 1;
	}
	else {
		if (b == 4 || b == 6 || b == 9 || b == 11) {
			d = 2;
		}
		else {
			if (b == 2) {
				d = 3;
			}
			else {
				d = 4;
			}
		}
	}
	switch (d) {
	case 1:
		if (a < 31) {
			a++;
		}
		else {
			a = 1;
			b++;
		}
		break;
	case 2:
		if (a < 30) {
			a++;
		}
		else {
			a = 1;
			b++;
		}
		break;
	case 3:
		if ((c % 4 == 0 && c % 100 != 0) || c % 400 == 0) {
			if (a < 29) {
				a++;
			}
			else {
				a = 1;
				b++;
			}
		}
		else {
			if (a < 28) 
			{
				a++;
			}
			else 
			{
				a = 1;
				b++;
			}
		}
		break;
	case 4:
		if (a < 31) 
		{
			a++;
		}
		else 
		{
			a = 1;
			b = 1;
			c++;
		}
	}
	cout << "Date of next day: " << a << "." << b << "." << c << "\n";
	system("pause");
	return(0);
}
*/

/*
//À2 GCD and LCM
#include <iostream>  
using namespace std;
int main()
{
	int a, x, y, b, nod, nok;
	cout << "Enter the first number ";
	cin >> x;
	cout << "Enter the second number ";
	cin >> y;
	a=x;
	b=y;
	while (a != b)
	{
		if (a < b)
			b = b - a;
		else
			a = a - b;
	}
	nod = a;
	nok = x * y / nod;
	cout << "nod=" << nod << "\n";
	cout << "nok=" << nok << "\n";
	system("pause");
	return 0;
}
*/

/*
//À3 Palindrome
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, b = 0, c = 0, aa;
	cout << "Enter the number ";
	cin >> a;
	aa = a;
	while (a > 0)
	{
		b = a % 10;
		c = c * 10 + b;
		a = a / 10;
	}
	if (c == aa)
		cout << "Is" << endl;
	else cout << "is not" << endl;
	system("pause");
	return 0;
}
*/

/*
//À4   Is it a prime number
#include <iostream>  
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, b, c;
	cin >> a;
	c = 0;
	for (b=2; b<a; b++)
	{
		if (a%b == 0)
		{
			c++;
			break;
		}
	}
	if (c == 0)
		cout << "Prime\n";
	else 
		cout << "Not Prime\n";
	system("pause");
	return 0;
}
*/

/*
//À5 Sum and number of digits
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, a1, r = 0, r1 = 0;
	cout << "enter number: \n";
	cin >> a;
	a1 = a;
//find the number of digits of a number
	while (a != 0) {
		a = a / 10;
		r++;
	}
//find the sum of the digits of a number
	while (a1 != 0) {
		r1 = r1 + a1 % 10;
		a1 = a1 / 10;
	}
	cout << "Sum " << r1 <<"\n";
	cout << "number of digits " << r <<"\n";
	system("pause");
	return(0);
}
*/

/*
//À6 Number of different digits
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, b, aa, p, k = 0;
	cout << "Enter the number ";
	cin >> a;
	for (b = 0; b <= 9; b++)
	{
		aa = a; p = 0;
		while (aa > 0 && p == 0)
			{
			if (aa % 10 == b)
				{
				k++; p = 1;
				}
			aa = aa / 10;
			}
	}
	cout << "Number of different digits " << k << "\n";
	system("pause");
	return 0;
}
*/	

/*
//À7 Largest digit of a number
#include <iostream>;
using namespace std;
int main()
{
	int a, ost, max = 0;
	cout << "enter number: \n";
	cin >> a;
	while (a != 0 && max != 9) {
		ost = a % 10;
		if (ost > max) {
			max = ost;
		}
		a = a / 10;
	}
	cout << max << "\n";
	system("pause");
	return(0);
}
*/

/*
//À8 prime divisors
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, i = 2, n;
	cout << "enter number: \n";
	cin >> a;
	cout << "prime divisors: ";
	while (i != a + 1) {
		if (a%i == 0) {
			n = 2;
			while (n != i && i%n != 0) {
				n++;
			}
			if (n == i) {
				cout << i << " ";
			}
		}
		i++;
	}
	system("pause");
	return(0);
}
*/

/*
//À9 Raises to a power
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int A, n, k, res=1;
	cout << "Enter the number ";
	cin >> A;
	cout << "Enter degree ";
	cin >>n;
	for (k = 1; k <= n; k++)
		res *= A;
	cout << "Raised number" << res << "\n";
	system("pause");
	return 0;
}
*/

/*
//À10 Number of combinations
#include <iostream>
using namespace std;
int main()
{
	int m, n, i, f, f1, f2, f3;
	double z;
	cout << "Enter m ";
	cin >> m;
	cout << "Enter n ";
	cin >> n;
	f = 1;
	for (int i = 1; i <= n; i++)
		{
		f *= i;
			if (i ==m)
		{
			f3 = f;
		}
			if (i == n)
			{
				f1 = f;
			}
			if (i == n - m)
			{
				f2 = f;
			}
		}
	z = f1 / (f3 * f2);
	cout << z<<"\n";
	system("pause");
	return 0;
}
*/

/*
//À11 perfect number
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, n = 1, r = 0;
	cout << "enter number: \n";
	cin >> a;
	while (n != a) {
		if (a%n == 0) {
			r = r + n;
		}
		n++;
	}
	if (r == a) {
		cout << "perfect\n";
	}
	else {
		cout << "not perfect\n";
	}
	system("pause");
	return(0);
}
*/

/*
//À12 Translation of the number system

#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, n, i = 0, st = 1, ost;
	cout << "Enter the number and calculation system \n";
	cin >> a;
	cin >> n;
	if (a != 0) {
		while (st < a) {
			st = st*n;
			i++;
		}
		if (st != a) {
			st = st / n;
				}
		else {
			i++;
		}
		cout << "Number " << a << " â " << n << "-th system of calculus is equal to";
		while (i != 0) {
			ost = a / st;
			cout << ost;
			a = a%st;
			i--;
			st = st / n;
		}
	}
	else {
		cout << "number " << a << " â " << n << "-th system of calculus is equal to 0";
	}
	cout << "\n";
	system("pause");
	return(0);
}
*/

/*
//À13 Nine between pairs of numbers
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, a1, ost, r = 0, st, i;
	cout << "enter number: \n";
	cin >> a;
	a1 = a;
	cout << "number:";
	while (a1 != 0) {
		a1 = a1 / 10;
		r++;
	}
	while (a != 0) {
		i = 1;
		st = 1;
		while (i != r) {
			st = st * 10;
			i++;
		}
		ost = a / st;
		if (r != 1) {
			cout << ost << "9";
		}
		else {
			cout << ost;
		}
		a = a % st;
		r--;
	}
	cout << "\n";
	system("pause");
	return(0);
}
*/

/*
//À14 Duplication of the largest number
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, max = 0, a1, a2, ost, n, r = 0, st, i;
	cout << "enter number: \n";
	cin >> a;
	a1 = a;
	a2 = a;
	cout << "number:";
	//find the largest digit of a number
	while (a != 0 && max != 9) {
		ost = a % 10;
		if (ost > max) {
			max = ost;
		}
		a = a / 10;
	}
	//find the number of digits in a number
	while (a1 != 0) {
		a1 = a1 / 10;
		r++;
	}
	while (r != 0) {
		i = 1;
		st = 1;
		//raise ten to the power equal to the number of the desired digit - 1
		while (i != r) {
			st = st * 10;
			i++;
		}
		//we get a number
		ost = a2 / st;
		//checking for compliance with the largest and displaying two if so
		if (ost == max) {
			cout << ost << ost;
		}
		else {
			cout << ost;
		}
		a2 = a2 % st;
		r--;
	}
	cout << "\n";
	system("pause");
	return(0);
}
*/

/*
//À15 Fibonacci sequence
#include <iostream>;
using namespace std;
int main()
{
	int f=0, s=1, a, n=1, r=1;
	cout << "enter number: \n";
	cin >> a;
	while (n != a) {
		r = f + s;
		f = s;
		s = r;
		n++;
	}
	cout << r<<"\n";
	system("pause");
	return(0);
}
*/

/*
//Â2 Number of repetitions
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, a1, n, i, ost, r = 0;
	cout << "enter number: \n";
	cin >> a;
	while (r != 10) {
		a1 = a;
		i = 0;
		while (a1 != 0) {
			ost = a1 % 10;
			if (ost == r) {
				i++;
			}
			a1 = a1 / 10;
		}
		cout << "digit " << r << " occurs in this number " << i << " times\n";
		r++;
	}
	system("pause");
	return(0);
}
*/

/*
//Â7 friendly numbers
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, n = 1, ar = 0, b, br = 0;
	cout << "enter 2 numbers: \n";
	cin >> a >> b;
	while (n != a) {
		if (a%n == 0) {
			ar = ar + n;
		}
		n++;
	}
	n = 1;
	while (n != b) {
		if (b%n == 0) {
			br = br + n;
		}
		n++;
	}
	if (ar == b && br == a) {
		cout << "friendly\n";
	}
	else {
		cout << "not friendly\n";
	}
	system("pause");
	return(0);
}
*/