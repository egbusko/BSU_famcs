#include "MyClass.h"

Our_Class :: Our_Class(int n) {
	Array = new int[n];
	size = n;
}

Our_Class :: Our_Class(const Our_Class &other) {
	this->size = other.size;
	this->Array = new int[other.size];
	for (int i = 0; i < other.size; i++)
		this->Array[i] = other.Array[i];
}

Our_Class :: ~Our_Class() {
	delete[] Array;
}

void Our_Class::in_array() {
	cout << "Enter the array:\n";
	for (int i = 0; i < size; i++)
	{
		cout << "The " << i + 1 << " element- ";
		cin >> Array[i];
	}
}

void Our_Class :: out_array() {
	ofstream file("output.txt", ios_base::app);
	for (int i = 0; i < size; i++)
		file << Array[i] << ' ';
}

int Our_Class :: GetSize() {
	return size;
}
int* Our_Class :: GetArray() {
	return Array;
}

void Our_Class :: Merge(int *A, int first, int last)
{
	int middle, start, final, j;
	int *mas = new int[100];
	middle = (first + last) / 2;
	start = first; //начало левой части
	final = middle + 1; //начало правой части
	for (j = first; j <= last; j++)
		if ((start <= middle) && ((final > last) || (A[start] < A[final])))
		{
			mas[j] = A[start];
			start++;
		}
		else
		{
			mas[j] = A[final];
			final++;
		}
	for (j = first; j <= last; j++)
		A[j] = mas[j];
	delete[]mas;
};

void Our_Class :: SortSliyaniem(int *A, int first, int last)
{
	if (first < last)
	{
		SortSliyaniem(A, first, (first + last) / 2);	//сортировка левой части
		SortSliyaniem(A, (first + last) / 2 + 1, last); //сортировка правой части
		Merge(A, first, last);							//слияние двух частей
	}
};


//	Здесь испльзуем шаг n/2, но 
//	9*2^i-9*2^i/2+1				<size /3
//	8*2^i-6*2^(i+1)/2+1			<size /3
void Our_Class :: ShellSort()
{
	int i, j, step;
	int tmp;
	for (step = size / 2; step > 0; step /= 2)
		for (i = step; i < size; i++)
		{
			tmp = Array[i];
			for (j = i; j >= step; j -= step)
			{
				if (tmp < Array[j - step])
				{
					Array[j] = Array[j - step];
				}
				else
					break;
			}
			Array[j] = tmp;
		}
}


void Our_Class :: QuickSort(int *numbers, int left, int right)
{
	int tmp;
	int begin_of_arr = left;
	int end_of_arr = right;
	tmp = numbers[left];
	while (left < right)
	{
		while ((numbers[right] >= tmp) && (left < right))
			right--;
		if (left != right)
		{
			numbers[left] = numbers[right];
			left++;
		}
		while ((numbers[left] <= tmp) && (left < right))
			left++;
		if (left != right)
		{
			numbers[right] = numbers[left];
			right--;
		}
	}
	numbers[left] = tmp;
	tmp = left;
	left = begin_of_arr;
	right = end_of_arr;

	if (left < tmp)
		QuickSort(numbers, left, tmp);
	if (right > tmp)
		QuickSort(numbers, tmp + 1, right);
}

//1 этап
//Определяем правую часть дерева, начиная с n/2-1 (нижний уровень дерева). 
//Берем элемент левее этой части массива и просеиваем его сквозь пирамиду 
//	по пути, где находятся меньшие его элементы
//2 этап
//Берем последний элемент массива в качестве текущего. 
//Меняем верхний (наименьший) элемент массива и текущий местами. 
//Текущий элемент (он теперь верхний) просеиваем сквозь n-1 элементную пирамиду. 
void Our_Class :: siftDown(int *numbers, int root, int bottom)
{
	int maxChild;
	int done = 0;

	while ((root * 2 <= bottom) && (!done))
	{
		if (root * 2 == bottom)
		{
			maxChild = root * 2;
		}

		else if (numbers[root * 2] > numbers[root * 2 + 1])
		{
			maxChild = root * 2;
		}
		else
		{
			maxChild = root * 2 + 1;
		}
		if (numbers[root] < numbers[maxChild])
		{
			int temp = numbers[root]; // меняем их местами
			numbers[root] = numbers[maxChild];
			numbers[maxChild] = temp;
			root = maxChild;
		}
		else
			done = 1;
	}
}

void Our_Class :: HeapSort(int *numbers, int array_size)
{
	for (int i = (array_size / 2) - 1; i >= 0; i--)
		siftDown(numbers, i, array_size - 1);

	for (int i = array_size - 1; i >= 1; i--)
	{
		int temp = numbers[0];
		numbers[0] = numbers[i];
		numbers[i] = temp;
		siftDown(numbers, 0, i - 1);
	}
}