// ТРАНСПОНИРОВАНИЕ МАТРИЦЫ 
#include <iostream>
#include <iomanip>
#include <ctime>
#include <time.h>
using namespace std;


//	Транспонирование не квадратной матрицы (создаем матрицу(4x2)
//по большему параметру(4x4), транспонируем и выводим нужную часть(2x4)
void Ex1()
{
	srand(time(0));
	int **A, n, m, max = 0;
	cout << "Size of matrix? "<<endl;
	cin >> n >> m;
	if (n > m)
		max = n;
	else max = m;

	A = new int *[max];
	for (int i = 0; i < max; i++)
	{
		A[i] = new int[max];
		for (int j = 0; j < max; j++)
			A[i][j] = rand() % 100;
	}

	for (int i = 0; i < n; i++)
	{	
		for (int j = 0; j < m; j++)
			cout << setw(6) << A[i][j];
		cout << endl;
	}

		_asm
		{
			pushad
			mov ebx, A      // для строк
			xor eax, eax
			mov ecx, max
			xor edi, edi

			for1 :
				push ecx
				mov edx, ebx     //для столбцов
				mov esi, [ebx]   //адрес начала строки матрицы
				

				for2 :

					mov edi, [edx]
					push dword ptr[esi][eax]    //обмен
					push dword ptr[edi][eax]
					pop dword ptr[esi][eax]
					pop dword ptr[edi][eax]
					add esi, 4					//по строке
					add edx, 4					// к следующей строке 
				loop for2

				add ebx, 4
				add eax, 4					// диагональный элемент
				pop ecx
			loop for1
				popad
		}
		cout << "RESULT" << endl;
		for (int i = 0; i < m; i++)
		{
			for (int j = 0; j < n; j++)
				cout << setw(6) << A[i][j];
			cout << endl;
		}
		for (int i = 0; i < max; i++)
			delete[] A[i];
		delete[]A;
	system("pause");
	system("cls");
}



//РАЗНОСТЬ МАТРИЦ
void Ex2()
{
	srand(time_t(0));
	int **A, **B, n;
	cout << "Vvedite razmernost matric: " << endl;
	cin >> n;
	A = new int *[n];
	B = new int *[n];


	cout << "matrix 1" << endl;
	for (int i = 0; i < n; i++)
	{
		A[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			A[i][j] = rand() % 100;
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}


	cout << endl << "matrix 2" << endl;
	for (int i = 0; i < n; i++)
	{
		B[i] = new int[n];
		for (int j = 0; j < n; j++)
		{
			B[i][j] = rand() % 100;
			cout << B[i][j] << "\t";
		}
		cout << endl;
	}
	 

	_asm
	{
		mov ebx, A 
		mov eax, B
		mov ecx, n
		xor edi, edi
		xor esi, esi

		_for1 :
			mov esi, [ebx]		// адрес первого элемента первой строки матрицы А
			mov edi, [eax]		// адрес первого элемента первой строки матрицы В
			push ecx

			_for2 :
				mov edx, [edi]	// значение первого элемента первой строки матрицы В
				sub[esi], edx	// разность первого элемента матрицы А и первого элемента матрицы В
				add esi, 4		// переход к следующему элементу строки матрицы А
				add edi, 4		// переход к следующему элементу строки матрицы В
			loop _for2

			pop ecx
			add eax, 4			// переход к следующей строке матрицы В
			add ebx, 4			// переход к следующей строке матрицы А
		loop _for1
	}

	cout << endl << "raznost matric: " << endl;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << A[i][j] << "\t";
		}
		cout << endl;
	}

	system("pause");
	system("cls");
}



int main()
{
	Ex1();
	Ex2();
	return 0;
}