#include <iostream>
#include <string>
using namespace std;

struct BadIndex {};


class Human
{
	string name;
	string surname;
	string patron;
	int age;

public:
	Human()	{
		name = "Ivan";
		surname = "Petrov";
		patron = "Vladimirovich";
		age = 23;
	}
	Human(string name_2,string surname_2,string patron_2,int age_2) {
		name = name_2;
		surname = surname_2;
		patron = patron_2;
		age = age_2;
	}
	Human(const Human&other) {
		name = other.name;
		surname = other.surname;
		patron = other.patron;
		age = other.age;
	}
	~Human() {}

	Human & operator=(const Human &other)
	{
		this->name = other.name;
		this->surname = other.surname;
		this->patron = other.patron;
		this->age = other.age;
		return *this;
	}

	friend ostream & operator<<(ostream& out, const Human& chel)
	{
		out << chel.surname << " " << chel.name << " " << chel.patron << " " << chel.age << "years\n";
		return out;
	}
};


template <typename T>
class List
{
public:
	List();
	List(List &other);
	~List();

	int GetSize() { return size; }

	void push_back(T data);
	void push_front(T data);
	void pop_front();
	void pop_back();
	void insert(T value, int index);
	void removeAt(int index);
	void clear();
	T& operator[](const int index);

private:

	template <typename T>
	class Node
	{	
	public:

		Node *pNext;
		Node *pPrev;
		T data;
		
