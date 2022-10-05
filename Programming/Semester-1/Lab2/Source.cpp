//C2(1) НЕ мой вариант
/*
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double MYarctg(double, double);
//прототип функции
int main()
{
	double x, eps = 1;
	int k, i;
	setlocale(LC_ALL, ".1251");
	cout << "Введите значение x, |x|<1:\n";
	cin >> x;
	cout << "Введите k:\n";
	cin >> k;
	for (i = 1; i <= k; i++)
		eps = eps / 10;
	cout << "Значение арктангенса, вычесленное с помощью ряда Тейлора с точностью" << eps << ":";
	cout << setprecision(3) << setw(8) << MYarctg(x, eps);
	//setprecision(0)-восстанавливает первоначальный формат - 6 символов...
	cout << endl << "Значение арктангенса, вычисленное с помощью atan(x):" << setw(8) << atan(x) << endl;
	system("pause");
	return 0;
}
double MYarcrg(double x, double eps)
{
	long n = 1;
	double sum = 0, next, prev;
	prev = 0;
	next = x;
	do
	{
		sum = sum + next;
		n = n + 2;
		prev = next;
		n = (-1)*prev*(n - 2)*x*x / n;
	} while (abs(prev) >= eps);
	return sum;
}
*/

//C2(1) Мой вариант

//#include <iostream>
//#include <iomanip>
//#include <cmath>
//#include <stdio.h>
//using namespace std;
//double MYfunc(double x, double eps)
//
//{
//	int n = 1, t = 0;
//	double sum = 0, prev = 1, next = 1;
//	while (abs(prev) >= eps)
//	{
//		sum += next;
//		prev = next;
//		next = (prev * (-1)*x *(t + 1)) / (2 * n);
//		n++;
//		t++;
//	}
//	return sum;
//}
//int main()
//{
//	int x, k;
//	double eps;
//	cin >> x >> k;
//	cout << 1 / sqrt(1 + x) << endl;
//	eps = pow(10, k*(-1));
//	cout << MYfunc(x, eps) << endl;
//	/* scanf_s("%lf", &x);
//	scanf_s("%d", k);
//	eps=pow(10, k*(-1);
//	printf("%lf", MYfunc(x,eps));
//	printf("%lf", sqrt(1+x)); */
//	system("pause");
//	return 0;
//}

//B2
#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;
double func(double a, double b, double h, int m)
{
	double sum = 0;
	while (a <= b)
	{
		double k;
		for (int n = 1; n <= m; n++)
		{
			k =2* n * a;
			sum += pow(a, 2 * n + 1)*cos(k) / (2 * n + 2);

		}
		cout << " |" << setw(23) << right << fixed << setprecision(5) << "X = " << a << " |" << setw(25) << setprecision(5) << "Sum = " << sum << " |" << setw(25) << "Sin(x) = " << sin(k) << " |" << endl;
		cout << " —---------------------------------------------------------------------------------------------------\n";
		a += h;
	}
	return 0;
}
int main()
{
	double a, b, h;
	int m;
	cout << "Enter a, b, h, m:" << endl;
	cin >> a >> b >> h >> m;
		func(a, b, h, m);
	system("pause");
	return 0;
}


//#include <iostream>
//#include <iomanip>
//#include <cmath>
//using namespace std;
//double func(double a, double b, double h, int m)
//{
//	double sum = 0;
//	while (a <= b)
//	{
//		double k;
//		for (int n = 1; n <= m; n++)
//		{
//			k =2* n * a;
//			sum += pow(a, 2 * n + 1)*cos(k) / (2 * n + 2);
//
//		}
//		printf("%-0s", " |");
//		printf("%%", setw(23));
//		printf("%p", right);
//		printf("%p", fixed);
//		printf("%p", setprecision(5));
//		printf("%-0s", "X = ");
//		printf("%lf", a);
//		printf("%-0s", " |");
//		printf("%%", setw(25));
//		printf("%p", setprecision(5));
//		printf("%-0s", "Sum = ");
//		printf("%lf", sum);
//		printf("%-0s", " |");
//		printf("%%", setw(25));
//		printf("%-0s", "Sin(x) = ");
//		printf("%lf", sin(k));
//		printf("%-0s", " |");
//		printf("%-0s", "\n");
//		printf("%-0s", " —---------------------------------------------------------------------------------------------------");
//		printf("%-0s", "\n");
//		a += h;
//	}
//	return 0;
//}
//int main()
//{
//	double a, b, h;
//	int m;
//	printf("%-0s", "Enter a: ");
//	printf("%-0s", "\n");
//	scanf_s("%lf", &a);
//	printf("%-0s", "Enter b: ");
//	printf("%-0s", "\n");
//	scanf_s("%lf", &b);
//	printf("%-0s", "Enter h: ");
//	printf("%-0s", "\n");
//	scanf_s("%lf", &h);
//	printf("%-0s", "Enter m: ");
//	printf("%-0s", "\n");
//	scanf_s("%d", &m);
//	func(a, b, h, m);
//	system("pause");
//	return 0;
//}




