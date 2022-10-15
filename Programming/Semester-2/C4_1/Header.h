#pragma once
#include <iostream>  
#include <string>
using namespace std;


class List
{
public:
	List();
	List(const List &other);
	~List();
	int GetSize() { return size; }

	void push_back(string name, string surname, string patron, int age);
	void push_front(string name, string surname, string patron, int age);
	void pop_front();
	void pop_back();
	void insert(string name, string surname, string patron, int age, int index);
	void removeAt(int index);
	void clear();
	void operator[](const int index);

private:

	class Node
	{
	public:
		Node *pNext;

		string name;
		string surname;
		string patron;
		int age;

		Node(const Node &other)
		{
			this->name = other.name;
			this->surname = other.surname;
			this->patron = other.patron;
			this->age = other.age;
		}

		Node(string name = "Ivan", string surname = "Petrov", string patron = "Vladimirovich", int age = 23, Node *pNext = nullptr)	
		{
			this->name = name;
			this->surname = surname;
			this->patron = patron;
			this->age = age;
			this->pNext = pNext;
		}
	};
	int size;
	Node* head;
};