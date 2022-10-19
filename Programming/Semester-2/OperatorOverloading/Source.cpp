#include <iostream>  
#include <string>
	//#include "MyString.h"
using namespace std;

class Mnogestvo
{
	int str_[1000];
public:
	
	friend ostream & operator<<(ostream &output, const Stroki &D)
	{
		for (int i = 0; i < 1000; i++)
		{
			if (D.a[i]!='\0')
				out << D.str_[i] << "";
		}
		return output;
	}
	friend istream & operator>>(istream &input, Stroki &D)
	{
		int i = 0;
		do
		{
			input >> D.str_[i];
			i++;
		} while (D.str_[i]='\0');
		return input;			
	}
	Stroki operator+(const Stroki &D)
	{
		Stroki b;
		int i, n = 0;
		do
		{
			b.str_[i] = str_[i];
			i++;
		} while (str_[i] != '\0');

		do {
			b.str_[i] = D.str_[i];
			i++;
			n++;
		} while (D.str_[n]) != '\0');

		b.a[i] = '\0';
		return b;
	}
};




int main()
{

}