//
//B5, C++
//#include <iostream>
//#include <iomanip>
//#include <cmath>
//using namespace std;
//double Myfunc(int m, double x);
//int main()
//{
//	int m, n = 5;
//	double a, b, h, x, sum = 0;
//	setlocale(LC_ALL, ".1251");
//	/*cout << "Введите значение x, |x|<1: \n";
//	cin >> x;*/
//	cout << "Введите m: \n";
//	cin >> m;
//
//	cin >> a >> b >> h;
//	cout << " --------------------------------------------\n";
//	cout << " | Значение переменной X |      Сумма       |\n";
//	cout << " --------------------------------------------\n";
//	if (a <= b)
//	{
//		for (x = a; x <= b; x += h)
//		{
//			cout << " |" << setw(23) << right << fixed << setprecision(5) << x << "|" << setw(18) << Myfunc(m, x) << "|" << "\n";
//
//			cout << " --------------------------------------------\n";
//		}
//	}
//	else if (a > b)
//	{
//		for (x = a; x >= b; x -= h)
//		{
//			cout << " |" << setw(23) << right << fixed << setprecision(5) << x << "|" << setw(18) << Myfunc(m, x) << "|" << "\n";
//
//			cout << " --------------------------------------------\n";
//		}
//	}
//	cout << setprecision(3) << setw(8) << Myfunc(m, x);
//	system("pause");
//	return 0;
//}
//
//double Myfunc(int m, double x)
//{
//	double sum = 0;
//	int n;
//	for (n = 5; n <= m; n++)
//		sum = sum + pow(x, (2 * n + 1)) *sin(n*x) / (2 * n + 1);
//	return sum;
//}

//
//B5, C
//#include <iostream>
//#include <iomanip>
//#include <cmath>
//using namespace std;
//double Myfunc(int m, double x);
//int main()
//{
//	int m, n = 5;
//	double a, b, h, x, sum = 0;
//	setlocale(LC_ALL, ".1251");
//	printf("Введите m: \n");
//	scanf_s("%d", &m);
//	scanf_s("%lf", &a);
//	scanf_s("%lf", &b);
//	scanf_s("%lf", &h);
//	/*while ((h <= 0) || (h > abs(a - b)));*/
//	printf(" --------------------------------------------\n");
//	printf(" | Значение переменной X |      Сумма       |\n");
//	printf(" --------------------------------------------\n");
//	if (a <= b)
//	{
//		for (x = a; x <= b; x += h)
//		{
//			printf("| %23lf | %16lf| \n", x, Myfunc(m, x));
//			printf(" --------------------------------------------\n");
//		}
//	}
//	else if (a > b)
//	{
//		for (x = a; x >= b; x -= h)
//		{
//			printf(" | %23lf | %16lf| \n", x, Myfunc(m, x));
//			printf(" --------------------------------------------\n");
//		}
//	}
//	printf("% 8.3 lf", Myfunc(m, x));
//	system("pause");
//	return 0;
//}
//
//
//double Myfunc(int m, double x)
//{
//	double sum = 0;
//	int n;
//	for (n = 5; n <= m; n++)
//		sum = sum + pow(x, (2 * n + 1)) *sin(n*x) / (2 * n + 1);
//	return sum;
//	
//}