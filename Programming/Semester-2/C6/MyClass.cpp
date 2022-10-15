#include "MyClass.h"
#include <iostream>
#include <string>
using namespace std;


Human_::Human_() {
	name = "Ivan";
	surname = "Petrov";
	patron = "Vladimirovich";
	age = 23;
}

Human_::Human_(string name_2, string surname_2, string patron_2, int age_2) {
	name = name_2;
	surname = surname_2;
	patron = patron_2;
	age = age_2;
}

Human_ ::Human_(const Human_ & other){
	name = other.name;
	surname = other.surname;
	patron = other.patron;
	age = other.age;
}

Human_ & Human_ :: operator=(const Human_ &other){
	this->name = other.name;
	this->surname = other.surname;
	this->patron = other.patron;
	this->age = other.age;
	return *this;
}

ostream & operator<<(ostream& out, const Human_& chel){
	out << "- " << chel.surname << " " << chel.name << " " 
		<< chel.patron << "   " << chel.age << "years\n";
	return out;
}