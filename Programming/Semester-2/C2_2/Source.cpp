#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include<stdio.h>
#include <cstring>
	#include <iostream>
	#include <fstream>
	#include <ctime>
#include "MyClass.h"
using namespace std;

int main()
{
	int n;
	cout << "Enter the size: ";
	cin >> n; cout << endl;

	Our_Class a(n);
	a.in_array();
	Our_Class b(a), c(a), d(a);

	int t1 = clock();	int t2, t3, t4;		t2 = t3 = t4 = t1;
	a.SortSliyaniem(a.GetArray(), 0, n-1);
	t1 = clock()-t1;
	cout << endl << "It took " << ((float)t1) / CLOCKS_PER_SEC << " seconds in SortSliyaniem\n";
	for (int i = 0; i < n; i++)
		cout << a.GetArray()[i]<<" ";
	cout << endl;


	b.ShellSort();
	t2 =clock()-t2-t1;
	cout << endl << "It took " << ((float)t2) / CLOCKS_PER_SEC << " seconds in ShellSort\n";
	for (int i = 0; i < n; i++)
		cout << b.GetArray()[i] << " ";
	cout << endl;
	
	
	c.QuickSort(c.GetArray(), 0, n - 1);
	t3 = clock() - t3-t2;
	cout << endl << "It took " << ((float)t3) / CLOCKS_PER_SEC << " seconds in QuickSort\n";
	for (int i = 0; i < n; i++)
		cout << c.GetArray()[i] << " ";
	cout << endl;
	
	
	d.HeapSort(d.GetArray(), n);
	t4 = clock() - t4-t3;
	cout << endl << "It took " << ((float)t4) / CLOCKS_PER_SEC << " seconds in HeapSort\n";
	for (int i = 0; i < n; i++)
		cout << d.GetArray()[i] << " ";
	cout << endl<<endl;



	char sort_sliyaniem[25] = "Sortirovka Sliyaniem";
	char sort_shell[25] = "Sortirovka Shella";
	char sort_quick[25] = "Quick Sort";
	char sort_heap[25] = "Heap Sort";
	char tere[25] = "-----------------------";

	ofstream file("output.txt", ios_base::app);
	file << sort_sliyaniem << endl;	a.out_array();
	file << endl; file << tere;file << endl; file << endl;

	file << sort_shell<<endl; b.out_array();
	file << endl; file << tere; file << endl; file << endl;

	file << sort_quick << endl;	c.out_array();	
	file << endl; file << tere; file << endl; file << endl;

	file << sort_heap << endl; d.out_array();	
	file << endl; file << tere; file << endl; file << endl;

	system("pause");
	return 0;
}