		Node(const Node &other)
		{
			this->data = other.data;
		}
		Node(Node *pPrev = tail, T data = T(), Node *pNext = head)   //T() - примитивное значение типа данных
		{
			this->pPrev = pPrev;
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node<T> *head;
	Node<T> *tail;
};



template <typename T>
List<T>::List() {
	size = 0;
	head = nullptr;
	tail = nullptr;
}

template<typename T>
List<T>::List(List<T> & other)
{
	Node<T> *other_head = other.head;
	for(int i=0; i< other.GetSize();i++)
	{
		this->push_back(other_head->data);
		other_head = other_head->pNext;
	}
}

template <typename T>
List<T>::~List()
{
	clear();
}


//+
template <typename T>
void List<T>::push_back(T data)
{
	if (head == nullptr)
	{
		head = new Node<T>(tail, data, head);
		tail = head;
		head->pNext = head;
		head->pPrev = tail;
	}
	else
	{
		tail = new Node<T>(tail, data, head);
		(tail->pPrev)->pNext = tail;
		head->pPrev = tail;
	}
	size++;
}


//+
template<typename T>
void List<T>::push_front(T data)
{
	head = new Node<T>(tail, data, head);
	size++;
	if (size == 1)
	{
		tail = head;
		head->pNext = head;
		head->pPrev = head;
	}
	else
	{
		(head->pNext)->pPrev = head;
		tail->pNext = head;
	}		

}


//+
template<typename T>
void List<T>::pop_front()
{
	Node<T> *temp = head;
	head = head->pNext;
	tail->pNext = head;
	head->pPrev = tail;

	delete temp;
	size--;
}


//+
template<typename T>
void List<T>::pop_back()
{
	removeAt(size - 1);
}


//+
template<typename T>
void List<T>::insert(T value, int index)
{
	if (index == 0)
	{
		push_front(value);
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}

		Node<T> *newNode = new Node<T>(previous, value, previous->pNext);
		previous->pNext = newNode;
		(newNode->pNext)->pPrev = newNode;
		size++;
	}
}


//+
template<typename T>
void List<T>::removeAt(int index)
{
	if (index == 0)
	{
		pop_front();
	}
	else
	{
		Node<T> *previous = this->head;
		for (int i = 0; i < index - 1; i++)
		{
			previous = previous->pNext;
		}
		Node<T> *toDelete = previous->pNext;
		previous->pNext = toDelete->pNext;
		(toDelete->pNext)->pPrev = previous;
		delete toDelete;
		size--;
	}
}


//+
template<typename T>
void List<T>::clear()
{
	while (size)
		pop_front();
}


//+
template<typename T>
T & List<T>::operator[](const int index)
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
void view_the_list(List<T>& L2) {
	for (int i = 0; i < L2.GetSize(); i++)
		L2[i];
}

int exit_program() {
	system("pause");
	exit(0);
}



template<typename T>
void foo_num(List<T>& L2)
{
	int num_cin, push_num, index;
	cout << "Enter element for adding: ";
	cin >> num_cin;
	cout << "  Choose: \n" << "  1____push_front\n"
		<< "  2____insert in index\n"
		<< "  3____push_back\n";
	cout << "  "; cin >> push_num;
	switch (push_num)
	{
	case 1:
		L2.push_front(num_cin);
		cout << "\n";
		break;
	case 2:
		cout << "Enter index for pushing ";
		cin >> index; cout << "\n\n";
		L2.insert(num_cin, index);
		break;
	case 3:
		L2.push_back(num_cin);
		cout << "\n";
		break;
	default:
		cout << "Wrong push_number, calling pushing back\n\n";
		L2.push_back(num_cin);
		break;
	}
}


template<typename T>
void foo_human(List<T>& L2)
{
	string name, surname, patron; int age, push_num, index;
	cout << "Enter name:    ";
	cin >> name;
	cout << "Enter surname: ";
	cin >> surname;
	cout << "Enter patron:  ";
	cin >> patron;
	cout << "Enter age:     ";
	cin >> age;
	Human chelovek(name, surname, patron, age);

	cout << "  Choose: \n" << "  1____push_front\n"
		<< "  2____insert in index\n"
		<< "  3____push_back\n";
	cout << "  "; cin >> push_num;
	switch (push_num)
	{
	case 1:
		L2.push_front(chelovek);
		cout << "\n";
		break;
	case 2:
		cout << "Enter index for pushing ";
		cin >> index; cout << "\n\n";
		L2.insert(chelovek, index);
		break;
	case 3:
		L2.push_back(chelovek);
		cout << "\n";
		break;
	default:
		cout << "Wrong push_number, calling pushing back\n\n";
		L2.push_back(chelovek);
		break;
	}
}


template<typename T>
void menu_list_num(List<T>& L2)
{
	string name, surname, patron;
	//int age, push_num
		int index, number, pop_num, type_num;
	//int num_cin;
	//Human chelovek;
	cout << "\tView the list ---------- 1\n"
		<< "\tAdd the element -------- 2\n"
		<< "\tDelete the element ----- 3\n"
		<< "\tExit ------------------- 0\n";
	cout << "\tENTER THE NUMBER: ";
	cin >> number; //cout << endl;


	switch (number)
	{
	case 1:
		/*if (L2.GetSize() == 0)
		{
			cout << "The List is empty\n";
		}
		else
		{*/
		for (int i = 0; i < L2.GetSize(); i++)
			cout << L2[i] << " ";
			cout << endl;
		//}
		break;
	case 2:
		foo_num(L2);
		break;

	case 3:
		cout << "  Choose: \n" << "  1____pop_front\n"
			 << "  2____removeAt in index\n"
			 << "  3____pop_back\n";
		cout << "  ";  cin >> pop_num;
		switch (pop_num)
		{
		case 1:
			L2.pop_front();
			break;
		case 2:
			cout << "Enter index for poping ";
			cin >> index; cout << endl;
			L2.removeAt(index);
			break;
		case 3:
			L2.pop_back();
			break;
		default:
			cout << "Wrong pop_number, calling poping back\n\n";
			L2.pop_back();
			break;
		}
		break;
	case 0:
		exit_program();
		break;
	default:
		cout << "!!  Wrong number  !!\n"
			<< " REenter the number \n\n";
		break;
	}
}


template<typename T>
void menu_list_human(List<T>& L2)
{
	string name, surname, patron;
	int age, push_num;
	int index, number, pop_num, type_num;
	int num_cin;
	Human chelovek;
	cout << "\tView the list ---------- 1\n"
		<< "\tAdd the element -------- 2\n"
		<< "\tDelete the element ----- 3\n"
		<< "\tExit ------------------- 0\n";
	cout << "\tENTER THE NUMBER: ";
	cin >> number; //cout << endl;


	switch (number)
	{
	case 1:
		/*if (L2.GetSize() == 0)
		{
			cout << "The List is empty\n";
		}
		else
		{*/
		for (int i = 0; i < L2.GetSize(); i++)
			cout << L2[i];
		cout << endl;
		//}
		break;
	case 2:

		foo_human(L2);
		break;

	case 3:
		cout << "  Choose: \n" << "  1____pop_front\n"
			<< "  2____removeAt in index\n"
			<< "  3____pop_back\n";
		cout << "  ";  cin >> pop_num;
		switch (pop_num)
		{
		case 1:
			L2.pop_front();
			break;
		case 2:
			cout << "Enter index for poping ";
			cin >> index; cout << endl;
			L2.removeAt(index);
			break;
		case 3:
			L2.pop_back();
			break;
		default:
			cout << "Wrong pop_number, calling poping back\n\n";
			L2.pop_back();
			break;
		}
		break;
	case 0:
		exit_program();
		break;
	default:
		cout << "!!  Wrong number  !!\n"
			<< " REenter the number \n\n";
		break;
	}
}

int main()
{
	int type_of_date;
	cout << "Number(1) or Your_type(2)\n";
	cin >> type_of_date;
	
	if (type_of_date == 1)
	{
		List < int> list;
		int counter = 20;
		while (counter)
		{
			counter--;
			menu_list_num(list);
		}
	}
	else if (type_of_date==2)
	{
		List<Human> list;
		int counter = 20;
		while (counter)
		{
			counter--;
			menu_list_human(list);
		}
	}
	

	



	List < int> lst;
	List<int> lst_2(lst);
	for (int i = 0; i < lst_2.GetSize(); i++)
		cout << lst_2[i] << endl;
	cout << endl;
	
		/*for (int i = 0; i < lst.GetSize(); i++)
			cout << lst[i] << endl;
		cout << endl;*/

		int numbers_count;
		cin >> numbers_count;
		cout << endl;
		for (int i = 0; i < numbers_count; i++)
			lst.push_back(rand()%10);

	int cin_index;
	cout << "\nEnter the index: ";
	cin >> cin_index;
	try
	{
		cout << "The " << cin_index << "-st element = " << lst[cin_index] << endl;
	}
	catch (BadIndex)
	{
		cout << "----Bad index, check it----\n\n";
	}


	system("pause");
	return 0;
}