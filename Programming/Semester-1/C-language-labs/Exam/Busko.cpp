//Бусько Егор

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include"windows.h"
#include<stdio.h>
#include <iomanip>
#include <cstring>

using namespace std;


struct podarok
{
	char name_1[30] = {};
	char name_2[30] = {};
	double chena = 0;
	int number = 0;
	podarok *prev;
};
struct brak
{
	char name_1[30] = {};
	char name_2[30] = {};
	double chena = 0;
	int number = 0;
	brak *prev;
};
struct dop_podarki
{
	char name_1[30] = {};
	char name_2[30] = {};
	double chena = 0;
	int number = 0;
	dop_podarki *prev;
};


void cout_podarok(podarok* _podarok) {
	cout << _podarok->name_1 <<" " << _podarok->name_2 << "\t"
		 << _podarok->chena << "\t" << _podarok->number << endl;
}


void cout_all_podarki(podarok **_arr, int _num) {
	cout << "-------- Podarki -------------------------\n";
	for (int i = 0; i < _num; i++)
	{
		cout_podarok(_arr[i]);
	}
	cout << "------------------------------------------\n";
}


int compare_string_podarok(const void * p1, const void * p2) {
	return  strcmp((*(podarok**)p1)->name_1, (*(podarok**)p2)->name_1);
}


int compare_string_brak(const void * p1, const void * p2) {
	return  strcmp((*(brak**)p1)->name_1, (*(brak**)p2)->name_1);
}


int compare_string_dop(const void * p1, const void * p2) {
	return  strcmp((*(dop_podarki**)p1)->name_1, (*(dop_podarki**)p2)->name_1);
}


double Fsum(int num_podarok, podarok**_podarok, int _num){
	double _S = 0;

	for (int i = 0; i < _num; i++)
	{	
		_S+=_podarok[num_podarok]->chena;
	}
	return _S;
}

double Fsum_2(int num_brak, brak**_brak, int _num) {
	double _S = 0;

	for (int i = 0; i < _num; i++)
	{
		_S += _brak[num_brak]->chena;
	}
	return _S;
}


int compare_p(const void * p1, const void * p2) {
	return  ((*(podarok**)p2)->chena) - ((*(podarok**)p1)->chena);
}


int cmp_pers(const void * key, const void * p) {
	return  strcmp((char*)key, (*(podarok**)p)->name_1);
}




