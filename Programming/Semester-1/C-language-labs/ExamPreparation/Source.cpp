#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"windows.h"
#include<stdio.h>
#include <iomanip>
#include <cstring>

using namespace std;


struct person
{
	char surname[30] = {};
	char name[3] = {};
	char patronymic[3]={};
	int TSUM=0;
	int SUM=0;
	int RSUM=0;
	int SUMD=0;
	person *prev;
};


void cout_person(person* _person){
	cout << _person->surname<<" "<< _person->name <<" "
	     << _person->patronymic << "\t" << _person->TSUM <<"\t"
	     << _person->SUM << "\t" << _person->RSUM << "\t"
	     << _person->SUMD << endl;
}


void cout_all_persons(person **_arr, int _num){
	cout << "-------- Persons -------------------------\n";
	for (int i = 0; i < _num; i++)
	{
		cout_person(_arr[i]);
	}
	cout << "------------------------------------------\n";
}


int compare_p(const void * p1, const void * p2){	
	return  ((*(person**)p1)->SUM) - ((*(person**)p2)->SUM);
}


int compare_string(const void * p1, const void * p2) {
	return  strcmp(  (*(person**)p1)->surname, (*(person**)p2)->surname  );
}


int cmp_pers(const void * key, const void * p){
	return  strcmp( (char*)key , (*(person**)p)->surname  );
}


void SLVE(int SUM, int TSUM, int PRC, int *RSUM, int *SUMD){
	*RSUM=SUM*0.01*PRC+SUM;
	*SUMD = SUM - TSUM;
}


void summirovanie(person**_person,int numb,int*all_tsum, int*all_sum, int*all_rsum) {
	for (int i = 0; i < numb; i++)
	{ 
		*all_tsum += _person[i]->TSUM;
		*all_sum += _person[i]->SUM;
		*all_rsum += _person[i]->RSUM;
	}
}




