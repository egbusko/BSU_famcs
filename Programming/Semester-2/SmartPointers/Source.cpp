#include <iostream>
#include <memory>
using namespace std;


template<typename T>
class SmartPointer
{
public:
	SmartPointer(T *ptr)	{
		this->ptr = ptr;
		cout << "Constructor" << endl;
	}
	~SmartPointer()	{
		delete ptr;
		cout << "Destructor" << endl;
	}
	T& operator*()	{
		return *ptr;
	}
private:
	T * ptr;
};


int main()
{
	int SIZE;
	cin >> SIZE;

	shared_ptr<int[]> ptr(new int[SIZE]);

	for (int i = 0; i < SIZE; i++)
	{
		ptr[i] = rand() % 10;
		cout << ptr[i] << " ";
	}

	cout << endl;
	system("pause");
	return 0;
}
