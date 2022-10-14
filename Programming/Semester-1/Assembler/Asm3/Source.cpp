// 2-3.10.18

#include <iostream>
using namespace std;


//Palindrome
int A1()
{
	int a, b;
	cout << "Enter the  number for testing: " << endl;
	cin >> a;

	_asm
	{
		mov eax, a
		mov ecx, 0
		mov ebx, 10
		mov edx, 0

		_met:
		push eax
			mov eax, ecx
			mul ebx
			mov ecx, eax
			pop eax
			cdq
			div ebx
			add ecx, edx
			cmp eax, 0
			jg _met

			mov b, ecx
	}
	if (b == a)
		cout << "Is a palindrome. " << endl;
	else
		cout << "Is not palindrome. " << endl;
	system("pause");
	system("cls");
	return 0;
}


//perfect number
int B1()
{
	int a=1, b=2, m, sum=0;
	cout << "Enter the  number for testing: " << endl;
	cin >> m;

	_asm   
	{
		mov eax,m
		mul a
		div b
		mov ecx,eax
		mov esi, 0

		_label:
			inc esi
			mov eax, m
			mov edx, 0
			div esi
			cmp edx, 0
		jne _end
			add sum,esi
		_end:
		loop _label
	}
	if (sum == m)
		cout << "Is a perfect number. " << endl;
	else
		cout << "Is not perfect number. " << endl;
	system("pause");
	return 0;
}

int main()
{
	A1();
	B1();
}