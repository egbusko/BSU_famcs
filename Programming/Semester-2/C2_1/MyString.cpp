#include "MyString.h"

String_::String_() {
	m_stroka = "Nothing";
	cout << "Конструктор " << (long)this <<endl;
}
String_::String_(string str) {
	m_stroka = str;
	cout << "Конструктор " << (long)this << endl;
}
String_::String_(const String_ &other) {
	cout << "Конструктор копирования " << (long)this << endl;
	this->m_stroka = other.m_stroka;
}

String_::~String_(){
	
	cout << "Деструктор "<< (long)this <<endl;

}

void String_ ::Add(String_ *add_str){
	m_stroka = m_stroka + "_" + add_str->GetStr();
}

int String_ :: Cmp_(String_ *left, String_ *right){
	string l_perem = left->GetStr();
	string r_perem = right->GetStr();

	if (l_perem > r_perem)
		return 1;
	else
		if (l_perem == r_perem)
			return 0;
		else
			return - 1;
}

void String_ :: SetStr(string stroka_dlia_vvoda) {
	m_stroka = stroka_dlia_vvoda;
}
string String_::GetStr() {	
	return m_stroka;
}
void String_ :: ShowStr() {
	cout << m_stroka << endl;
}