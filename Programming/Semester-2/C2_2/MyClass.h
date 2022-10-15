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



	//	����� ��������� ��� n/2, �� 
//	9*2^i-9*2^i/2+1				<size /3
//	8*2^i-6*2^(i+1)/2+1			<size /3
	void ShellSort();

	void QuickSort(int *numbers, int left, int right);


	//1 ����
	//���������� ������ ����� ������, ������� � n/2-1 (������ ������� ������). 
	//����� ������� ����� ���� ����� ������� � ���������� ��� ������ �������� 
	//	�� ����, ��� ��������� ������� ��� ��������
	//2 ����
	//����� ��������� ������� ������� � �������� ��������. 
	//������ ������� (����������) ������� ������� � ������� �������. 
	//������� ������� (�� ������ �������) ���������� ������ n-1 ���������� ��������. 
	void siftDown(int *numbers, int root, int bottom);
	void HeapSort(int *numbers, int array_size);
};