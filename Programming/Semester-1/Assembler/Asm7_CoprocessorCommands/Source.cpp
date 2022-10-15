
#include <iostream>
using namespace std;

void ex1()
// найти значение выражения (6.0*2.0)+(4.5*3.2)
{
	float a = 6.0, b = 2.0, c = 4.5, d = 3.2;
	float rez;
	_asm
	{
		finit		// инициализировать FPU
		fld  a		// втолкнуть 6.0 в стек
		fmul b		// ST(0) = 6.0 * 2.0
		fld  c		// втолкнуть 4.5 в стек
		fmul d		// ST(0) = 4.5 * 3.2
		fadd		// ST(0) = ST(0) + ST(1)
		fstp rez	// вытолкнуть результат
	}
	cout << rez<<endl;
	system("pause");
	system("cls");
}



void ex2()
{
	float a, b, c, d, rez;
	cout << "Enter the first value " << endl;
	cin >> a; cout << endl;
	cout << "Enter the second value " << endl;
	cin >> b; cout << endl;
	cout << "Enter the third value " << endl;
	cin >> c; cout << endl;
	cout << "Enter the fourth value " << endl;
	cin >> d; cout << endl;

	_asm
	{
		finit		
		fld  b		
		fmul c		
		fmul d		
		fld a	
		fadd
		fstp rez	
	}
	cout << rez << "- Result of work" << endl;
	system("pause");
	system("cls");
}



void ex3()
{
	float a = 2.0, b = 4.0, c = 8.0, d = 16.0, e = 32.0;
	float x, r1, r2, r3, r4, rez;
	cout << "Enter the value"<<endl;
	cin >> x;

	_asm
	{
		finit
		fld x
		fld e
		fsub
		fstp r1

		fld x
		fld d
		fsub
		fstp r2

		fld x
		fld c
		fsub
		fstp r3

		fld x
		fld b
		fsub
		fstp r4

		fld x
		fld a
		fsub

				fmul r1
				fstp r1

				fld r2
				fmul r3
				fstp r2

				fld r4
				fmul r2

				fld r1
				fmul r2
			fstp rez

	}
	if (rez == -0)
		rez = 0;
	cout << "The result of work - " << rez << endl;
	system("pause");
	system("cls");
}

int main() 
{
	//ex1();
	ex2();
	ex3();
	return 0;
}