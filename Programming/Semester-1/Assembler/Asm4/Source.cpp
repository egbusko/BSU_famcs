// 9-10.10.18

#include <iostream>
using namespace std;


int Ex1()
{
int numbval[5] = { 1,2,3,4,5 };			
int sumval = 0;							

//сумма чисел массива
_asm
{lea esi, numbval				// помещает адрес numbval в esi

/*     оманда загрузки действительного адреса LEA очень похожа на команду
MOV.  Ќо вместо пересылки данных из €чейки пам€ти в регистр команда
LEA загружает в регистр адрес данных. */

mov ebx, 5						//помещает 5 в ebx
mov eax, 0						//помещает 0 в aex
label1: add eax, [esi]			//складывает eax и какое-то число массива
	add esi, 4					//складывает esi и 4, т.к. тип целочисленный.
	dec ebx						//уменьшает ebx на 1
	jnz label1  //вместо loop	//прыгает на метку label1
	mov sumval, eax				//помещает eax в sumval

}			
cout << sumval<<endl;
system("pause");
system("cls");
return 0;
}



int Ex2()
{
	int i, a = 0;
	int n, res = 0;
	
	int mas[10];
	for (int i = 0; i < 10; i++)
	{
		cout << "Enter the " << i + 1 << "-th value: ";
		cin >> mas[i];
	}
	int B = mas[0], M = mas[0];
	_asm
	{

		lea esi, [mas]				
		lea eax, [mas]
		lea edx, [mas]
		mov ecx, 10	

		_label1: 
									dec ecx
									cmp ecx, a
								je end_

				add	eax,4
				mov ebx, [eax]
				cmp [esi],ebx
			jl max
				cmp [edx], ebx
			ja min	
				jmp _label1
				

			max:
		mov ebx, [eax]
		mov B, ebx
		mov esi, eax
			jmp _label1

			min:
		mov ebx, [eax]
		mov M,ebx
		mov edx, eax
			jmp _label1

			end_:
	}
	cout <<"Max: "<<B<< endl;
	cout << "Min: " << M << endl;
	system("pause");
	system("cls");
	return 0;
}



int Ex3()
{
	int srariphm, srariphm2, a[20];
	for (int i = 0; i < 20; i++)
	{
		cout << "Enter the " << i + 1 << "-th value: ";
		cin >> a[i];
	}
	_asm
	{
		lea eax, a
	
		mov ebx, [eax]
		mov ecx, 20
		dec ecx
		
		mov edx,0
		
		_m1:
	
			add eax, 4
			add ebx, [eax]
		loop _m1

		mov eax, ebx
		mov ebx, 20
		div ebx
		mov srariphm, eax
		mov srariphm2, edx
	}
	system("cls");
	cout << "Sr_ariphm = " << srariphm <<","<< srariphm2 << endl;
	system("pause");
	system("cls");
	return 0;
}



int main()
{
	//Ex1();
	Ex2();
	Ex3();
}