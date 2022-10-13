//#include <iostream>	
//using namespace std;
//int main()
//{
//	setlocale(LC_ALL, ".1251");
//	const int n = 3;
//	const int m = 4;
//	int i = 0 , j=0, a = 0, b = 0, c = 0 , s = 0, d=1,k=0;
//	int **mas = new int*[n];
//	for (int i = 0; i < n; i++)
//		mas[i] = new int[n];
//
//	for (i = 0; i < n; i++)
//		for (j = 0; j < n; j++)
//			cin >> mas[i][j];
//		cout << endl;
//
//		//Поиск наим по модулю
//		a = abs(mas[0][0]);
//		for (i = 0; i < n; i++)
//		{
//			for (j = 0; j < n; j++)
//			{
//				if (abs(mas[i][j]) < a)
//				{
//					a = abs(mas[i][j]);
//					d = mas[i][j];
//				}
//			}
//		}
//		
//	for (i = 0;i<n;i++)
//	{
//		for (j = 0;j<n;j++)
//		{
//			if (mas[i][j] == 0)
//			{
//				k++;
//			}
//			if (k != 0)
//				s += mas[i][j];
//		}
//	}
//	cout << "Наименьший по модулю элемент = " << d<<endl;
//	
//	if (d == 0)
//		cout << "Сумма элементов после 0 - " << s << endl;
//	else
//		cout << "Ноль не найден"<<endl;
//	for (int i = 0; i < n; i++)
//		delete[] mas[i];
//	delete[] mas;
//	system("pause");
//	return 0;
//}




#include <iostream>	
using namespace std;
int main()
{
	int n;
	cin >> n;
	int i, j, a, b, c, s = 0, f;

	/*int **mas2 = new int*[n];
	for (i = 0; i < n; i++)
		mas2[i] = new int[n];*/

	int **mas = new int*[n];
	for (i = 0; i < n; i++)
		mas[i] = new int[n];

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> mas[i][j];
	cout << endl;
	
	/*{
		for (i = 0; i < n / 2; i++)
			for (j = 0; j < n / 2; j++)
				mas2[i + n / 2][j + n / 2] = mas[i][j];

		for (i = n / 2; i < n; i++)
			for (j = n / 2; j < n; j++)
				mas2[i - n / 2][j - n / 2] = mas[i][j];

		for (i = 0; i < n / 2; i++)
			for (j = n / 2; j < n; j++)
				mas2[i + n / 2][j - n / 2] = mas[i][j];

		for (i = n / 2; i < n; i++)
			for (j = 0; j < n / 2; j++)
				mas2[i - n / 2][j + n / 2] = mas[i][j];
	}*/
	
	{
	for (i = 0; i < n / 2; i++)
		for (j = 0; j < n / 2; j++)
		{
			f = mas[i + n / 2][j + n / 2];
			mas[i + n / 2][j + n / 2] = mas[i][j];
			mas[i][j] = f;
		}
	for (i = 0; i < n / 2; i++)
		for (j = n / 2; j < n; j++)
		{
			f = mas[j][i];
			mas[j][i] = mas[i][j];
			mas[i][j] = f;
		}
	}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
	for (int i = 0; i < n; i++)
		delete[] mas[i];
	delete[] mas;
	/*for (int i = 0; i < n; i++)
		delete[] mas2[i];
	delete[] mas2;*/
	system("pause");
	return 0;
}



//Что-то еще

//#include <iostream>	
//using namespace std;
//int creation(double *mas)
//{
//	int n;
//	cout << "Введите n ";
//	cin >> n;
//	double *mas = new double[n];
//	for (int i = 0; i < n; i++)
//	{
//		mas[i] = rand() % 100 * pow(-1.0, i);
//	}
//	return n;
//}
//int nmin(double *mas, int n)
//{
//	int i, a = 0;
//	double min = abs(mas[i]);
//}
//
//
//int* get2and4(int number)
//{
//	int* out = new int[2];
//	out[0] = 2;
//	out[1] = 5;
//	return out;
//}
//
//void ex1(int len, int in_arr[])
//{
//	int* res = new int [len * 2];
//	int pos = 0;
//	int* t;
//	for (int i = 0; i < len; i++)
//	{
//		t = get2and4(in_arr[i]);
//		res[pos++] = t[0];
//		res[pos++] = t[1];
//	}
//	return;
//}
//
//int main()
//{
//	int in[] = { 12345,42434,53453, 34534, 76745, 76855 };
//	ex1(6, in);
//	return 0;
//}
//
//
//
//if (<s)
//{
//	if (< c)
//	{
//
//
//	}
//
//}
