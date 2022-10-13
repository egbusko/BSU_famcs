#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <cstdlib>
using namespace std;

struct student 
{
	char *surname = new char[500];
	int group;
	int zachnum;
	double MA;
	double GA;
	double PROG;
	double avg;

};
student st[100];


void main()
{
	FILE *oFile = fopen("sortedOutput.txt", "w");
	int n = 0;
	FILE *iFile = fopen("data.txt", "r");
	FILE *neud = fopen("neud.txt", "w");
	FILE *otlichnik = fopen("otlichnik.txt", "w");
	char *a = new char[500];
	int i = 0, count = 0, str = 0;
	
	if (iFile == NULL) 
	{
		printf("Error!");
	}

	else 
	{
		while (fgets(a, 500, iFile) != NULL) 
		{

			char * pointer;
			pointer = strtok(a, " ");

			while (pointer != NULL)
			{
				count++;

				if (i == 0) 
				{
					strcpy(st[str].surname, pointer);
					i++;
				}
				else if (i == 1) 
				{
					st[str].group = atoi(pointer);
					i++;
				}
				else if (i == 2) 
				{
					st[str].zachnum = atoi(pointer);
					i++;
				}
				else if (i == 3) 
				{
					st[str].MA = atof(pointer);
					i++;
				}
				else if (i == 4) 
				{
					st[str].GA = atof(pointer);
					i++;
				}
				else if (i == 5) 
				{
					st[str].PROG = atof(pointer);
					i = 0;
					str++;
				}

				pointer = strtok(NULL, " ");
			}
			n = count / 6;
		}

	}
	fclose(iFile);

	for (int i = 0; i < n; i++)
	{
		st[i].avg = (st[i].MA + st[i].GA + st[i].PROG) / 3;

	}
	setlocale(LC_ALL, "rus");

	for (int i = 0; i < n; i++)
	{
		printf("%s", " ");
		printf("%s", st[i].surname);
		printf("%s", " ");
		printf("%lf", st[i].avg);
		printf("%s", " ");
		printf("\n");
	}
	printf("%s", "\n");

	double ofall = 0;
	for (int i = 0; i < n; i++)
	{
		ofall = ofall + st[i].avg;
	}
	ofall /= n;
	printf("%s", " ");
	printf("%s", " Средний балл группы = ");
	printf("%lf", ofall);

	double tmpD;
	char *tmpC;
	int tmpI;

	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (st[j].group > st[j + 1].group)
			{
				tmpC = st[j].surname;
				st[j].surname = st[j + 1].surname;
				st[j + 1].surname = tmpC;

				tmpI = st[j].group;
				st[j].group = st[j + 1].group;
				st[j + 1].group = tmpI;

				tmpI = st[j].zachnum;
				st[j].zachnum = st[j + 1].zachnum;
				st[j + 1].zachnum = tmpI;

				tmpD = st[j].MA;
				st[j].MA = st[j + 1].MA;
				st[j + 1].MA = tmpD;

				tmpD = st[j].GA;
				st[j].GA = st[j + 1].GA;
				st[j + 1].GA = tmpD;

				tmpD = st[j].PROG;
				st[j].PROG = st[j + 1].PROG;
				st[j + 1].PROG = tmpD;

				tmpD = st[j].avg;
				st[j].avg = st[j + 1].avg;
				st[j + 1].avg = tmpD;


			}
		}
	}


	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n - 1; j++)
		{
			if (st[j].group == st[j + 1].group && st[j].surname[0] > st[j + 1].surname[0])

			{
				tmpC = st[j].surname;
				st[j].surname = st[j + 1].surname;
				st[j + 1].surname = tmpC;

				tmpI = st[j].zachnum;
				st[j].zachnum = st[j + 1].zachnum;
				st[j + 1].zachnum = tmpI;

				tmpD = st[j].MA;
				st[j].MA = st[j + 1].MA;
				st[j + 1].MA = tmpD;

				tmpD = st[j].GA;
				st[j].GA = st[j + 1].GA;
				st[j + 1].GA = tmpD;

				tmpD = st[j].PROG;
				st[j].PROG = st[j + 1].PROG;
				st[j + 1].PROG = tmpD;

				tmpD = st[j].avg;
				st[j].avg = st[j + 1].avg;
				st[j + 1].avg = tmpD;


			}
		}
	}
	printf("%s", "\n");
	printf("%s", "\n");
	for (int i = 0; i < n; i++)
	{
		fprintf(oFile, "%s", st[i].surname);
		fprintf(oFile, "%s", " ");
		fprintf(oFile, "%d", st[i].group);
		fprintf(oFile, "%s", " ");
		fprintf(oFile, "%d", st[i].zachnum);
		fprintf(oFile, "%s", " ");
		fprintf(oFile, "%lf", st[i].MA);
		fprintf(oFile, "%s", " ");
		fprintf(oFile, "%lf", st[i].GA);
		fprintf(oFile, "%s", " ");
		fprintf(oFile, "%lf", st[i].PROG);
		fprintf(oFile, "%s", " ");
		fprintf(oFile, "%lf", st[i].avg);
		fprintf(oFile, "%s", "\n");
	}

	for (int i = 0; i < n; i++)
	{
		if ((st[i].MA == 10 || st[i].MA == 9) && (st[i].GA == 10 || st[i].GA == 9) && (st[i].PROG == 10 || st[i].PROG == 9))
		{
			fprintf(otlichnik, "%s", st[i].surname);
			fprintf(otlichnik, "%s", " ");
			fprintf(otlichnik, "%d", st[i].group);
			fprintf(otlichnik, "%s", " ");
			fprintf(otlichnik, "%d", st[i].zachnum);
			fprintf(otlichnik, "%s", " ");
			fprintf(otlichnik, "%s", "\n");
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (st[i].MA < 9 || st[i].GA < 9 || st[i].PROG < 9)
		{
			fprintf(neud, "%s", st[i].surname);
			fprintf(neud, "%s", " ");
			fprintf(neud, "%d", st[i].group);
			fprintf(neud, "%s", " ");
			fprintf(neud, "%d", st[i].zachnum);
			fprintf(neud, "%s", " ");
			fprintf(neud, "%s", "\n");
		}
	}
	fclose(neud);
	fclose(otlichnik);
	fclose(oFile);

	system("pause");
}