int main()
{
	setlocale(LC_ALL, ".1251");
	
	//SetConsoleOutputCP(1251);

	FILE *file;
	file = fopen("Spisok.txt", "r");
	
	if (file == NULL)
	{
		printf("Error");
		exit(0);
	}
	int TSUM, PRC;
	fscanf(file, "%d %d", &TSUM, &PRC);
	


	/////////  Считываем и закидываем в структуру + используем список  //////////

	int number_of_persons = 0;
	person *tail = NULL;
	
	while (true)
	{
		person *p=new person; 

	//fscanf будет равно кол-ву удачно считанных эл-тов
		int res = fscanf(file, "%s %s %s %d %d", &p->surname, 
						&p->name, &p->patronymic, &p->TSUM, &p->SUM);
		
		if (res == 0)
		{
			cout << "Ошибка чтения" << endl;
			delete p;
			return 0;
		}
		else if (res == EOF)
		{
			delete p;
			break;
		}

		number_of_persons++;

		p->prev = NULL;

		if (tail == NULL)
			tail = p;
		else
		{
			p->prev = tail;
			tail = p;
		}	
	}
	fclose(file);

	/////////////////////////////////////////////////////////////////////////////



	person** arr_of_pointers = new person*[number_of_persons];
	person *n2 = tail;
	int pos = number_of_persons - 1;
	while (n2)
	{
		arr_of_pointers[pos--] = n2;
		n2 = n2->prev;
	}

	

//////Ex2 ///////////////////////////////////////////////////////////////////////////////////////
	

			//cout_all_persons(arr_of_pointers, number_of_persons);

	qsort(arr_of_pointers, number_of_persons, sizeof(void*), compare_p);

			//cout_all_persons(arr_of_pointers, number_of_persons);


//////Ex3-4 //////////////////////////////////////////////////////////////////////////////////////


	for (int i = 0; i < number_of_persons; i++)
	{
		SLVE(arr_of_pointers[i]->SUM, arr_of_pointers[i]->TSUM, PRC,
			&(arr_of_pointers[i]->RSUM), &(arr_of_pointers[i]->SUMD));
	}
	//system("pause");
	//system("cls");


//////Ex5 ///////////////////////////////////////////////////////////////////////////////////////	


	file = fopen("SSpisok.txt", "w");
	if (file == NULL)
	{
		printf("Error");
		exit(0);
	}
	
	for (int i = 0; i < number_of_persons; i++)
	{
		fprintf(file, "%s %s %s %d %d %d %d\n", arr_of_pointers[i]->surname,
				arr_of_pointers[i]->name, arr_of_pointers[i]->patronymic,
				arr_of_pointers[i]->TSUM, arr_of_pointers[i]->SUM,
				arr_of_pointers[i]->RSUM, arr_of_pointers[i]->SUMD);
	}
	fclose(file);


	//отсортированный только по SUM
	for (int i = 0; i < number_of_persons; i++)
	{
		cout << setw(8) << arr_of_pointers[i]->surname << " "
			<< setw(4) << arr_of_pointers[i]->name << " "
			<< setw(4) << arr_of_pointers[i]->patronymic << " "
			<< setw(4) << arr_of_pointers[i]->TSUM << " "
			<< setw(4) << arr_of_pointers[i]->SUM << " "
			<< setw(4) << arr_of_pointers[i]->RSUM << " "
			<< setw(4) << arr_of_pointers[i]->SUMD << endl;
	}
	

//////Ex6 ///////////////////////////////////////////////////////////////////////////////////////	
	

	qsort(arr_of_pointers, number_of_persons, sizeof(void*), compare_string);

	//отсортированный по фамилиям и SUM
	cout << endl;
	for (int i = 0; i < number_of_persons; i++)
	{
		cout<< setw(8) << arr_of_pointers[i]->surname << " "
			<< setw(4) << arr_of_pointers[i]->name << " "
			<< setw(4) << arr_of_pointers[i]->patronymic << " "
			<< setw(4) << arr_of_pointers[i]->TSUM << " "
			<< setw(4) << arr_of_pointers[i]->SUM << " "
			<< setw(4) << arr_of_pointers[i]->RSUM << " "
			<< setw(4) << arr_of_pointers[i]->SUMD << endl;
	}
	

	file = fopen("FSpisok.txt", "w");
	if (file == NULL)
	{
		printf("Error");
		exit(0);
	}

	fprintf(file, "Задание 6\n");
	for (int i = 0; i < number_of_persons; i++)
	{
		fprintf(file, "%d) %s %s %s %d %d %d %d\n", i+1, arr_of_pointers[i]->surname,
			arr_of_pointers[i]->name, arr_of_pointers[i]->patronymic,
			arr_of_pointers[i]->TSUM, arr_of_pointers[i]->SUM,
			arr_of_pointers[i]->RSUM, arr_of_pointers[i]->SUMD);
	}


//////Ex7 ///////////////////////////////////////////////////////////////////////////////////////	


	int all_TSUM=0, all_SUM=0, all_RSUM=0;
	summirovanie(arr_of_pointers, number_of_persons, &all_TSUM, &all_SUM, &all_RSUM);
	cout << all_TSUM << endl << all_SUM << endl << all_RSUM<<endl;

	fprintf(file, "\nЗадание 7\n");
	fprintf(file, "Сумма, потраченная сотрудниками: %d\n", all_TSUM);
	fprintf(file, "Выделенная сумма: %d\n", all_SUM);
	fprintf(file, "Сумма с процентами: %d\n", all_RSUM);
	fprintf(file, "Сумма, оставшаяся у фирмы: %d\n", all_TSUM - all_RSUM);
	fclose(file);


//////Ex8 ///////////////////////////////////////////////////////////////////////////////////////	












//////Ex9 ///////////////////////////////////////////////////////////////////////////////////////


	int nomer_sotrydnika;  char fam_sotrudnika[20];
	cout << endl <<  "Введите число номер сотрудника:" << endl;
	for (int i = 0; i < number_of_persons; i++) 
	{
		cout << i + 1 << ") " << arr_of_pointers[i]->surname << endl;
	}
	cin >> nomer_sotrydnika;
	strcpy(fam_sotrudnika, arr_of_pointers[nomer_sotrydnika-1]->surname);
	//cout << fam_sotrudnika<<endl;

	
	
	int perem = 1;
	if ((nomer_sotrydnika < 1) || (nomer_sotrydnika > 8))
	{
		cout << "Такого сотрудника нет"<<endl;
		perem--;
	}
	else
	{
		person** ptrItem = (person**)bsearch(fam_sotrudnika, arr_of_pointers,
			number_of_persons, sizeof(person*), cmp_pers);
		cout_person(*ptrItem);							//cout << (*ptrItem)->surname<<endl;
	}

	file = fopen("FSpisok.txt", "a");
	if (file == NULL)
	{
		printf("Error");
		exit(0);
	}
	fprintf(file, "\nЗадание 9\n");
	if (perem == 1)
	{
		fprintf(file, "Сотрудник с фамилией %s есть\n", arr_of_pointers[nomer_sotrydnika-1]->surname);
	}
	else
		fprintf(file, "Сотрудника с такой фамилией нет\n");


//////Ex10 ///////////////////////////////////////////////////////////////////////////////////////


	fprintf(file, "\nЗадание 10\n");
	fprintf(file, "Количество сотрудников: %d\n", number_of_persons);


//////////////////////////////////////////////////////////////////////////////////////////////////
	fclose(file);
	system("pause");
	system("cls");
	return 0;
}






//////////////////////////////////////////////////////////////////////////////////////////////////

//создание динамич. массива
/*char *arr_of_1st_surname_letters = new char[number_of_persons];

for (int i = 0; i < number_of_persons; i++)
	arr_of_1st_surname_letters[i] = arr_of_pointers[i]->surname[0];

for (int i = 0; i < number_of_persons; i++)
	cout << arr_of_1st_surname_letters[i] << endl;*/

//считывание из файла на C++
/*
#define CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
using namespace std;

struct company
{
	int ALLSUM;
	int PRC;
	char SURNAME[50];
	char NAME[50];
	char DADCHESTVO[50];
	int TSUM;
	int SUM;
	double RSUM;
	double SUMD;
};



void read(int n,company *arr)
{
	ifstream input("spisok.txt");
	input >> arr->ALLSUM;
	input >> arr->PRC;
	for (int i = 0; i < n; i++)
	{
		input >> arr[i].SURNAME;
		input >> arr[i].NAME;
		input >> arr[i].DADCHESTVO;
		input >> arr[i].TSUM;
		input >> arr[i].SUM;
	}
}
void vivod(company *arr, int n)
{
	cout << arr->ALLSUM << " " << arr->PRC << endl;
	for (int i = 0; i < n; i++)
	{
		cout << arr[i].SURNAME << " " << arr[i].NAME << " " << arr[i].DADCHESTVO << " " << arr[i].TSUM << " " << arr[i].SUM << endl;

	}
}
void main()
{
	setlocale(LC_ALL, "ru");
	int n;
	cin >> n;
	company *arr = new company[n];
	ifstream input("spisok.txt");
	read(n, arr);
	vivod(arr, n);

	vivod(arr, n);

	system("pause");
}*/

//////////////////////////////////////////////////////////////////////////////////////////////////