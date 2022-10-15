#include "MyClass.h"
#include <iostream>


Array_::Array_() {
	arr = new int[100];
	size = 100;
}
Array_ :: Array_(int n) {
	arr = new int[n];
	size = n;
}
Array_ :: Array_(const Array_ &other) {
	this->size = other.size;
	this->arr = new int[other.size];
	for (int i = 0; i < other.size; i++)
		this->arr[i] = other.arr[i];
}
Array_ :: ~Array_() {
	delete[] arr;
}


void Array_::in_array() {
	cout << "Enter the array:\n";
	for (int i = 0; i < size; i++)
	{
		cout << "The " << i + 1 << " element- ";
		cin >> arr[i];
	}
	cout << endl;
}
void Array_::out_array() {
	for (int i = 0; i < size; i++)
		cout << arr[i] << ' ';
}


int Array_::GetSize() {
	return size;
}
int* Array_::GetArray() {
	return arr;
}



Array_ & Array_::operator=(const Array_ &other){
	this->size = other.size;
	if (this->arr != nullptr)
	{
		delete[] this->arr;
	}
	this->arr = new int[other.size];
	for (int i = 0; i < size; i++)
		this->arr[i] = other.arr[i];
	return *this;
}

Array_ Array_::operator+(const Array_ &other){
	Array_ summa;
	summa.size = this->size;
	if (summa.arr != nullptr)
	{
		delete[] summa.arr;
	}
	summa.arr = new int[this->size];
	for (int i = 0; i < this->size; i++)
	{
		summa.arr[i] = this->arr[i] + other.arr[i];
	}
	return summa;
}

Array_ &Array_::operator-(const Array_ &other){
	for (int i = 0; i < this->size; i++){
		for (int j = 0; j < other.size; j++)
		{
			if (this->arr[i] == other.arr[j])
			{
				for (int z = i; z < this->size - 1; z++)
				{
					this->arr[z] = this->arr[z + 1];
				}
				this->size--;
				i--;
				break;
			}
		}
	}
	return *this;
}

bool Array_::operator==(const Array_ &other){
	int k = 0;
	if (this->size == other.size)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i] != other.arr[i])
				k++;
		}
		if (k == 0)
			return true;
		else return false;
	}
	else
		return false;
}

bool Array_::operator!=(const Array_ &other){
	int k = 0;
	if (this->size == other.size)
	{
		for (int i = 0; i < this->size; i++)
		{
			if (this->arr[i] != other.arr[i])
				k++;
		}
		if (k == 0)
			return false;
		else return true;
	}
	else
		return true;
}

bool Array_::operator>(const Array_ &other){
	int s_1 = 0, s_2 = 0;
	for (int i = 0; i < this->size; i++)
	{
		s_1 += this->arr[i];
		s_2 += other.arr[i];
	}
	return s_1 > s_2;
}

bool Array_::operator<(const Array_ &other){
	int s_1 = 0, s_2 = 0;
	for (int i = 0; i < this->size; i++)
	{
		s_1 += this->arr[i];
		s_2 += other.arr[i];
	}
	return s_1 < s_2;
}

bool Array_::operator>=(const Array_ &other){
	int s_1 = 0, s_2 = 0;
	for (int i = 0; i < this->size; i++)
	{
		s_1 += this->arr[i];
		s_2 += other.arr[i];
	}
	return (s_1 >= s_2);
}

bool Array_::operator<=(const Array_ &other){
	int s_1 = 0, s_2 = 0;
	for (int i = 0; i < this->size; i++)
	{
		s_1 += this->arr[i];
		s_2 += other.arr[i];
	}
	return (s_1 <= s_2);
}

ostream& operator << (ostream &out, const Array_ &obj){
	for (int i = 0; i < obj.size; i++)
		out << obj.arr[i] << " ";
	return out;
}

istream& operator >> (istream &in, Array_ &obj){
	for (int i = 0; i < obj.size; i++)
		in >> obj.arr[i];
	return in;
}