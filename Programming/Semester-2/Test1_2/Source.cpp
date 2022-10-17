#include <iostream>
#include <string>
using namespace std;

struct BadIndex {};

template <typename T>
class List
{
public:
	List();
	List(List &other);
	~List();

	int GetSize() { return size; }

	void push_back(T data);
	void pop_back();
	void clear();
	T& operator[](const int index);
	void operator=(List &other);
	void  operator + (List &other);


private:

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
		Node(T data = T(), Node *pNext = nullptr)
		{
			this->data = data;
			this->pNext = pNext;
		}
	};
	int size;
	Node<T> *head;
};



template <typename T>
List<T>::List() {
	size = 0;
	head = nullptr;
}

template<typename T>
List<T>::List(List<T> & other)
{
	size = other.size;
	Node<T> *other_head = other.head;
	for (int i = 0; i < other.GetSize(); i++)
	{
		this->push_back(other_head->data);
		other_head = other_head->pNext;
	}
}


//+
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
		head = new Node<T>(data, head);
	else
	{
		Node<T> *current = this->head;
		while (current->pNext != nullptr)
		{
			current = current->pNext;
		}
		current->pNext = new Node<T>(data);
	}
	size++;
}


//+
template<typename T>
void List<T>::pop_back()
{
	if (size == 1)
		head = nullptr;
	else 	{
		Node<T> *previous = this->head;
		Node<T> *previous2 = this->head;

		while (previous->pNext != nullptr)
			previous = previous->pNext;
		Node<T> *toDelete = previous;
		delete toDelete;
		for (int i = 0; i < size - 2; i++)
			previous2 = previous2->pNext;
		previous2->pNext = nullptr;
	}	size--;
}



//+
template<typename T>
void List<T>::clear()
{
	while (size)
		pop_back();
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

//+
template<typename T>
void List<T>::operator=(List<T> & other)
{
	clear();
	Node<T> *other_head = other.head;
	for (int i = 0; i < other.GetSize(); i++)
	{
		this->push_back(other_head->data);
		other_head = other_head->pNext;
	}
}

//+
template<typename T>
void List<T>::operator+(List<T> & other)
{
	Node<T> *other_head = other.head;
	for (int i = 0; i < other.GetSize(); i++)
	{
		//size++;
		this->push_back(other_head->data);
		other_head = other_head->pNext;
	}
}


//+
template<typename T>
void view_the_list(List<T>& L2) {
	for (int i = 0; i < L2.GetSize(); i++)
		L2[i];
}

int exit_program() {
	system("pause");
	exit(0);
}





//+
template<typename T>
void foo_num(List<T>& L2)
{
	int num_cin;
	cout << "Enter element for adding: ";
	cin >> num_cin;
	
	L2.push_back(num_cin);
		cout << "\n";
}

//+
template<typename T>
void foo_str(List<T>& L2)
{
	string str_cin;
	cout << "Enter str for adding: ";
	cin >> str_cin;

	L2.push_back(str_cin);
	cout << "\n";
}


template<typename T>
void menu_list_num(List<T>& L2)
{
	int number;
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
		L2.pop_back();
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
void menu_list_str(List<T>& L2)
{
	int number;
	cout << "\n\tView the list ---------- 1\n"
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
			cout << L2[i]<<" ";
		cout << endl;
		//}
		break;
	case 2:
		foo_str(L2);
		break;
	case 3:
		L2.pop_back();
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
	/*int type_of_date;
	cout << "Enter Number(1) or String(2) type\n";
	cin >> type_of_date;

	if (type_of_date == 1)
	{
		List <int> list;
		int counter = 20;
		while (counter)
		{
			counter--;
			menu_list_num(list);
		}
	}
	else if (type_of_date == 2)
	{
		List<string> list;
		int counter = 20;
		while (counter)
		{
			counter--;
			menu_list_str(list);
		}
	}*/


//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////  + и =  ///////////////////////////////////////////////////////////////////////////

	List<int> listik_1;
	listik_1.push_back(11);
	listik_1.push_back(22);
	listik_1.push_back(33);

	List<int> listik_2;
	listik_2.push_back(44);
	listik_2.push_back(55);
	listik_2.push_back(66);

	List<int> listik_3;
	listik_3.push_back(77);
	listik_3.push_back(88);
	listik_3.push_back(99);
	

	listik_1 + listik_2;
	for (int i = 0; i < listik_1.GetSize(); i++)
		cout << listik_1[i] << endl;
	cout << endl;



	listik_3 = listik_2;
	for (int i = 0; i < listik_3.GetSize(); i++)
		cout << listik_3[i] << endl;
	cout << endl;


//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////   Исключения и конструктор копирнования  //////////////////////////////////////////
	//List <int> lst;
	//List<int> lst_2(lst);
	//for (int i = 0; i < lst_2.GetSize(); i++)
	//	cout << lst_2[i] << endl;
	//cout << endl;
	///*for (int i = 0; i < lst.GetSize(); i++)
	//	cout << lst[i] << endl;
	//cout << endl;*/
	//int numbers_count;
	//cin >> numbers_count;
	//cout << endl;
	//for (int i = 0; i < numbers_count; i++)
	//	lst.push_back(rand() % 10);

	//int cin_index;
	//cout << "\nEnter the index: ";
	//cin >> cin_index;
	//try
	//{
	//	cout << "The " << cin_index << "-st element = " << lst[cin_index] << endl;
	//}
	//catch (BadIndex)
	//{
	//	cout << "----Bad index, check it----\n\n";
	//}
//////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////


	system("pause");
	return 0;
}