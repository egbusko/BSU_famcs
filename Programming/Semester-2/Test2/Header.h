#pragma once
#include <iostream>
#include <string>
using namespace std;


struct BadIndex {};


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
class Deque
{
public:
	Deque();
	Deque(Deque &other);
	~Deque();

	int GetSize() { return size; }

	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void pop_back();
	void clear();
	T& operator[](const int index);


	virtual void Union(Deque &dq2) = 0;
	virtual void Copy(Deque &dq2) = 0;





	template <typename T>
	class Node
	{
	public:
		Node *pNext;
		T data;

		Node(const Node &other)
		{
			this->data = other.data;
		}
		Node(T data = T(), Node *pNext = nullptr)   //T() - примитивное значение типа данных
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node<T> *head;
	Node<T> *tail;
};

template <typename T>
Deque<T>::Deque() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
Deque<T>::Deque(Deque<T> & other)
{
	Node<T> *other_head = other.head;
	for (int i = 0; i < other.GetSize(); i++)
	{
		this->push_back(other_head->data);
		other_head = other_head->pNext;
	}
}

template <typename T>
Deque<T>::~Deque() { clear(); }


//+
template <typename T>
void Deque<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(data, nullptr);
		tail = head;
	}
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data, nullptr);
		tail = current->pNext;
	}
	tail->pNext = nullptr;
	size++;
}


//+
template<typename T>
void Deque<T>::push_front(T data)
{
	head = new Node<T>(data, head);
	size++;
	if (size == 1)
	{
		tail = head;
		tail->pNext = nullptr;
	}
	else
	{
		tail->pNext = nullptr;
	}

}


//+
template<typename T>
void Deque<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	delete temp;
	size--;
}


//+
template<typename T>
void Deque<T>::pop_back()
{
	Node<T> *previous = this->head;
	for (int i = 0; i < size - 2; i++)
	{
		previous = previous->pNext;
	}
	Node<T> *toDelete = previous->pNext;
	previous->pNext = nullptr;
	delete toDelete;
	size--;
}


//+
template<typename T>
void Deque<T>::clear()
{
	while (size)
		pop_front();
}


//+
template<typename T>
T & Deque<T>::operator[](const int index)
{
	if (index < 0 || index >= size)
		throw BadIndex();

	int counter = 0;
	Node<T> *current = this->head;
	for (int i = 0; i < size; i++)
	{
		if (counter == index)
			return current->data;
		current = current->pNext;
		counter++;
	}
}



template<typename T>
void view_the_list(Deque<T>& L2) {
	for (int i = 0; i < L2.GetSize(); i++)
		cout << L2[i]<<" ";
	cout << endl;
}





template <typename T>
class Int_deque : public Deque<int>
{

public:

	void Union(Deque &other) {
		Node<T> *other_head = other.head;
		for (int i = 0; i < other.GetSize(); i++)
		{
			this->push_back(other_head->data);
			other_head = other_head->pNext;
		}
	}

	void Copy(Deque &other) {
		clear();
		//this->size = other.size;
		Node<T> *other_head = other.head;
		for (int i = 0; i < other.GetSize(); i++)
		{
			this->push_back(other_head->data);
			other_head = other_head->pNext;
		}
	}

};




template <typename T>
class Str_deque :public Deque<string>
{
public:

	void Union(Deque &other) {
		Node<T> *other_head = other.head;
		for (int i = 0; i < other.GetSize(); i++)
		{
			this->push_back(other_head->data);
			other_head = other_head->pNext;
		}
	}


	void Copy(Deque &other) {
		clear();
		Node<T> *other_head = other.head;
		for (int i = 0; i < other.GetSize(); i++)
		{
			this->push_back(other_head->data);
			other_head = other_head->pNext;
		}
	}

};