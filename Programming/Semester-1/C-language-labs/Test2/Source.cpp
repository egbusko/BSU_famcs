#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"windows.h"
#include<stdio.h>
using namespace std;

struct equipment
{
	char title[20]; 
	int cost; 
	int year; 
	int expl; 
	double ost_cost; 
};


////////////////////////////////////////////////////////////////////////////////////////////
void sort(equipment *eq, int *a) 
{
	int N = *(a);
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N - i - 1; j++)
		{
			if ((eq[j].expl < eq[j + 1].expl))
			{
				equipment tmp = eq[j];
				eq[j] = eq[j + 1];
				eq[j + 1] = tmp;
			}
		}
	}
}

int f1(int *a, FILE *input)
{
	char str[100];
	(*a)++;
	fgets(str, 100, input);
	while (str != NULL)
	{
		if (fgetc(input) == EOF)
		{
			break;
		}
		fgets(str, 100, input);
		(*a)++;
	}
	return 0;
}


int f2(int *a, FILE *input, equipment *eq)
{
	if (!(input = fopen("input.txt", "r + t")))
	{
		cout << "файл не открыт" << endl;
		system("pause");
		return 0;
	}
	int b = (*a);
	int k = 0;
	while (k != b)
	{
		char str[100];
		fgets(str, 100, input);
		char *pum, *next_symbol;
		char tudum[] = { " .,-" };

		pum = strtok_s(str, tudum, &next_symbol);
		strcpy_s(eq[k].title, pum);

		pum = strtok_s(NULL, tudum, &next_symbol);
		eq[k].cost = atoi(pum);

		pum = strtok_s(NULL, tudum, &next_symbol);
		eq[k].year = atoi(pum);

		eq[k].expl = (2018 - eq[k].year);

		eq[k].ost_cost = eq[k].cost - ((double)eq[k].cost * (0.05*eq[k].expl));

		k++;
	}
	return 0;
}
//////////////////////////////////////////////////////////////////////////////////////////////////


int main()
{
	setlocale(LC_ALL, "RUSSIAN");

	FILE *input = fopen("input.txt", "r");
	int num = 0, *a = &num;
	f1(a, input);
	equipment *eq = new equipment[num];
	f2(a, input, eq);
	

	for (int i = 0; i < num; i++)
	{
		printf_s("\nназвание: ");
		printf_s("%s", eq[i].title);
		printf_s("\nначальная стоимость: ");
		printf_s("%d", eq[i].cost);
		printf_s("\nгод ввода в эксплуатацию: ");
		printf_s("%d", eq[i].year);
		printf_s("\nсрок эксплуатации: ");
		printf_s("%d\n", eq[i].expl);
		printf_s("\n\n");
	}

	// Ex2 ////////////////////////////////////////////////////////////////////////////////////

	char max_title[100];
	int max_year;
	int max_cost = eq[0].cost;
	for (int i = 0; i < num; i++)
	{
		if (eq[i].cost > max_cost)
		{
			max_cost = eq[i].cost;
			strcpy(max_title, eq[i].title);
			max_year = eq[i].year;
		}
	}
	cout << "Больше всего стоит " << max_title << " " << max_cost << " " << max_year << endl << endl;

	//Ex3 ////////////////////////////////////////////////////////////////////////////////////

	



	//Ex4 ////////////////////////////////////////////////////////////////////////////////////

	sort(eq, a);
	cout << "отсортированный массив структур: " << endl;
	for (int i = 0; i < num; i++)
	{
		printf_s("\nНазвание: ");
		printf_s("%s", eq[i].title);
		printf_s("\nСрок эксплуатации: ");
		printf_s("%d", eq[i].expl);
		printf_s("\n\n");
	}


	//Ex5////////////////////////////////////////////////////////////////////////////////////

	FILE *output1;
	if (!(output1 = fopen("result1.txt", "w")))
	{
		cout << "файл result1.txt не открыт" << endl;
	}
	FILE *output2;
	if (!(output2 = fopen("result2.txt", "w")))
	{
		cout << "файл result2.txt не открыт" << endl;
	}

	for (int i = 0; i < num; i++)
	{
		fprintf(output1, "%d\t", i + 1);
		fprintf(output1, "%s\t", eq[i].title);
		fprintf(output1, " %d\t", eq[i].expl);
		fprintf(output1, "%d\t\n", eq[i].cost);
	}


	//Ex6////////////////////////////////////////////////////////////////////////////////////
	double **A = new double*[num];
	for (int i = 0; i < num; i++)
	{
		A[i] = new double[4];
	}
	for (int i = 0; i < num; i++)
	{
		A[i][0] = i + 1;
		A[i][1] = eq[i].expl;
		A[i][2] = eq[i].cost;
		A[i][3] = eq[i].ost_cost;
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%g\t", A[i][j]);
			fprintf(output2, "%g\t", A[i][j]);
		}
		printf("\n");
		fprintf(output2, "\n");
	}
	fprintf(output2, "\n\n");



	//Ex7 ////////////////////////////////////////////////////////////////////////////////////
	double sr_ost_cost = 0;
	for (int i = 0; i < num; i++)
	{
		sr_ost_cost += (double)eq[i].ost_cost;
	}
	sr_ost_cost = sr_ost_cost / num;
	printf("Средняя остаточная стоимость = %g\n", sr_ost_cost);


	//Ex8 ////////////////////////////////////////////////////////////////////////////////////

	int *mas = new int[num];
	for (int i = 0; i < num; i++)
	{
		mas[i] = eq[i].expl;
	}
	int sum = 0;
	int ost = 0;
	_asm
	{
		mov esi, mas
		mov ebx, num
		mov eax, 0
		summa: add eax, [esi]
			   add esi, 4
			   dec ebx
			   jnz summa
			   mov sum, eax
			   mov ecx, num
			   mov edx, 0
			   div  ecx;
		mov ost, edx
			mov sum, eax
	}
	double ostatok = (double)ost / num;
	double sr_srok = ostatok + sum;
	printf("Средний срок эксплуатации оборудования: = %g\n\n", sr_srok);


	//Ex9 ////////////////////////////////////////////////////////////////////////////////////
	for (int i = 0; i < num; i++)
	{
		for (int l = 0; l < num - i; l++)
		{
			if (A[i][3] > A[i + l][3])
			{
				double *temp = A[i];
				A[i] = A[i + l];
				A[i + l] = temp;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			fprintf(output2, "%g\t", A[i][j]);
		}
		fprintf(output2, "\n");
	}
	for (int i = 0; i < num; i++)
		delete[] A[i];

	fprintf(output2, "\nСредняя остаточная стоимость = %g ", sr_ost_cost);
	fprintf(output2, "\nСредний срок эксплуатации = %3f ", sr_srok);

	fclose(input);
	fclose(output1);
	fclose(output2);
	system("pause");
	return 0;
}
