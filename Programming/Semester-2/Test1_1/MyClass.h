#pragma once
#include <iostream>  
using namespace std;

class Weight
{
	int kilos_w;
	int grams_w;
public:
	Weight();
	Weight(int kilos_, int grams_);
	Weight(const Weight &other);
	~Weight();

	void in_weight();
	void out_weight();
	int GetKilos();
	int GetGrams();

	Weight & operator=(const Weight &other);
	Weight  operator + (const Weight &other);
	Weight  operator - (const Weight &other);
	Weight  operator * (double num);
	Weight  operator / (double num);


	bool operator == (const Weight &other);
	bool operator > (const Weight &other);
	bool operator < (const Weight &other);
	bool operator >= (const Weight &other);

	friend ostream &operator << (ostream &s, Weight &obj);
	friend istream &operator >> (istream &s, Weight &obj);
};