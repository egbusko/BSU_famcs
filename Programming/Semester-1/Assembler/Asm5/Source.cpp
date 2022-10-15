//16-17.10.2018

#include <iostream>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctime>
using namespace std;


int Ex1() 
{
	int n, element, res = 0;
	cout << "Enter number of elements in array: ";
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) 
	{
		cout << "Enter the " << i + 1 << "-th value: ";
		cin >> a[i];
	}

	_asm 
	{
		mov esi, a				//Адрес массиса в esi
		mov ecx, n
		dec ecx					//N-1 в ecx

		metka_1 :
			push ecx			//N-1 в стек
				mov eax, esi	//Адрес  массива в eax
				add eax, 4		//Идем по массиву
				
			metka_2 :
				mov edx, [eax]	
				cmp[esi], edx	//сравниванием 2 эл-та массива
				je end_
				add eax, 4
			loop metka_2

				add esi, 4
				pop ecx
		loop metka_1

		jmp _end



		end_ :
			mov res, 1
			mov element ,edx
			pop ecx
			

		_end :

	}
	if (res != 0) 
		cout << "True "<<endl<<"Element: "<< element << endl;
	else 
		cout << "False" << endl;
	delete[] a;
	system("pause");
	system("cls");
	return 0;
}




int Ex2() 
{
	srand(time(0));
	int n = 0;
	cout << "Enter the number of elements- ";
	cin >> n;
	int *a = new int[n];

	cout <<endl<< "Random array: ";
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100;
		cout << a[i] << " ";
	}

	_asm 
	{
		mov esi, a
		mov ecx, n
	

		_m1 :
				push ecx
				mov eax, esi
				add eax, 4

			_m2 :
					mov edx, [eax]
					
					cmp ecx,1
					je _mm
					cmp[esi], edx
					jl _obmen
					_mm:
					add eax, 4
			loop _m2

				add esi, 4
				pop ecx
		loop _m1


				jmp end_

		_obmen :
			mov ebx, [esi]
			mov edi, [eax]
			mov[esi], edi
			mov[eax], ebx
			add eax, 4
		loop _m2

		end_ :
	}

		cout << endl << "Ordered array: ";
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl<<endl;
	system("pause");
	return 0;
}




int main()
{
	Ex1();
	Ex2();
	return 0;
}