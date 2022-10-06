#include "pch.h"
#include "windows.h"
#include <iostream>
#include "process.h" 
#include  "winbase.h"
#include <algorithm>
#include <mutex>
using namespace std;


void producer(void *lParam);
void consumer(void *lParam);



class MonitorStack {
private:
	
	int size;
	int howMuch;
	mutex g_lock;
	HANDLE hasEmptySlot = CreateEvent(NULL, TRUE, FALSE, "hasEmptySlot");
	HANDLE hasStackItem = CreateEvent(NULL, TRUE, FALSE, "hasStackItem");
	
public:
	int * stack;

	MonitorStack(int size) {
		this->size = size;
		stack = new int[this->size + 1];
		howMuch = 0;
	};
	~MonitorStack() {
		delete[] stack;
	}

	int GetSize() {
		return size;
	}
	int GetHowMuch() {
		return howMuch;
	}
	MonitorStack operator --(int) {
		size--;
		return size;
	}
	
	int Push(int& element) {
		while (true) {
			g_lock.lock();

			if (howMuch < size) {
				int ind;
				try {
					ind = ++howMuch;
					stack[ind] = element;
				}
				catch (...) {}
				if (howMuch == size) {
					ResetEvent(hasEmptySlot);
				}
				SetEvent(hasStackItem);
				cout << "Produced number: " << ind << endl;
				g_lock.unlock();
				return ind;
			}
			else {
				g_lock.unlock();
				WaitForSingleObject(hasEmptySlot, INFINITE);
			}
		}
	}

	int Pop() {
		while (true) {
			g_lock.lock();
				if (howMuch > 0) {
					int tmp;
					try {	
						 tmp = howMuch--;
					}
					catch (...) {}
					if (howMuch == 0) {
						ResetEvent(hasStackItem);
					}
					SetEvent(hasEmptySlot);
					cout << "Consumed number: " << tmp << endl;
					g_lock.unlock();
					return tmp;
				}
				else {
					g_lock.unlock();
					WaitForSingleObject(hasStackItem, INFINITE);
				}
		}
	}
};




struct infoThread {
	MonitorStack *monitor;
	int numToPush;
	int numToPop;
	int hasPushed = 0;
	int hasPoped = 0;
	HANDLE hEnded;
};



int main()
{
	infoThread *objInfo;
	int sizeMonitor = 0;
	cout << "Enter size: ";
	cin >> sizeMonitor;
	MonitorStack monit(sizeMonitor);
	
	int amountNumPr = 0;
	int amountNumCons = 0;
	cout << "\nEnter num producers: ";
	cin >> amountNumPr;
	cout << "Enter num comsumers: ";
	cin >> amountNumCons;
	objInfo = new infoThread[amountNumPr + amountNumCons];
	HANDLE *hThreadsEnded = new HANDLE[amountNumPr + amountNumCons];
	int *numForProducer = new int [amountNumPr];
	int *numForConsumer = new int[amountNumCons];



	for (int i = 0; i < amountNumPr + amountNumCons; i++) {
		hThreadsEnded[i] = CreateEvent(NULL, TRUE, FALSE, "ended" + i);
		objInfo[i].hEnded = hThreadsEnded[i];
		objInfo[i].monitor = &monit;
	}
	for (int i = 0; i < amountNumPr; i++) {
		cout << "Enter num for producer: ";
		cin >> numForProducer[i];
	}
	for (int i = 0; i < amountNumCons; i++) {
		cout << "Enter num for comsumer: ";
		cin >> numForConsumer[i];
	}
	cout << endl;
	


	for (int i = 0; i < amountNumPr; i++) {
		objInfo[i].numToPush = numForProducer[i];
		if (CreateThread(NULL, 1024, (LPTHREAD_START_ROUTINE)producer, &objInfo[i], NULL, NULL) == NULL) {
			cout << "#Error thread";
		}
	}

	for (int i = amountNumPr; i < amountNumCons + amountNumPr; i++) {
		objInfo[i].numToPop = numForConsumer[i- amountNumPr];
		if (CreateThread(NULL, 1024, (LPTHREAD_START_ROUTINE)consumer, &objInfo[i], NULL, NULL) == NULL) {
			cout << "#Error thread";
		}
	}


	
	WaitForMultipleObjects(	amountNumCons + amountNumPr,   // number of handles in array
							hThreadsEnded,		// array of thread handles
							TRUE,           // wait until all are signaled
							INFINITE);
	
	system("pause");
	return 0;
}





void producer(void *lParam) {
	infoThread *obj = (infoThread*)lParam;
	int ind = 0;
	for (int i = 1; i <= obj->numToPush; i++) {
		ind = obj->monitor->Push(i);
		obj->hasPushed++;
	}
	cout << endl;
	SetEvent(obj->hEnded);
}



void consumer(void *lParam) {
	infoThread *obj = (infoThread*)lParam;
	int ind = 0;
	for (int i = 0; i < obj->numToPop; i++) {
		ind = obj->monitor->Pop();
		obj->hasPoped++;
	}
	cout << endl;
	SetEvent(obj->hEnded);
}
