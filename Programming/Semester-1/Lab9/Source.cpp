#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string.h>
using namespace std;

struct chelovek
{
	char name[100];
	char surname[100];
	char patron[100];
	int number;
	char book[100];
	char data[10];
};
chelovek chel[100];


void main()
{
	setlocale(0, "ru");
	int f;
	cout << " 1) Ввод массива структур (на выбор – с файла или консоли) \n ";
	cout << "2) Сортировка массива структур \n ";
	cout << "3) Поиск в массиве структур по заданному параметру(по значению одного любого из полей) \n ";
	cout << "4) Изменение заданной структуры \n ";
	cout << "5) Удаление структуры из массива(по номеру и по значению одного любого из полей) \n ";
	cout << "6) Вывод на экран и в файл массива структур\n ";
	cout << "7) Выход.\n";
	cin >> f;




	int n = 6;

	ofstream fileo("output.txt");
	ifstream filein("input.txt");
	if (f == 1)
	{
		for (int i = 0; i < 6; i++)
		{
			filein >> chel[i].name;
			filein >> chel[i].surname;

			filein >> chel[i].patron;
			filein >> chel[i].number;
			filein >> chel[i].book;
			filein >> chel[i].data;
		}
		cout << " Array was defined. Next point? :";
		cin >> f;
	}

	double tmpd;
	char *tmpc;

	if (f == 2)
	{
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n - 1; j++)
			{
				if (arr[j].square > arr[j + 1].square)
				{
					tmpd = arr[j + 1].square;
					arr[j + 1].square = arr[j].square;
					arr[j].square = tmpd;

					tmpd = arr[j + 1].population;
					arr[j + 1].population = arr[j].population;
					arr[j].population = tmpd;
				}
			}
		}cout << " next point? :";
		cin >> f;
	}
	cout << endl;

	/*for (int i = 0; i < n; i++)
	{
		cout << arr[i].name << " " << arr[i].capital << " " << arr[i].square << " " << arr[i].population << " " << endl;
	}*/
	double t;
	int a;
	if (f == 3)
	{
		cout << "\n Enter square: ";
		cin >> t;
		for (int i = 0; i < n; i++)
		{
			if (arr[i].square == t)
			{
				a = i;
				break;
			}
		}
		cout << arr[a].name << " " << arr[a].capital << " " << arr[a].square << " " << arr[a].population << " " << endl; // poisk
		cout << " next point? :";
		cin >> f;
	}
	double inc;
	if (f == 4)
	{
		cout << " \n How many people appeared this year in Russia?: ";	//изменение

		cin >> inc;
		arr[1].population = arr[1].population + inc;
		cout << endl << arr[1].population << endl;
		cout << " next point? :";
		cin >> f;
	}
	int k;
	if (f == 5)
	{
		cout << " Which country you'd delete? :";
		cin >> k;// udalenie po nomery
		for (int i = k; i < n - 1; i++)
		{
			strcpy(arr[i].name, arr[i + 1].name);
			strcpy(arr[i].capital, arr[i + 1].capital);
			arr[i].square = arr[i + 1].square;
			arr[i].population = arr[i + 1].population;
		}
		cout << " next point? :";
		cin >> f;

	}
	if (f == 6)
	{
		for (int i = 0; i < n - 1; i++)
		{
			fileo << arr[i].name;
			fileo << " ";
			fileo << arr[i].capital;
			fileo << " ";
			fileo << arr[i].square;
			fileo << " ";
			fileo << arr[i].population;
			fileo << "\n\n";

			for (int i = 0; i < n; i++)
			{
				cout << arr[i].name << " " << arr[i].capital << " " << arr[i].square << " " << arr[i].population << " " << endl;
			}
		}// vivod
		cout << " next point? :";
		cin >> f;
	}
	if (f == 7)
	{
		exit(0);
	}
	fileo.close();
	filein.close();


	system("pause");
}