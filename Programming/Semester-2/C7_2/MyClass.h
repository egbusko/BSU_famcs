#pragma once
#include <iostream>  
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
class Array_
{
	int size;
	T *arr;

public:
	Array_() {
		arr = nullptr;
		size = 0;
	}

	Array_(int s): size(s)	{
		arr = new T[s];
	}

	Array_(const Array_ &other) {
		this->size = other.size;
		this->arr = new T[other.size];
		for (int i = 0; i < other.size; i++)
			this->arr[i] = other.arr[i];
	}
	
	~Array_()			{	delete[] arr;	}

	int GetSize()		{	return size;	}
	T* GetArray()		{	return arr;		}

	void nUnion(Array_&arr1, Array_&arr2) {
		delete[] arr;
		size = arr1.size + arr2.size;
		arr = new T[size];
		
		int iThis = 0, iTemp = 0;
		T tempArr[20];
		int k = 1;
		for (int i = 0; i < arr1.size; i++)
		{
			for (int j = 0; j < arr2.size; j++)
			{
				if (arr1.arr[i] == arr2.arr[j])
					k = 0;
			}

			if (k == 1)
				arr[iThis++] = arr1.arr[i];
			else
				tempArr[iTemp++] = arr1.arr[i];

			k = 1;
		}

		int tmp = iTemp;
		while (tmp != 0)
		{
			tmp--;
			arr[iThis++] = tempArr[tmp];
		}


		for (int j = 0; j < arr2.size; j++)
		{
			for (int i = 0; i < arr1.size; i++)
			{
				if (arr1.arr[i] == arr2.arr[j])
					k = 0;
			}

			if (k == 1)
				arr[iThis++] = arr2.arr[j];

			k = 1;
		}

		size = iThis;

		qsort(arr, size, sizeof(T), comp<T>);
	}
	void Union(Array_&arr1, Array_&arr2) {							//объединение
		delete[] arr;
		size = arr1.size + arr2.size;
		arr = new T[size];
		qsort(arr1.arr, arr1.size, sizeof(T), comp<T>);
		qsort(arr2.arr, arr2.size, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while ((i < arr1.size) && (j < arr2.size))
		{
			if (arr1.arr[i] < arr2.arr[j])
				arr[k++] = arr1.arr[i++];
			else
			{
				if (arr1.arr[i] > arr2.arr[j])
					arr[k++] = arr2.arr[j++];
				else
				{
					arr[k++] = arr1.arr[i++];
					j++;
					size--;
				}
			}
		}

		while (i < arr1.size)
		{
			arr[k++] = arr1.arr[i++];
		}

		while (j < arr2.size)
		{
			arr[k++] = arr2.arr[j++];
		}
	}



	void nSymrazn(Array_&arr1, Array_&arr2) {
		delete[] arr;
		size = arr1.size + arr2.size;
		arr = new T[size];

		int iThis = 0, iTemp = 0;
		T tempArr[20];
		int k = 1;
		for (int i = 0; i < arr1.size; i++)
		{
			for (int j = 0; j < arr2.size; j++)
			{
				if (arr1.arr[i] == arr2.arr[j])
					k = 0;
			}

			if (k == 1)
				arr[iThis++] = arr1.arr[i];

			k = 1;
		}



		for (int j = 0; j < arr2.size; j++)
		{
			for (int i = 0; i < arr1.size; i++)
			{
				if (arr1.arr[i] == arr2.arr[j])
					k = 0;
			}

			if (k == 1)
				arr[iThis++] = arr2.arr[j];

			k = 1;
		}

		size = iThis;
		qsort(arr, size, sizeof(T), comp<T>);

	}
	void symrazn(Array_&arr1, Array_&arr2) {						//симметрическая разность
		delete[] arr;	
		size = arr1.size + arr2.size;
		arr = new T[size];
		qsort(arr1.arr, arr1.size, sizeof(T), comp<T>);
		qsort(arr2.arr, arr2.size, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while ((i < arr1.size) && (j < arr2.size))
		{
			if (arr1.arr[i] < arr2.arr[j])
				arr[k++] = arr1.arr[i++];
			else
			{
				if (arr1.arr[i] > arr2.arr[j])
					arr[k++] = arr2.arr[j++];
				else
				{
					i++;
					j++;
					size -= 2;
				}
			}
		}
		while (i < arr1.size)
		{
			arr[k++] = arr1.arr[i++];
		}
		while (j < arr2.size)
		{
			arr[k++] = arr2.arr[j++];
		}
	}


	void intersection(Array_&arr1, Array_&arr2) {							//пересечение
		delete[] arr;
		size = arr1.size;
		arr = new T[size];
		qsort(arr1.arr, arr1.size, sizeof(T), comp<T>);
		qsort(arr2.arr, arr2.size, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while (i < arr1.size)
		{
			while (j < arr2.size)
			{
				if (arr1.arr[i] == arr2.arr[j])
				{
					arr[k++] = arr2.arr[j++];
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
		size = k;
		T *y = new T[size];				//перезаписываем arr, т.к. кол-во  эл-тов
													//в пересечении может быть меньше чем мы выделили в начале фун-ции
		for (int p = 0; p < k; p++)
			y[p] = arr[p];

		delete[]arr;
		arr = new T[size];
		for (int p = 0; p < k; p++)
			arr[p] = y[p];
		delete[] y;
	}

	

	Array_ & operator=(const Array_ &other) {
		this->size = other.size;
		if (this->arr != nullptr)
		{
			delete[] this->arr;
		}
		this->arr = new T[other.size];
		for (int i = 0; i < size; i++)
			this->arr[i] = other.arr[i];
		return *this;
	}


	Array_   operator + (const Array_ &arr2) {
		Array_<T> summa;

		summa.size = size + arr2.size;
		if (summa.arr != nullptr)
			delete[]  summa.arr;
		summa.arr = new T[summa.size];

		
		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2.arr, arr2.size, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while ((i < size) && (j < arr2.size))
		{
			if (arr[i] < arr2.arr[j])
				summa.arr[k++] = arr[i++];
			else
			{
				if (arr[i] > arr2.arr[j])
					summa.arr[k++] = arr2.arr[j++];
				else
				{
					summa.arr[k++] = arr[i++];
					j++;
					summa.size--;
				}
			}
		}

		while (i < size)
		{
			summa.arr[k++] = arr[i++];
		}

		while (j < arr2.size)
		{
			summa.arr[k++] = arr2.arr[j++];
		}

		return summa;
	}


	Array_  operator * (const Array_ &arr2) {
		Array_<T> cross;

		cross.size = size;
		if (cross.arr != nullptr)
			delete[]  cross.arr;
		cross.arr = new T[cross.size];


		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2.arr, arr2.size, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while (i < size)
		{
			while (j < arr2.size)
			{
				if (arr[i] == arr2.arr[j])
				{
					cross.arr[k++] = arr2.arr[j++];
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
		cross.size = k;
		T *y = new T[cross.size];				//перезаписываем arr, т.к. кол-во  эл-тов
													//в пересечении может быть меньше чем мы выделили в начале фун-ции
		for (int p = 0; p < k; p++)
			y[p] = cross.arr[p];

		delete[] cross.arr;
		cross.arr = new T[cross.size];
		for (int p = 0; p < k; p++)
			cross.arr[p] = y[p];
		delete[] y;

		return cross;
	}

	Array_  operator - (const Array_ &arr2) {
		Array_<T> razn;

		razn.size = size + arr2.size;
		if (razn.arr != nullptr)
			delete[]  razn.arr;
		razn.arr = new T[razn.size];


		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2.arr, arr2.size, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while ((i < size) && (j < arr2.size))
		{
			if (arr[i] < arr2.arr[j])
				razn.arr[k++] = arr[i++];
			else
			{
				if (arr[i] > arr2.arr[j])
					razn.arr[k++] = arr2.arr[j++];
				else
				{
					i++;
					j++;
					razn.size-=2;
				}
			}
		}

		while (i < size)
		{
			razn.arr[k++] = arr[i++];
		}

		while (j < arr2.size)
		{
			razn.arr[k++] = arr2.arr[j++];
		}

		return razn;
	}
		


	static Array_* _union(Array_&arr1, Array_&arr2) {
		Array_ * res = new Array_();

		res->nUnion(arr1, arr2);
		return res;
	}
	


	friend ostream &operator << (ostream &out, const Array_<T> &obj) {
		for (int i = 0; i < obj.size; i++)
			out << obj.arr[i] << " ";
		return out;
	}

	friend istream &operator >> (istream &in, Array_<T> &obj) {
		for (int i = 0; i < obj.size; i++)
			in >> obj.arr[i];
		return in;
	}
};

