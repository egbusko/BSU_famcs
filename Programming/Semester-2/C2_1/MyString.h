#pragma once
#include <iostream>  
#include <string>
using namespace std;

class String_
{
	string m_stroka;
public:
	String_();
	String_(string str);
	String_(const String_ &other);
	~String_();

	void Add(String_ *str);
	static int Cmp_(String_ *left, String_ *right);

	//int Cmp_Neravenstvo_strok_3(String_ * mas_strok, int i, int j);
	
	void SetStr(string stroka_dlia_vvoda); 
	string GetStr();
	void ShowStr();
};