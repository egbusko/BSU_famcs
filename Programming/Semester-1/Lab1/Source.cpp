// A1,12 ���������

/*
//�1.0 ����������� ���� ���������� ���
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, b, c, d;
	cout << "������� ����: \n";
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
	cout << "���� ���������� ���: " << a << "." << b << "." << c << "\n";
	system("pause");
	return(0);
}
*/

/*
//�2 ��� � ���
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
//�3 ���������
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, b = 0, c = 0, aa;
	cout << "������� ����� ";
	cin >> a;
	aa = a;
	while (a > 0)
	{
		b = a % 10;
		c = c * 10 + b;
		a = a / 10;
	}
	if (c == aa)
		cout << "��������" << endl;
	else cout << "���" << endl;
	system("pause");
	return 0;
}
*/

/*
//�4   ������� �� �����
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
		cout << "�������\n";
	else 
		cout << "���\n";
	system("pause");
	return 0;
}
*/

/*
//�5 ����� � ���������� ����
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, a1, r = 0, r1 = 0;
	cout << "enter number: \n";
	cin >> a;
	a1 = a;
//������ r��������� ���� �����
	while (a != 0) {
		a = a / 10;
		r++;
	}
//������ ����� ���� �����
	while (a1 != 0) {
		r1 = r1 + a1 % 10;
		a1 = a1 / 10;
	}
	cout << "����� " << r1 <<"\n";
	cout << "����� ���� " << r <<"\n";
	system("pause");
	return(0);
}
*/

/*
//�6 ���-�� ��������� ����
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, b, aa, p, k = 0;
	cout << "������� ����� ";
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
	cout << "���������� ������ ���� " << k << "\n";
	system("pause");
	return 0;
}
*/	

/*
//�7 ���������� ����� �����
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
//�8 ������� �������� 
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, i = 2, n;
	cout << "enter number: \n";
	cin >> a;
	cout << "������� ��������: ";
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
//�9 �������� � �������
#include <iostream>
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int A, n, k, res=1;
	cout << "������� ����� ";
	cin >> A;
	cout << "������� ������� ";
	cin >>n;
	for (k = 1; k <= n; k++)
		res *= A;
	cout << "����������� �����" << res << "\n";
	system("pause");
	return 0;
}
*/

/*
//�10 ����� ���������
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
//�11 ����������� �����
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
		cout << "�����������\n";
	}
	else {
		cout << "�������������\n";
	}
	system("pause");
	return(0);
}
*/

/*
//�12 ������� ������� ���������

#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, n, i = 0, st = 1, ost;
	cout << "������� ����� � ������� ��������� \n";
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
		cout << "����� " << a << " � " << n << "-�� ������� ��������� ����� ";
		while (i != 0) {
			ost = a / st;
			cout << ost;
			a = a%st;
			i--;
			st = st / n;
		}
	}
	else {
		cout << "����� " << a << " � " << n << "-�� ������� ��������� ����� 0";
	}
	cout << "\n";
	system("pause");
	return(0);
}
*/

/*
//�13 ������ ����� ������ �����
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, a1, ost, r = 0, st, i;
	cout << "enter number: \n";
	cin >> a;
	a1 = a;
	cout << "�����:";
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
//�14 ������������ ����������� �����
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
	cout << "�����:";
	//������� ���������� ����� �����
	while (a != 0 && max != 9) {
		ost = a % 10;
		if (ost > max) {
			max = ost;
		}
		a = a / 10;
	}
	//������� ���������� ���� � �����
	while (a1 != 0) {
		a1 = a1 / 10;
		r++;
	}
	while (r != 0) {
		i = 1;
		st = 1;
		//�������� ������ � ������� ������ ������ ������ ����� - 1
		while (i != r) {
			st = st * 10;
			i++;
		}
		//�������� �����
		ost = a2 / st;
		//��������� �� ����������� ���������� � ������� ��� ���� ��� � ����
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
//�15 ������������������ ���������
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
//�2 ���������� ����������
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
		cout << "����� " << r << " ����������� � ���� ����� " << i << " ���\n";
		r++;
	}
	system("pause");
	return(0);
}
*/

/*
//�7 ������������� �����
#include <iostream>;
using namespace std;
int main()
{
	setlocale(LC_ALL, ".1251");
	int a, n = 1, ar = 0, b, br = 0;
	cout << "������� 2 �����: \n";
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
		cout << "�������������\n";
	}
	else {
		cout << "���������������\n";
	}
	system("pause");
	return(0);
}
*/