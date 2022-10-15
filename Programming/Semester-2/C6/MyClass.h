#pragma once
#include <iostream>
#include <string>
using namespace std;

class Human_
{
	string name;
	string surname;
	string patron;
	int age;

public:
	Human_();
	Human_(string name_2, string surname_2, string patron_2, int age_2);
	Human_(const Human_&other);
	~Human_() {}
	Human_ & operator=(const Human_ &other);
	friend ostream & operator<<(ostream& out, const Human_& chel);
};




	class Lot
	{
	public:
		virtual void Printing() = 0;
		virtual void ReversePrinting() = 0;

	};



class Int_num : public Lot
{
	int size;
	int mas[5];

public:
	Int_num()	{
		size = 5;
		for (int i = 0; i < size; i++)
			mas[i] = i + 1;
	}

	void Printing() override	{
		for (int i = 0; i < size; i++)
			cout << mas[i] << "  ";
		cout << endl;
	}
	void ReversePrinting() override {
		for (int i = size-1; i >= 0; i--)
			cout << mas[i] << "  ";
		cout << endl;
	}
};


class Doub_num :public Lot
{
	int size;
	double mas[3];

public:
	Doub_num()	{
		size = 3;
		for (int i = 0; i < size; i++)
			mas[i] = i + 1.5;
	}

	void Printing() override	{
		for (int i = 0; i < size; i++)
			cout << mas[i] << "  ";
		cout << endl;
	}
	void ReversePrinting() override {
		for (int i = size - 1; i >= 0; i--)
			cout << mas[i] << "  ";
		cout << endl;
	}
};


class Strings :public Lot
{
	string stroka;
public:
	Strings()
	{
		stroka = "Hi, world";
	}
	void Printing() override	{
		cout << stroka << endl;
	}
	void ReversePrinting() override 	{	}
};


class Chel :public Lot
{
	Human_ cheloveki[3];
	int num;
public:
	Chel()
	{
		num = 3;
	}
	void Printing() override
	{
		for (int i = 0; i < num; i++)
			cout << cheloveki[i];
	}
	void ReversePrinting() override 	{	}
};





	class Using_Lot
	{
	public:
		void UseIt(Lot *lot)
		{
			lot->Printing();
			lot->ReversePrinting();
			cout << endl;
		}

	};