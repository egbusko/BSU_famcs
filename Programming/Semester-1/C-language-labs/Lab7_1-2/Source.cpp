//C7 ex.1-2
#include <iostream>	
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct chelovek
{
	int kurs;
	char name[100];
	char surname[100];
	char patron[100];
	int ocenki[3];
	int mat_polozenie;
	int stipendiya;
};


void change_positions(chelovek *a1, chelovek* a2)
{
	chelovek t;
	t =*a1;
	*a1 = *a2;
	*a2 = t;
}


int opredelenie_stipendii(int mat_polozenie,int srball)
{
	int stipendiya;
	if (mat_polozenie == 0)
	{
		if (srball < 4)
			stipendiya = 0;
		if ((4 <= srball) && (srball < 6))
		{
			stipendiya = 85;
		}
		if ((6 <= srball) && (srball < 8))
		{
			stipendiya = 105;
		}
		if ((8 <= srball) && (srball <=10))
		{
			stipendiya = 135;
		}
	}
	if (mat_polozenie == 1)
	{
		if (srball < 4)
			stipendiya = 0;
		if ((4 <= srball) && (srball < 6))
		{
			stipendiya = 75;
		}
		if ((6 <= srball) && (srball < 8))
		{
			stipendiya = 95;
		}
		if ((8 <= srball) && (srball <= 10))
		{
			stipendiya = 125;
		}
	}
	if (mat_polozenie == 2)
	{
		if (srball < 4)
			stipendiya = 0;
		if ((4 <= srball) && (srball < 6))
		{
			stipendiya = 65;
		}
		if ((6 <= srball) && (srball < 8))
		{
			stipendiya = 85;
		}
		if ((8 <= srball) && (srball <= 10))
		{
			stipendiya = 115;
		}
	}
	return stipendiya;
}


int Ex1()
{
	 int n; 
	cout << "Kolichestvo uchenikov vvedite:" << endl;
	cin >> n;
	system("cls");
	chelovek *chel;

	n = 4;
	chelovek chel_stat[] = {
		{ 2, "Artem", "Zaiac", "Vladimirovich", { 6,7,8 }, 2 },
		{ 1, "Roman", "Volk", "Ivanovich", { 9,8,5 }, 1 },
		{ 2, "Egor", "Busko", "Andreevich", { 7,8,4 }, 0 },
		{ 0, "Lesha", "Petrov", "Dmitrievich", { 5,3,9 }, 1 }
	};
	chel = chel_stat;
	

/*	chel = new chelovek[n];
for (int i = 0; i < n; i++)
	{
		cout << "Vvedite kurs:" << endl;
		cin >> chel[i].kurs;
		cout << "Vvedite name:" << endl;
		cin >> chel[i].name;
		cout << "Vvedite surname:" << endl;
		cin >> chel[i].surname;
		cout << "Vvedite patron:" << endl;
		cin >> chel[i].patron;
		for (int j = 0; j < 3; j++)
		{
			cout << "Vvedite ocenki "<<i+1 <<" uchenika:"<< endl;
			cin >> chel[i].ocenki[j];
		}
		cout << "Vvedite sostoyanie:" << endl;
		cin >> chel[i].mat_polozenie;
		system("cls");
	}
	system("cls");
	*/



	//Считаем средний балл
	int *srball = new int[n];
	for (int i = 0; i < n; i++)
	{
		srball[i] = (chel[i].ocenki[0] + chel[i].ocenki[1] + chel[i].ocenki[2]) / 3;
	}
	


	//Присваиваем стипендию
	for (int i = 0; i < n; i++)
	{
		chel[i].stipendiya = opredelenie_stipendii(chel[i].mat_polozenie, srball[i]);
	}
	


	//Сортируем по курсам
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
		{
			if (chel[j].kurs > chel[j + 1].kurs || 
				(chel[j].kurs == chel[j + 1].kurs && chel[j].stipendiya > chel[j + 1].stipendiya))
								
				change_positions(&(chel[j]), &(chel[j + 1]));
		}
	}
	system("pause");
		system("cls");
	return 0;
}



int Ex2()
{
	int n, m;
	printf("Enter starting position: \t");
	cin >> m;
	printf("Enter how much symbols: \t");
	cin >> n;
	char *str = new char[1000];
	char *temp = new char[n];

	FILE *file;
	FILE *input;
	fopen_s(&input, "output.txt", "w+");
	fopen_s(&file, "newfile.txt", "r+");

	if (!file)
	{
		printf("Error\t");
		exit(0);
	}
	else
	{
		while (fgets(str, strle n(str), file))
		{
			fprintf(stdout, "%s", str);
		}
	}

	int count = 0;
	for (int i = m; i < m + n; i++)
	{
		temp[count] = str[i];
		count++;
	}
	cout << endl << str << endl << temp;
	fputs(temp, input);


	fclose(file);
	fclose(input);
	system("pause");
	system("cls");
	return 0;
}



//////////////////////////////////////////////////////////
int main()
{
	//Ex1();
	Ex2();
}