int main()
{
	setlocale(LC_ALL, ".1251");

	FILE *file;
	file = fopen("Gift.txt", "r");

	if (file == NULL)
	{
		printf("Error");
		exit(0);
	}
	int numb_of_podarki;
	fscanf(file, "%d", &numb_of_podarki);

/////////////////////////////////////////////////////////////////////////////

	int number_of_types_podarki = 0;
	podarok *tail = NULL;

	while (true)
	{
		podarok *p = new podarok;
		
		//fscanf будет равно кол-ву удачно считанных эл-тов
		int res = fscanf(file, "%s %s %lf %d", &p->name_1, &p->name_2, &p->chena, &p->number);

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

		number_of_types_podarki++;

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

	podarok** arr_of_pointers = new podarok*[number_of_types_podarki];
	podarok *n2 = tail;
	int pos = number_of_types_podarki - 1;
	while (n2)
	{
		arr_of_pointers[pos--] = n2;
		n2 = n2->prev;
	}
	
	//for (int i = 0; i < number_of_types_podarki; i++)
	//	{
	//		cout /*<< setw(15)*/ << arr_of_pointers[i]->name_1 << " "
	//			 /*<< setw(20)*/ << arr_of_pointers[i]->name_2 << "   "
	//			 /*<< setw(4)*/  << arr_of_pointers[i]-> chena << "   "
	//			 /*<< setw(4)*/  << arr_of_pointers[i]->number << endl;
	//	}



//////Ex2 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	file = fopen("Brak.txt", "r");
	if (file == NULL)
	{
		printf("Error");
		exit(0);
	}
	int numb_of_brak;
	fscanf(file, "%d", &numb_of_brak);


/////////////////////////////////////////////////////////////////////////////
	int number_of_types_brak = 0;
	brak *tail2 = NULL;

	while (true)
	{
		brak *p2 = new brak;

		int res = fscanf(file, "%s %s %lf %d", &p2->name_1, &p2->name_2, &p2->chena, &p2->number);

		if (res == 0)
		{
			cout << "Ошибка чтения" << endl;
			delete p2;
			return 0;
		}
		else if (res == EOF)
		{
			delete p2;
			break;
		}
	
		number_of_types_brak++;

		p2->prev = NULL;

		if (tail2 == NULL)
			tail2 = p2;
		else
		{
			p2->prev = tail2;
			tail2 = p2;
		}
	}
	fclose(file);
/////////////////////////////////////////////////////////////////////////////

	brak** arr_of_pointers2 = new brak*[number_of_types_brak];
	brak *n2_2 = tail2;
	int pos_2 = number_of_types_brak - 1;
	while (n2_2)
	{
		arr_of_pointers2[pos_2--] = n2_2;
		n2_2 = n2_2->prev;
	}


	//cout << endl << endl;
	//for (int i = 0; i < number_of_types_brak; i++)
	//{
	//	cout /*<< setw(15)*/ << arr_of_pointers2[i]->name_1 << " "
	//		/*<< setw(20)*/ << arr_of_pointers2[i]->name_2 << "   "
	//		/*<< setw(4)*/ << arr_of_pointers2[i]->chena << "   "
	//		/*<< setw(4)*/ << arr_of_pointers2[i]->number << endl;
	//}


//////Ex3 /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	qsort(arr_of_pointers, number_of_types_podarki, sizeof(void*), compare_string_podarok);
	qsort(arr_of_pointers2, number_of_types_brak, sizeof(void*), compare_string_brak);


			file = fopen("SortGift.txt", "w");
			if (file == NULL)
			{
				printf("Error");
				exit(0);
			}

	fprintf(file,     "----------Заказанные подарки: ---------- \n");
	for (int i = 0; i < number_of_types_podarki; i++)
	{
		fprintf(file, "%s %s %lf %d\n", arr_of_pointers[i]->name_1,	arr_of_pointers[i]->name_2, 
												arr_of_pointers[i]->chena, arr_of_pointers[i]->number);
	}

	fprintf(file, "\n\n---------- Бракованные подарки: -------- \n");
	for (int i = 0; i < number_of_types_brak; i++)
	{
		fprintf(file, "%s %s %lf %d\n", arr_of_pointers2[i]->name_1, arr_of_pointers2[i]->name_2,
			arr_of_pointers2[i]->chena, arr_of_pointers2[i]->number);
	}
	fclose(file);


	//cout << endl << endl;
	//for (int i = 0; i < number_of_types_podarki; i++)
	//{
	//	cout /*<< setw(15)*/ << arr_of_pointers[i]->name_1 << " "
	//		/*<< setw(20)*/ << arr_of_pointers[i]->name_2 << "   "
	//		/*<< setw(4)*/ << arr_of_pointers[i]->chena << "   "
	//		/*<< setw(4)*/ << arr_of_pointers[i]->number << endl;
	//}

	//cout << endl << endl;
	//for (int i = 0; i < number_of_types_brak; i++)
	//{
	//	cout /*<< setw(15)*/ << arr_of_pointers2[i]->name_1 << " "
	//		/*<< setw(20)*/ << arr_of_pointers2[i]->name_2 << "   "
	//		/*<< setw(4)*/ << arr_of_pointers2[i]->chena << "   "
	//		/*<< setw(4)*/ << arr_of_pointers2[i]->number << endl;
	//}


//////Ex4 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	
	double S = 0, SB = 0;
	for (int i = 0; i < number_of_types_podarki; i++)
	{
		S+=Fsum(i,arr_of_pointers, arr_of_pointers[i]->number);
	}
	//cout << endl << S << endl;


	for (int i = 0; i < number_of_types_brak; i++)
	{
		SB += Fsum_2(i, arr_of_pointers2, arr_of_pointers2[i]->number);
	}
	//cout << endl << SB << endl;


//////Ex5 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	file = fopen("DisCount.txt", "r");
	if (file == NULL)
	{
		printf("Error");
		exit(0);
	}

	int number_of_types_dop = 0;
	dop_podarki *tail3 = NULL;

	while (true)
	{
		dop_podarki *p3 = new dop_podarki;

		int res = fscanf(file, "%s %s %lf %d", &p3->name_1, &p3->name_2, &p3->chena);

		if (res == 0)
		{
			cout << "Ошибка чтения" << endl;
			delete p3;
			return 0;
		}
		else if (res == EOF)
		{
			delete p3;
			break;
		}

		number_of_types_dop++;

		p3->prev = NULL;

		if (tail3 == NULL)
			tail3 = p3;
		else
		{
			p3->prev = tail3;
			tail3 = p3;
		}
	}
	fclose(file);


	dop_podarki** arr_of_pointers3 = new dop_podarki*[number_of_types_dop];
	dop_podarki *n2_3 = tail3;
	int pos_3 = number_of_types_dop - 1;
	while (n2_3)
	{
		arr_of_pointers3[pos_3--] = n2_3;
		n2_3 = n2_3->prev;
	}

	qsort(arr_of_pointers3, number_of_types_dop, sizeof(void*), compare_string_dop);


	//cout << endl << endl;
	//for (int i = 0; i < number_of_types_dop; i++)
	//{
	//	cout /*<< setw(15)*/ << arr_of_pointers3[i]->name_1 << " "
	//	 	 /*<< setw(20)*/ << arr_of_pointers3[i]->name_2 << "   "
	//		 /*<< setw(4)*/ << arr_of_pointers3[i]->chena << endl;
	//}


//////Ex6 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	int perem = 0;
	for (int i = 0; i < number_of_types_podarki; i++)
	{
		for (int j = 0; j < number_of_types_brak; j++)
		{
			perem = strcmp(arr_of_pointers[i]->name_1, arr_of_pointers2[j]->name_1);
			if (perem == 0)
			{
				strcpy(arr_of_pointers[i]->name_1, arr_of_pointers3[i]->name_1);
				strcpy(arr_of_pointers[i]->name_2, arr_of_pointers3[i]->name_2);
				arr_of_pointers[i]->chena = arr_of_pointers3[i]->chena;
			}
		}
	}


//////Ex7 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

	double SP = 0;
	for (int i = 0; i < number_of_types_podarki; i++)
	{
		SP += Fsum(i, arr_of_pointers, arr_of_pointers[i]->number);
	}
	//cout << endl << SP << endl;
	

//////Ex8 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


	qsort(arr_of_pointers, number_of_types_podarki, sizeof(void*), compare_p);


	//cout << endl << endl;
	//for (int i = 0; i < number_of_types_podarki; i++)
	//{
	//	cout /*<< setw(15)*/ << arr_of_pointers[i]->name_1 << " "
	//		/*<< setw(20)*/ << arr_of_pointers[i]->name_2 << "   "
	//		/*<< setw(4)*/ << arr_of_pointers[i]->chena << "   "
	//		/*<< setw(4)*/ << arr_of_pointers[i]->number << endl;
	//}


		file = fopen("NewGift.txt", "w");
		if (file == NULL)
		{
			printf("Error");
			exit(0);
		}

		double Ostatok = S - SP;
		fprintf(file, "Сумма денег S, которую подготовили родители: %lf\n", S);
		fprintf(file, "Сумма денег SB, стоимость бракованных подарков: %lf\n", SB);
		fprintf(file, "Сумма денег SP, стоимость НЕ бракованных подарков: %lf\n", SP);
		fprintf(file, "Общая потраченная сумма и остаток денег, если он был: %lf\n", Ostatok);
		fclose(file);

		
///////Ex9 ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

		
		cout << "Упражнение 9\n";
			int nomer_podarka;  char name_podarka[20];
			cout << endl << "Введите число номер подарка:" << endl;
			for (int i = 0; i < number_of_types_podarki; i++)
			{
				cout << i + 1 << ") " << arr_of_pointers[i]->name_1 << arr_of_pointers[i]->name_2 <<endl;
			}
			cin >> nomer_podarka;
			strcpy(name_podarka, arr_of_pointers[nomer_podarka - 1]->name_1);
			//cout << name_podarka <<endl;
		
		
		
			int peremen = 1;
			if ((nomer_podarka < 1) || (nomer_podarka > 10))
			{
				cout << "Такого подарка нет" << endl;
				peremen--;
			}
			else
			{
				podarok** ptrItem = (podarok**)bsearch(name_podarka, arr_of_pointers,
					number_of_types_podarki, sizeof(podarok*), cmp_pers);
				
				if (ptrItem != 0)
					cout_podarok(*ptrItem);
										
				//cout << (*ptrItem)->name_1<<endl;
			}
		
		
		system("pause");
		system("cls");
		return 0;
}