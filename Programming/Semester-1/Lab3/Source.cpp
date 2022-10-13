//#include "stdafx.h"
#include <iostream>
using namespace std;

//функция, сливающая массивы
void Merge(int *A, int first, int last)
{
	int middle, start, final, j;
	int *mas = new int[100];
	middle = (first + last) / 2;							//вычисление среднего элемента
	start = first;											//начало левой части
	final = middle + 1;										//начало правой части
	for (j = first; j <= last; j++)							//выполнять от начала до конца
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}
	
	for (j = first; j <= last; j++) 
		A[j] = mas[j];
	delete[]mas;
};


//рекурсивная процедура сортировки
void MergeSort(int *A, int first, int last)
{
	if (first < last)
	{
			MergeSort(A, first, (first + last) / 2);		//сортировка левой части
			MergeSort(A, (first + last) / 2 + 1, last);		//сортировка правой части
			Merge(A, first, last);							//слияние двух частей
	}
};




void Achast()
{
	setlocale(LC_ALL, "Rus");
	int i, n;
	int *A = new int[100];
	cout << "Размер массива > "; cin >> n;
	for (i = 1; i <= n; i++)
	{
		cout << i << " элемент > "; cin >> A[i];
	}
	MergeSort(A, 1, n);										//вызов сортирующей процедуры
	cout << "Упорядоченный массив: ";						
	for (i = 1; i <= n; i++) 
		cout << A[i] << " ";
	delete[]A;
	cout << endl << endl;
	system("pause>>void");
	system("cls");
}





void Bchast()
{
	const int n=10;
	int a[n] /*= {4,6,8,9,4,3,5,6,5,7}*/, b;
	int V = 0, Y = 0;
	cout << "Enter mas:"<<endl;
	for (int i = 0; i < n; i++)
		cin >> a[i];


	//Мы складываем все элементы не находящиеся
	//на "переломах" возрастания-убывания массива
	for (int i = 1; i < n - 1; i++)
	{
		if ((a[i - 1] < a[i]) && (a[i] < a[i + 1]))
			V += a[i];
		if ((a[i - 1] > a[i]) && (a[i] > a[i + 1]))
			Y += a[i];
	}
	if (a[0] < a[1])
		V += a[0];
	if (a[0] > a[1])
		Y += a[0];
	if (a[n-2] < a[n-1])
		V += a[n-1];
	if (a[n-2] > a[n-1])
		Y += a[n-1];
	cout <<endl<< "Summa vozrastaushchih: "<<V << endl;
	cout<< "Summa ubuvaushchih: "<< Y<<endl;
	cout << "Raznost= " << V-Y << endl;
}

int main()
{
	//Achast();
	Bchast();
	system("pause");
	return 0;
}
