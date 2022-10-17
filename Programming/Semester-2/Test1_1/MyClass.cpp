#include "MyClass.h"
#include <iostream>


Weight::Weight() {
	kilos_w = 50;
	grams_w = 000;
}
Weight::Weight(int kilo_,int grams_) {
	kilos_w = kilo_;
	grams_w = grams_;
}
Weight::Weight(const Weight &other) {
	kilos_w = other.kilos_w;
	grams_w = other.grams_w;
}
Weight :: ~Weight() { }


void Weight::in_weight() {
	cout << "Enter kilos: ";
	cin >> kilos_w;
	cout << "Enter grams: ";
	cin >> grams_w;
}
void Weight::out_weight() {
	cout << kilos_w << "," << grams_w << endl;
}


int Weight::GetKilos() {
	return kilos_w;
}
int Weight::GetGrams() {
	return grams_w;
}



Weight & Weight::operator=(const Weight &other) {
	this->kilos_w = other.kilos_w;
	this->grams_w = other.grams_w;
	return *this;
}

Weight Weight::operator+(const Weight &other) {
	Weight summa;
	summa.kilos_w = this->kilos_w + other.kilos_w;
	summa.grams_w = this->grams_w + other.grams_w;

	while (summa.grams_w >= 1000)
	{
		summa.grams_w -= 1000;
		summa.kilos_w += 1;
	}
	return summa;
}

Weight Weight::operator-(const Weight &other) {
	Weight raznost;
	int t_gr, oth_gr;
	t_gr = this->grams_w;
	oth_gr = other.grams_w;

	raznost.kilos_w = this->kilos_w - other.kilos_w;

	if (this->grams_w >= other.grams_w)
		raznost.grams_w = this->grams_w - other.grams_w;
	else
	{
		while (t_gr < oth_gr)
		{
			raznost.kilos_w -= 1;
			t_gr += 1000;
		}
		raznost.grams_w = t_gr - oth_gr;
	}
	
	return raznost;
}

Weight Weight::operator*(double num)
{
	Weight multipl;
	double w_num = this->kilos_w + (this->grams_w)*0.001;
	w_num *= num;

	multipl.kilos_w = (w_num * 1000)/1000;
	multipl.grams_w = (w_num * 1000) - multipl.kilos_w*1000;
	return multipl;
}

Weight Weight::operator/(double num)
{
	Weight div;
	double w_num = this->kilos_w + (this->grams_w)*0.001;
	w_num /= num;

	div.kilos_w = (w_num * 1000) / 1000;
	div.grams_w = (w_num * 1000) - div.kilos_w*1000;
	return div;
}

bool Weight::operator==(const Weight &other) {
	int k = 0;
	if ((this->kilos_w == other.kilos_w)&&(this->grams_w == other.grams_w))
		return true;
	else
		return false;
}



bool Weight::operator>(const Weight &other) {

	if (this->kilos_w > other.kilos_w)
		return true;
	else if ((this->kilos_w == other.kilos_w) && (this->grams_w > other.grams_w))
		return true;
	else
		return false;
}

bool Weight::operator<(const Weight &other) {
	if (this->kilos_w < other.kilos_w)
		return true;
	else if ((this->kilos_w == other.kilos_w) && (this->grams_w < other.grams_w))
		return true;
	else
		return false;
}

bool Weight::operator>=(const Weight &other) {
	if (this->kilos_w > other.kilos_w)
		return true;
	else if ((this->kilos_w == other.kilos_w) && (this->grams_w >= other.grams_w))
		return true;
	else
		return false;
}


ostream& operator << (ostream &out,  Weight &obj) {
	out << obj.GetKilos() << "," << obj.GetGrams();
	return out;
}

istream& operator >> (istream &in, Weight &obj) {
	in >> obj.kilos_w;
	in >> obj.grams_w;
	return in;
}