#include <iomanip>
#include <iostream>
#include <fstream>

using namespace std;

struct node 
{
	char dat;
	node *next;
	node *prev;

};

typedef node *pNode;

struct Stack 
{
	pNode head;
	pNode tail;

};


void Push(Stack &st, char x) 
{
	pNode newNode = new node;
	newNode->dat = x;
	newNode->next = st.head;
	newNode->prev = NULL;

	if (st.head)
		st.head->prev = newNode;
	st.head = newNode;

	if (!st.tail) st.tail = st.head;
}

char Pop(Stack &st) 
{
	pNode topNode = st.head;
	char x;

	if (!topNode) return '0';
	x = topNode->dat;

	st.head = topNode->next;

	if (st.head) st.head->prev = NULL;
	else st.tail = NULL;

	delete topNode;
	return x;
}

void Ex1_1() 
{
	char str[500];
	Stack stack;

	stack.head = NULL;

	stack.tail = NULL;

	cout << "Enter a string: ";
	gets_s(str);

	for (int i = 0; i < strlen(str); i++) {

		if (str[i] == '(') Push(stack, ')');

		if (str[i] == '[') Push(stack, ']');

		if (str[i] == '{') Push(stack, '}');


		if (str[i] == ')' || str[i] == ']' || str[i] == '}') {

			if (Pop(stack) != str[i]) {

				cout << "Incorrect Input!!!" << endl;
				return;

			}

		}
	}

	if (stack.head != NULL) {

		cout << "Incorrect Input!!!" << endl;
		return;
	}

	cout << "Correct Input!!!" << endl;
}

///////////////////////////////////////////////////////////////

struct Node 
{
	int data;
	Node *next;
	Node *prev;

};
typedef Node *PNode;

struct Queue 
{
	PNode head;
	PNode tail;
};

