#pragma once
#include <iostream>  
#include <fstream>
using namespace std;

class Our_Class
{
	int size;
	int *Array;

public:
	Our_Class(int n);
	Our_Class(const Our_Class &other);
	~Our_Class();

	void in_array();
	void out_array();
	int GetSize();
	int* GetArray();


	/////////////////////////////////////////////////////////////////////////////////////////////
	///////////////////////////			SORTS			/////////////////////////////////////////
	/////////////////////////////////////////////////////////////////////////////////////////////	

	void Merge(int *A, int first, int last);
	void SortSliyaniem(int *A, int first, int last);



	//	Здесь испльзуем шаг n/2, но 
//	9*2^i-9*2^i/2+1				<size /3
//	8*2^i-6*2^(i+1)/2+1			<size /3
	void ShellSort();

	void QuickSort(int *numbers, int left, int right);


	//1 этап
	//Определяем правую часть дерева, начиная с n/2-1 (нижний уровень дерева). 
	//Берем элемент левее этой части массива и просеиваем его сквозь пирамиду 
	//	по пути, где находятся меньшие его элементы
	//2 этап
	//Берем последний элемент массива в качестве текущего. 
	//Меняем верхний (наименьший) элемент массива и текущий местами. 
	//Текущий элемент (он теперь верхний) просеиваем сквозь n-1 элементную пирамиду. 
	void siftDown(int *numbers, int root, int bottom);
	void HeapSort(int *numbers, int array_size);
};