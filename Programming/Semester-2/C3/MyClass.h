#pragma once
#include <iostream>  
using namespace std;

class Array_
{
	int size;
	int *arr;
public:
	Array_();
	Array_(int n);
	Array_(const Array_ &other);
	~Array_();

	void in_array();
	void out_array();
	int GetSize();
	int* GetArray();

	Array_ & operator=(const Array_ &other);
	Array_  operator + (const Array_ &other);
	Array_  &operator - (const Array_ &other);
	bool operator == (const Array_ &other);
	bool operator != (const Array_ &other);
	bool operator > (const Array_ &other);
	bool operator < (const Array_ &other);
	bool operator >= (const Array_ &other);
	bool operator <= (const Array_ &other);

	friend ostream &operator << (ostream &s, const Array_ &obj);
	friend istream &operator >> (istream &s, Array_ &obj);
};