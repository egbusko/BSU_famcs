#pragma once
#include <iostream>
#include <string>
using namespace std;





template <class T>
int comp(const void * elem1, const void * elem2) {
	if (*(T*)elem1 > *(T*)elem2)
		return 1;
	else if (*(T*)elem1 < *(T*)elem2)
		return -1;
	else
		return 0;
}





template <typename T>
class Lot
{
public:
	virtual void Printing() = 0;
	virtual void PrintArr() = 0;

	virtual void Union() = 0;
	virtual void intersection() = 0;
	virtual void symrazn() = 0;
};



template <typename T>
class Int_num : public Lot<int>
{
	int size;
	T *arr;
	int size2;
	T *arr2;
	int size_3;
	T *arr_3;
public:
	Int_num() {
		size = 5;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = i + 1;

		size2 = 3;
		arr2 = new T[size2];
		for (int i = 0; i < size2; i++)
			arr2[i] = i + 4;

		arr_3 = nullptr;
		size_3 = 0;
	}

	int GetSize1() { return size; }
	int GetSize2() { return size2; }
	T* GetArray1() { return arr; }
	T* GetArray2() { return arr2; }
	void SetSize(int s1, int s2) {
		size = s1;
		size2 = s2;
		
	}

	void Printing() override {
		for (int i = 0; i < size; i++)
			cout << arr[i] << "  ";
		cout << endl;
		
		for (int i = 0; i < size2; i++)
			cout << arr2[i] << "  ";
		cout << endl;
	}

	void PrintArr() override {
		for (int i = 0; i < size_3; i++)
			cout << arr_3[i] << "  ";
		cout << endl;
	}

	void Union()  {
		delete[]arr_3;
		size_3 = size + size2;
		arr_3 = new T[size_3];
		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2, size2, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while ((i < size) && (j < size2))
		{
			if (arr[i] < arr2[j])
				arr_3[k++] = arr[i++];
			else
			{
				if (arr[i] > arr2[j])
					arr_3[k++] =arr2[j++];
				else
				{
					arr_3[k++] = arr[i++];
					j++;
					size_3--;
				}
			}
		}

		while (i < size)
		{
			arr_3[k++] = arr[i++];
		}

		while (j < size2)
		{
			arr_3[k++] = arr2[j++];
		}
	}
	
	void intersection() override {
		delete[]arr_3;
		size_3 = size;
		arr_3 = new T[size_3];
		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2, size2, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while (i < size)
		{
			while (j < size2)
			{
				if (arr[i] == arr2[j])
				{
					arr_3[k++] = arr2[j++];
				}
				else
				{
					j++;
				}
			}
			j = 0;
			i++;
		}
		if (k == 0)
		{
			//throw pustoicont();
		}
		size_3 = k;
		T *y = new T[size_3];				//перезаписываем arr, т.к. кол-во  эл-тов
													//в пересечении может быть меньше чем мы выделили в начале фун-ции
		for (int p = 0; p < k; p++)
			y[p] = arr_3[p];

		delete[]arr_3;
		arr_3 = new T[size_3];
		for (int p = 0; p < k; p++)
			arr_3[p] = y[p];
		delete[] y;
	}

	void symrazn() override {
		delete[]arr_3;
		size_3 = size + size2;
		arr_3 = new T[size_3];
		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2, size2, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while ((i < size) && (j < size2))
		{
			if (arr[i] < arr2[j])
				arr_3[k++] = arr[i++];
			else
			{
				if (arr[i] > arr2[j])
					arr_3[k++] = arr2[j++];
				else
				{
					i++;
					j++;
					size_3-=2;
				}
			}
		}

		while (i < size)
		{
			arr_3[k++] = arr[i++];
		}

		while (j < size2)
		{
			arr_3[k++] = arr2[j++];
		}
	}
};




template <typename T>
class Strings :public Lot<string>
{
	int size;
	T *arr;
	int size2;
	T *arr2;
	int size_3;
	T *arr_3;
public:
	Strings()
	{
		size = 5;
		arr = new T[size];
		for (int i = 0; i < size; i++)
			arr[i] = "a";

		size2 = 3;
		arr2 = new T[size2];
		for (int i = 0; i < size2; i++)
			arr2[i] = "b";

		arr_3 = nullptr;
		size_3 = 0;
	}

	int GetSize1() { return size; }
	int GetSize2() { return size2; }
	T* GetArray1() { return arr; }
	T* GetArray2() { return arr2; }
	void SetSize(int s1, int s2){ 
		size = s1;
		size2 = s2;
	}

	void Printing() override {
		for (int i = 0; i < size; i++)
			cout << arr[i] << "  ";
		cout << endl;

		for (int i = 0; i < size2; i++)
			cout << arr2[i] << "  ";
		cout << endl;
	}
	void PrintArr() override {
		for (int i = 0; i < size_3; i++)
			cout << arr_3[i] << "  ";
		cout << endl;
	}

	void Union() override {
		delete[]arr_3;
		size_3 = size + size2;
		arr_3 = new T[size_3];
		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2, size2, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while ((i < size) && (j < size2))
		{
			if (arr[i] < arr2[j])
				arr_3[k++] = arr[i++];
			else
			{
				if (arr[i] > arr2[j])
					arr_3[k++] = arr2[j++];
				else
				{
					arr_3[k++] = arr[i++];
					j++;
					size_3--;
				}
			}
		}

		while (i < size)
		{
			arr_3[k++] = arr[i++];
		}

		while (j < size2)
		{
			arr_3[k++] = arr2[j++];
		}
	}
	void intersection() override {
		delete[]arr_3;
		size_3 = size;
		arr_3 = new T[size_3];
		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2, size2, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while (i < size)
		{
			while (j < size2)
			{
				if (arr[i] == arr2[j])
				{
					arr_3[k++] = arr2[j++];
				}
				else
				{
					j++;
				}
			}
			j = 0;
			i++;
		}
		if (k == 0)
		{
			//throw pustoicont();
		}
		size_3 = k;
		T *y = new T[size_3];				//перезаписываем arr, т.к. кол-во  эл-тов
													//в пересечении может быть меньше чем мы выделили в начале фун-ции
		for (int p = 0; p < k; p++)
			y[p] = arr_3[p];

		delete[]arr_3;
		arr_3 = new T[size_3];
		for (int p = 0; p < k; p++)
			arr_3[p] = y[p];
		delete[] y;
	}
	void symrazn() override {
		delete[]arr_3;
		size_3 = size + size2;
		arr_3 = new T[size_3];
		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2, size2, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while ((i < size) && (j < size2))
		{
			if (arr[i] < arr2[j])
				arr_3[k++] = arr[i++];
			else
			{
				if (arr[i] > arr2[j])
					arr_3[k++] = arr2[j++];
				else
				{
					i++;
					j++;
					size_3 -= 2;
				}
			}
		}

		while (i < size)
		{
			arr_3[k++] = arr[i++];
		}

		while (j < size2)
		{
			arr_3[k++] = arr2[j++];
		}
	}

};