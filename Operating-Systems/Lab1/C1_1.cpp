#include "pch.h"
#include "windows.h"
#include <iostream>
#include "process.h" 
#include  "winbase.h"
#include <algorithm>
using namespace std;


void mySort(void *lParam);

bool comparator_up(int i, int j) {
	return i < j;
}
bool comparator_down(int i, int j) {
	return i > j;
}


struct infoThread { 
	int * myArr;
	int n;
	HANDLE hSemaphore;
	int typeOfSort = 1;
};


int main()
{
	infoThread obj;
	cout << "Number of elements: ";
	cin >> obj.n;
	cout << endl;
	obj.myArr = new int[obj.n];

	for (int i = 0; i < obj.n; i++) {
		cout << "Enter " << i + 1 << "-th element: ";
		cin >> obj.myArr[i];
	}

	cout << endl << "Num of el-ts: " << obj.n << endl;
	for (int i = 0; i < obj.n; i++) {
		cout << obj.myArr[i]<<" ";
	}
	cout << endl;


	cout << endl << "Type of sort? (1-UP  2-DOWN): ";
	cin >> obj.typeOfSort;
	
	

	
	obj.hSemaphore = CreateSemaphore(NULL, 0, 1, NULL);
	HANDLE hThread = CreateThread(NULL, 1024, (LPTHREAD_START_ROUTINE)mySort, &obj, NULL, NULL);

	if (hThread == NULL){
		cout << "Error thread";
	}

	WaitForSingleObject(obj.hSemaphore, INFINITE);
	


	cout << "Circling over obj... Sorted array:";
	for (int i = 0; i < obj.n; i++) {
		cout << obj.myArr[i] << " ";
	}
	cout << endl;

	ReleaseSemaphore(obj.hSemaphore, 1, NULL);

	Sleep(1000);

	CloseHandle(hThread);

	system("pause");
	return 0;
}



void mySort(void *lParam)
{
	infoThread *obj2 = (infoThread*)lParam;

	switch (obj2->typeOfSort) {
	case 1:
		sort(obj2->myArr, obj2->myArr + obj2->n, comparator_up);
		break;
	case 2:
		sort(obj2->myArr, obj2->myArr + obj2->n, comparator_down);
		break;
	default:
		sort(obj2->myArr, obj2->myArr + obj2->n, comparator_up);
		break;
	}
	cout << "sorting.. " << endl;
	ReleaseSemaphore(obj2->hSemaphore, 1, NULL);
	cout << "Waiting in mySort.. " << endl;

	WaitForSingleObject(obj2->hSemaphore, INFINITE);
	cout << "Done Waiting in mySort.. " << endl;
	

	_endthread();
}
