#include <iostream>
using namespace std;


void example1()
{
	char str1[] = "Able to breathe easily again";
	char str2[40];
	int n;
	cin >> n;
	int m = sizeof(str1)-n;
	char s[] = "/0";
	_asm
	{
		lea esi, str1		// адрес источника
		lea edi, str2		// адрес приемника
		mov ecx, m			// размер строки
		cld					// установка DF=0
		rep movsb			// копирование
		lea esi, s
		movsb
		movsb
	}
	cout << str2<< endl;
	system("pause");
	system("cls");
}



void example2()
{
	char str1[] = "Hello, world!";
	char str2[] = "Hello, planete!";
	int m = sizeof(str1), b = 0;
	_asm
	{
			lea esi, str1
			lea edi, str2
			mov ecx, m
			cld					// ѕроверка
			repe cmpsb			// равенства
		jcxz EQUAL_				// строк
			dec esi					//  орректировка
			dec edi					// индексов и
			inc ecx					// размера
		jmp EXIT_
		EQUAL_ :
			mov b, 1			// —троки равны
		EXIT_ :

	}
	if (b == 0)
		cout << "Stroki ne ravny "<<endl;
	else cout << "Stroki ravny "<<endl;
	system("pause");
	system("cls");
}



void Ex1()
{
	char stroka[1000], stroka_2[1000];
	cout << "Vvedite stroku:" << endl;
	gets_s(stroka); cout << endl;

	int position = 0;
	cout << "Enter posision dla copy " << endl;
	cin >> position; cout << endl;

	int Dlina_podstroki = 0;
	cout << "Enter Dlinu_podstroki " << endl;
	cin >> Dlina_podstroki; cout << endl;

	_asm
	{
		lea esi, stroka
		lea edi, stroka_2
		mov ebx, position
		add esi, ebx
		
		mov ecx, Dlina_podstroki
		rep movsb
	}
	cout <<"Poluchenaia stroka - ";
	for (int i = 0; i < Dlina_podstroki; i++)
	{
		cout << stroka_2[i];
	}
	cout << endl;
	system("pause");
	system("cls");
}



void Ex2()
{
	char stroka_1[1000], stroka_2[1000];
	cout << "Vvedite 1 stroku:" << endl;
	gets_s(stroka_1);
	cout << "Vvedite 2 stroku:" << endl;
	gets_s(stroka_2);

	//ƒлина 3 строки, len1 + len2 + нуль терминатор
	int len1 = strlen(stroka_1), len2 = strlen(stroka_2);
	int len = len1 + len2;
	char stroka_3[2000];

	_asm	
	{
		lea esi, stroka_1		//јдрес источника
		lea edi, stroka_3		//јдрес приемника
		mov ecx, len1
		rep movsb

		lea esi, stroka_2
		mov ecx, len2
		rep movsb
	}
	cout << "Poluchenaia stroka - " ;
	for (int i = 0; i < len; i++)
	{
		cout << stroka_3[i];
	}
	cout << endl;
	system("pause");
	system("cls");
}



int main()
{
	//example1();
	//example2();
	Ex1();
	
	//он пропустит это считывание(1), когда вы делаете подр€д
	//выполнение программ
	char s[3];
	gets_s(s);

	Ex2();
	return 0;
}