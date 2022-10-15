#include <iostream>
#include <string>
#include "Header.h"
using namespace std;


void view_the_list(List& L2){
	for (int i = 0; i < L2.GetSize(); i++)
		L2[i];
}

int exit_program(){
	system("pause");
	exit(0);
}


void menu_list(List& L2)
{		
	string name, surname, patron;
	int age, index, number, push_num, pop_num;
	cout << "\tView the list ---------- 1\n" 
		 << "\tAdd the element -------- 2\n"
		 << "\tDelete the element ----- 3\n" 
		 << "\tExit ------------------- 0\n";
	cout << "\tENTER THE NUMBER: ";
	cin >> number; //cout << endl;


	switch (number)
	{
	case 1:
		for (int i = 0; i < L2.GetSize(); i++)
			L2[i];
		cout << endl;
		break;
	case 2:
		cout << "Enter name:    ";
		cin >> name;
		cout << "Enter surname: ";
		cin >> surname;
		cout << "Enter patron:  ";
		cin >> patron;
		cout << "Enter age:     ";
		cin >> age;

		cout << "  Choose: \n" << "  1____push_front\n"
							   << "  2____insert in index\n"
							   << "  3____push_back\n";
		cout << "  "; cin >> push_num;
		switch (push_num)
		{
		case 1:
			L2.push_front(name, surname, patron, age);
			cout << "\n";
			break;
		case 2:
			cout << "Enter index for pushing ";
			cin >> index; cout << "\n\n";
			L2.insert(name, surname, patron, age, index);
			break;
		case 3:
			L2.push_back(name, surname, patron, age);
			cout << "\n";
			break;
		default:
			cout << "Wrong push_number, calling pushing back\n\n";
			L2.push_back(name, surname, patron, age);
			break;
		}
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
	cout << "**********  List of students  **********\n\n";
	List lst;
	
	int counter = 20;
	while (counter)
	{
		counter--;
		menu_list(lst);	
	}
	

	cout << "\n";
	List lst2(lst);
	cout << "OTHER LIST: \n";
	for (int i = 0; i < lst2.GetSize(); i++)
	{
		lst2[i];
	}
	system("pause");
	return 0;
}