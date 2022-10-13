#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>	
#include <cmath>
#include<stdlib.h> 
#include<string.h>
using namespace std;

int A1chast()
{
	const int n = 500; 
	char *s[n] = {}; 
	char strok[n] = { "privetp drug poka drug poel\n" };
	printf("Vvedite neskolko slov:\n");
	//fgets(strok, n, stdin);
	char d[] = " ,";
	char *m = NULL; int i = 0, k=0;


	//Функция fgets, при вводе закидывает вконец строки - \n,
	//его нужно заменить на конец строки - \0
	if (strok[strlen(strok) - 1] == '\n')
		strok[strlen(strok) - 1] = '\0';
	

	//Закидываем по слову в массив
	m = strtok(strok, d);
	while (m != NULL)
	{
		s[i] = m;
		i++;
		m = strtok(NULL, d);	
	}


	//Проверка первого и последнего символов слова
	for (int j = 0; j < i; j++)
	{
		if (s[j][0] == s[j][strlen(s[j])-1])
		{
			cout << s[j] << endl;
		}
	}

	system("pause");
	system("cls");
	return 0;
}

int A2chast()
{
	const int n = 1000; int len, k,a;
	int counts[256] = {};
	char strok[n];	
	printf("Vvedite text:\n");
	fgets(strok, n, stdin);			//cin.getline(strok, n);
	
	len = strlen(strok);
	for (int i = 0; i < len; i++)
	{
		counts[strok[i]]++;
	}


	//Поиск наибольшего
	k = counts[0];
	for (int j = 0; j < 256; j++)
	{
		if (counts[j] > k)
		{
			k = counts[j];
			a = j;
		}
	}


	char s = a;
	printf("%c\n", s);
	system("pause");
	system("cls");
	return 0;
}





int	sumir(char *s,int a, int k)
{
	int t=0;
	for (int i = k; i < a; i += 2)
	{
		t += s[i] - 48;
	}
	return t;
}
int Bchast()
{
	int sum1 = 0, a, b, c;
	char s[14];
	printf("Vvedite cod:\n");
	fgets(s, 14, stdin);			//cin.getline(s, 14);
	char *str = s;
	a = strlen(str);

	if (a != 13)
	{
		printf("Neverny razmer!\n");
		system("pause");
		return 0;
	}


//Проверка на присутствие символов
	for (int i = 0; i < a; i++)
	{
		if ((s[i] >= 48) && (s[i] <= 57))
		{}
		else
		{
			printf("V stroke est simvoly, oshibka\n");
			system("pause");
			return 0;
		}
	}


	b = sumir(s, a, 0) % 10;
	c = (sumir(s, a, 1) * 3) % 10;
	if ((b + c) % 10 == 0)
		printf("Cod veren\n");
	else
		printf("Summa NE kratna 10.\n");
	system("pause");
	return 0;
}

int main()
{
	//A1chast();
	//A2chast();
	Bchast();
}