////C7 ex.3
//#define  _CRT_SECURE_NO_WARNINGS
//#include <iostream>	
//using namespace std;
//
//struct chelovek
//{
//	char name[100];
//	int nomer_groupy;
//	int zachetka;
//	int ocenkaMAN;
//	int ocenkaGeo;
//	int ocenkaProg;
//};
//
//
//void change_positions(chelovek *a1, chelovek* a2)
//{
//	chelovek t;
//	t = *a1;
//	*a1 = *a2;
//	*a2 = t;
//}
//
//
//int Ex3()
//{
//	FILE *file;
//	file = fopen("test\\test.test", "r");
//	if (file == NULL)
//	{
//		printf("Error\n");
//		exit(0);
//	}
//	
//
//	int n = 0;
//	while (true)
//	{
//		char nill_terminator;
//		scanf("%c", nill_terminator);
//		if (nill_terminator=='\0')
//			n++;
//	}
//
//
//
//
//	for (int i = 0; i < n; i++)
//	{
//
//		scanf(%s %d %d %d %d %d, chel[i].name, chel[i].nomer_groupy, chel[i].zachetka, chel[i].ocenkaMAN, chel[i].ocenkaGeo, chel[i].ocenkaProg);
//	}
//
//
//
//chelovek chel_stat[] = {
//		{ 2, "Artem", "Zaiac", "Vladimirovich", { 6,7,8 }, 2 },
//		{ 1, "Roman", "Volk", "Ivanovich", { 9,8,5 }, 1 },
//		{ 2, "Egor", "Busko", "Andreevich", { 7,8,4 }, 0 },
//		{ 0, "Lesha", "Petrov", "Dmitrievich", { 5,3,9 }, 1 }
//
//
//	chel = new chelovek[n];
//
//	system("cls");
//	chelovek *chel;
//	chel = chel_stat;
//
//	/*	chel = new chelovek[n];
//	for (int i = 0; i < n; i++)
//		{
//			cout << "Vvedite kurs:" << endl;
//			cin >> chel[i].kurs;
//			cout << "Vvedite name:" << endl;
//			cin >> chel[i].name;
//			cout << "Vvedite surname:" << endl;
//			cin >> chel[i].surname;
//			cout << "Vvedite patron:" << endl;
//			cin >> chel[i].patron;
//			for (int j = 0; j < 3; j++)
//			{
//				cout << "Vvedite ocenki "<<i+1 <<" uchenika:"<< endl;
//				cin >> chel[i].ocenki[j];
//			}
//			cout << "Vvedite sostoyanie:" << endl;
//			cin >> chel[i].mat_polozenie;
//			system("cls");
//		}
//		system("cls");
//		*/
//
//
//
//		//Считаем средний балл
//	int *srball = new int[n];
//	for (int i = 0; i < n; i++)
//	{
//		srball[i] = (chel[i].ocenki[0] + chel[i].ocenki[1] + chel[i].ocenki[2]) / 3;
//	}
//
//
//
//	//Присваиваем стипендию
//	for (int i = 0; i < n; i++)
//	{
//		chel[i].stipendiya = opredelenie_stipendii(chel[i].mat_polozenie, srball[i]);
//	}
//
//
//
//	//Сортируем по курсам
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n - i - 1; j++)
//		{
//			if (chel[j].kurs > chel[j + 1].kurs ||
//				(chel[j].kurs == chel[j + 1].kurs && chel[j].stipendiya > chel[j + 1].stipendiya))
//
//
//				change_positions(&(chel[j]), &(chel[j + 1]));
//		}
//	}
//
//	flose(file);
//	system("pause");
//	system("cls");
//	return 0;
//}

//int main()
//{
//	Ex3();
//}