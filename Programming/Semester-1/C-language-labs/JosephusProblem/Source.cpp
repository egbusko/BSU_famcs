#include <iostream>	
#include <fstream>	
#include <cstring>	
#include <list>
using namespace std;



int main()
{
	list<int> queue;
	int n, m;
	cout << "Enter a number of people: " << endl;
	cin >> n;

	for (int i = 0; i < n; i++)
		queue.push_back(i);

	cout << "Enter a number of deleted person: " << endl;
	cin >> m;


	int pos = -1;
	auto it = queue.begin();


	while (queue.size() != 1)
	{
		if (pos == m - 1)
		{
			it = queue.erase(it);
			if (it == queue.end())
				it = queue.begin();

			pos = 0;
		}

		pos++;
		it++;

		if (it == queue.end()) {
			it = queue.begin();
		}
	}

	cout << queue.front() << endl;
	
	system("pause");
	return 0;
}



//struct node
//{
//	int item;
//	node* next;
//};
//typedef node * link;
//
//int main()
//{
//	int i, n, m;
//	cout << "Enter a number of people: " << endl;
//	cin >> n;
//	cout << "Enter a number of deleted person: " << endl;
//	cin >> m;
//	link t = new node;
//	t->item = 1;
//	t->next = t;
//	link x = t;
//	for (i = 2; i <= n; i++)
//	{
//		x = (x->next = new node);
//		x->item = i;
//		x->next = t;
//	}
//	while (x != x -> next)
//	{
//		for (i = 1; i < m; i++)
//			x = x->next;
//		x->next = x->next->next;
//	}
//	cout << "Number " << x->item << " becomes the    person#1" << endl;
//	cout << endl << endl;
//	system("pause");
//	return 0;
//}