bool Pal(int a)
{
	int aa = a, res = 0, count = 0;

	while (aa > 0) 
	{
		res = res * 10 + aa % 10;
		aa /= 10;
		count++;
	}

	if (a == res && count > 1) 
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool Simple(int a) 
{
	if (a == 1 || a == 2 || a == 3) return true;
	else
	{
		for (int i = 2; i < a; i++)
		{
			if (a % i == 0) return false;
		}
		return true;
	}
}

int Pop(Queue &Q)
{
	PNode TopNode = Q.head;
	int x;
	if (!TopNode)
		return 0;
	x = TopNode->data;
	Q.head = TopNode->next;
	if (Q.head) Q.head->prev = NULL;
	else Q.tail = NULL;
	delete TopNode;
	return x;
}

void PushTail(Queue &Q, int x)
{
	PNode NewNode;
	NewNode = new Node;
	NewNode->data = x;
	NewNode->prev = Q.tail;
	NewNode->next = NULL;
	if (Q.tail)
		Q.tail->next = NewNode;
	Q.tail = NewNode;
	if (!Q.head) Q.head = Q.tail;
}

void Ex1_2() {

	ifstream iFile("inp.txt");

	Queue q1;

	q1.head = NULL;
	q1.tail = NULL;

	Queue q2;

	q2.head = NULL;
	q2.tail = NULL;

	Queue q3;

	q3.head = NULL;
	q3.tail = NULL;

	int counter = 0;

	while (!iFile.eof()) {

		int a = 0;
		iFile >> a;

		if (Simple(a) == true) {

			PushTail(q1, a);
			counter++;
		}
		if (Pal(a) == true) {

			PushTail(q2, a);
			counter++;
		}


	}

	int *mas = new int[counter];
	int c = 0, ch = 0;

	while (q1.head != NULL) {

		ch = 0;

		int k = Pop(q1);

		for (int i = 0; i < c; i++) {

			if (k == mas[i]) ch = 1;

		}

		if (ch != 1) {

			PushTail(q3, k);
			mas[c] = k;
			c++;

		}

	}

	while (q2.head != NULL) {

		ch = 0;

		int k = Pop(q2);

		for (int i = 0; i < c; i++) {

			if (k == mas[i]) ch = 1;

		}

		if (ch != 1) {

			PushTail(q3, k);
			mas[c] = k;
			c++;

		}

	}
	while (q3.head != NULL) {

		cout << Pop(q3) << " ";
	}
}



///////////////////////////////////////////////////////////////////////////////

struct Node {
	char *surname = new char[500];
	int group;
	int zachnum;
	double man;
	double geo;
	double prog;

	Node *prev;
	Node *next;
};

typedef Node *PNode;

ofstream oFile("OUT.txt");
ifstream iFile("IN.txt");

PNode head;
PNode tail;

int strok = 0;

void Swap(PNode a, PNode b) {

	PNode NewNode = new Node;

	strcpy(NewNode->surname, a->surname);
	NewNode->group = a->group;
	NewNode->zachnum = a->zachnum;
	NewNode->man = a->man;
	NewNode->geo = a->geo;
	NewNode->prog = a->prog;

	strcpy(a->surname, b->surname);
	a->group = b->group;
	a->zachnum = b->zachnum;
	a->man = b->man;
	a->geo = b->geo;
	a->prog = b->prog;

	strcpy(b->surname, NewNode->surname);
	b->group = NewNode->group;
	b->zachnum = NewNode->zachnum;
	b->man = NewNode->man;
	b->geo = NewNode->geo;
	b->prog = NewNode->prog;

}

void AddNew(char *surn, int group, int zach, int man, int geo, int prog) {

	PNode NewNode = new Node;
	NewNode->prev = tail;
	NewNode->next = NULL;

	strcpy(NewNode->surname, surn);
	NewNode->group = group;
	NewNode->zachnum = zach;
	NewNode->man = man;
	NewNode->geo = geo;
	NewNode->prog = prog;

	if (tail) tail->next = NewNode;
	tail = NewNode;
	if (!head) head = tail;

}

void fUse() {

	if (iFile.eof()) {
		printf("Error!");
	}

	else {

		while (!iFile.eof()) {

			char surn[500];
			int group, zach, man, geo, prog;

			iFile >> surn >> group >> zach >> man >> geo >> prog;

			AddNew(surn, group, zach, man, geo, prog);
			strok++;
		}


	}
}

void middleMark() {

	PNode tmp = head;

	while (tmp != NULL) {

		cout << tmp->surname << " " << (tmp->man + tmp->geo + tmp->prog) / 3 << endl;
		tmp = tmp->next;

	}

}

void absMiddleMark() {

	double ct = 0;

	PNode tmp = head;

	while (tmp != NULL) {

		ct += (tmp->man + tmp->geo + tmp->prog) / 3;
		tmp = tmp->next;

	}

	ct /= strok;

	cout << "Middle ball: " << ct << endl;

}

void listMiddle() {

	for (int j = 0; j < strok; j++) {

		PNode tmp = head;

		while (tmp->next != NULL) {

			if (tmp->group > tmp->next->group) {

				Swap(tmp, tmp->next);

			}

			tmp = tmp->next;

		}

	}

	for (int j = 0; j < strok; j++) {

		PNode tmp = head;

		while (tmp->next != NULL) {

			if (tmp->surname[0] > tmp->next->surname[0] && tmp->group == tmp->next->group) {

				Swap(tmp, tmp->next);

			}

			tmp = tmp->next;

		}

	}

	PNode tmp = head;

	while (tmp != NULL) {

		oFile << tmp->surname << " " << tmp->group << " " << (tmp->man + tmp->geo + tmp->prog) / 3 << endl;

		tmp = tmp->next;

	}

}

void listTop() {

	for (int j = 0; j < strok; j++) {

		PNode tmp = head;

		while (tmp->next != NULL) {

			if (tmp->group > tmp->next->group) {

				Swap(tmp, tmp->next);

			}

			tmp = tmp->next;

		}

	}

	for (int j = 0; j < strok; j++) {

		PNode tmp = head;

		while (tmp->next != NULL) {

			if (tmp->surname[0] > tmp->next->surname[0] && tmp->group == tmp->next->group) {

				Swap(tmp, tmp->next);

			}

			tmp = tmp->next;

		}

	}

	PNode tmp = head;
	if (!oFile.eof()) oFile << endl;

	while (tmp != NULL) {

		if ((tmp->geo == 9 || tmp->geo == 10) && (tmp->man == 9 || tmp->man == 10) && (tmp->prog == 9 || tmp->prog == 10))
			oFile << tmp->surname << " " << tmp->group << " " << tmp->zachnum << endl;

		tmp = tmp->next;

	}

}

void listDown() {

	for (int j = 0; j < strok; j++) {

		PNode tmp = head;

		while (tmp->next != NULL) {

			if (tmp->group > tmp->next->group) {

				Swap(tmp, tmp->next);

			}

			tmp = tmp->next;

		}

	}

	for (int j = 0; j < strok; j++) {

		PNode tmp = head;

		while (tmp->next != NULL) {

			if (tmp->surname[0] > tmp->next->surname[0] && tmp->group == tmp->next->group) {

				Swap(tmp, tmp->next);

			}

			tmp = tmp->next;

		}

	}

	PNode tmp = head;
	if (!oFile.eof()) oFile << endl;

	while (tmp != NULL) {

		if (tmp->geo < 4 || tmp->man < 4 || tmp->prog < 4)
			oFile << tmp->surname << " " << tmp->group << " " << tmp->zachnum << endl;

		tmp = tmp->next;

	}

}

void Ex1_3() {

	head = NULL;
	tail = NULL;

	fUse();
	middleMark();
	absMiddleMark();
	listMiddle();
	listTop();
	listDown();

	iFile.close();
	oFile.close();

}




void main() {

	Ex1_1();
	Ex1_2();
	Ex1_3();

	system("pause");
}