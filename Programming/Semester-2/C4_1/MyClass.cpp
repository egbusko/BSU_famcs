#include "Header.h"
#include <iostream>
#include <string>


List::List() {
	size = 0;
	head = nullptr;
}


List::List(const List & other)
{
	Node *other_head = other.head;
	while (other_head !=0)
	{
		this->push_back(other_head->name, other_head->surname, other_head->patron, other_head->age);
		other_head = other_head->pNext;
	}
}


List::~List(){
	clear();
}


void List::push_back(string name, string surname, string patron, int age)
{
	if (head == nullptr)
		head = new Node(name, surname, patron, age);
	else
	{
		Node *current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node(name, surname, patron, age);
	}
	size++;
}


void List::push_front(string name, string surname, string patron, int age)
{
	head = new Node(name, surname, patron, age, head);
	size++;
}


void List::pop_front()
{
	Node *temp = head;
	head = head->pNext;
	delete temp;
	size--;
}


void List::pop_back(){
	removeAt(size - 1);
}


void List::insert(string name, string surname, string patron, int age, int index)
{
	if (index == 0)
	{
		push_front(name, surname, patron, age);
	}
	else
	{
		Node *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node *newNode = new Node(name, surname, patron, age, previous->pNext);
		previous->pNext = newNode;

		size++;
	}
}


void List::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		delete toDelete;
		size--;
	}
}

void List::clear()
{
	while (size)
		pop_front();
}

void List::operator[](const int index)
{
	int counter = 0;
	Node *current = this->head;
	while (current != nullptr)
	{
		if (counter == index)
		{
			cout << current->surname << " " << current->name << " "
				<< current->patron << " - " << current->age<<"\n";
		}
		current = current->pNext;
		counter++;
	}
}
