#pragma once
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

struct out_of_board {};
struct nenaiden {};


struct EngFr
{
	char EngWord[20];
	char Prepos[10];
	char P;
	char FrWord[20];

	bool operator == (const EngFr &other) {
		if ( (strcmp(this->EngWord, other.EngWord) == 0) && (strcmp(this->FrWord, other.FrWord) == 0) )
			return true;
		else return false;
	}

	friend std::istream &operator>>(std::istream& in, EngFr &S)	{
		in.getline(S.EngWord, 20, '\n');
		in.getline(S.Prepos, 10, '\n');
		in >> S.P;
		in.ignore();
		in.getline(S.FrWord, 20, '\n');
		return in;
	}

	friend std::ostream &operator<<(std::ostream& out, EngFr &S) {
		
		if (S.P == 'S')		{
			if ((S.EngWord[0] == 'a') || (S.EngWord[0] == 'e') || (S.EngWord[0] == 'i') || (S.EngWord[0] == 'o')) {
				out << "an " << S.EngWord << "   ";
			}
			else {
				out << "a " << S.EngWord << "   "; }
		}
		else{
			out<<"to "<< S.EngWord << "   "; }
		
		out << S.Prepos << "   " << S.P << "    ";
		

		if(S.FrWord[(strlen(S.FrWord))-1]=='e')
			out << S.FrWord << " une " << std::endl;
		else
			out << S.FrWord << " un " << std::endl;

		return out;
	}
};



struct FrEng
{
	char FrWord[20];
	char P;
	char EngWord[30];

	bool operator == (const FrEng &other) {
		if ((strcmp(this->FrWord, other.FrWord) == 0) && (strcmp(this->EngWord, other.EngWord) == 0))
			return true;
		else return false;
	}

	friend std::istream &operator>>(std::istream& in, FrEng &S) {
		in.getline(S.FrWord, 20, '\n');
		in >> S.P;
		in.ignore();
		in.getline(S.EngWord, 20, '\n');
		return in;
	}

	friend std::ostream &operator<<(std::ostream& out, FrEng &S) {
		out << S.FrWord << "  " << S.P << "  " << S.EngWord << "-(eng. saying)" << std::endl;
		return out;
	}
};
struct EngCounter
{
	char EngWord[20];
	char P;
	int counter;
	   
	bool operator == (const EngCounter &other) {
		if ((strcmp(this->EngWord, other.EngWord) == 0) && (this->counter==other.counter))
			return true;
		else return false;
	}

	friend std::istream &operator>>(std::istream& in, EngCounter &S) {
		in.getline(S.EngWord, 20, '\n');
		in >> S.P >> S.counter;
		return in;
	}

	friend std::ostream &operator<<(std::ostream& out, EngCounter &S) {
		out << S.EngWord << "  " << S.P << "  " << S.counter << "-(repeting)" << std::endl;
		return out;
	}
};

//
//std::ostream &operator<<(std::ofstream& out, Fan1 &where)
//{
//	out << where.Name << where.country;
//	out << where.birth << where.detention;
//	return out;
//}
//std::istream &operator>>(std::ifstream& in, Fan1 &where)
//{
//	in >> where.Name >> where.country;
//	in.ignore();
//	in >> where.birth >> where.detention;
//	return in;
//}
//
//std::ofstream &operator<<(std::ofstream& out, Fan2 &where)
//{
//	out << where.Name;
//	out << where.passport << where.detention;
//	return out;
//}
//std::ifstream &operator>>(std::ifstream& in, Fan2 &where)
//{
//	in >> where.Name;
//	in.ignore();
//	in >> where.passport >> where.detention;
//	return in;
//}
//
//std::ofstream &operator<<(std::ofstream& out, Fan3 &where)
//{
//	out << where.Name << where.country;
//	out << where.birth << where.passport << where.detention;
//	return out;
//}
//std::ifstream &operator>>(std::ifstream& in, Fan3 &where)
//{
//	in >> where.Name >> where.country;
//	in.ignore();
//	in >> where.birth >> where.passport >> where.detention;
//	return in;
//}


template<class T>
int compare(const void* a, const void* b)
{
	return strcmp(((T*)a)->EngWord, ((T*)b)->EngWord);
}


template<class T>
int compareD(const void* a, const void* b)
{
	return -(strcmp(((T*)a)->Name, ((T*)b)->Name));
}




template<class T>
int compareFind(const void* a, const void* b)
{
	return strcmp(((T*)a)->FrWord, ((T*)b)->FrWord);
}


//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////////////////////////////////////////////////




template<class T>
class TVOC 
{
	int size;
	T *arr;

public:

	TVOC() 	{ 
		size = 0; 
		arr = nullptr;
	}
	TVOC(int s) {
		size = s;
		arr = new T[s];
	}
	TVOC(TVOC& other)	{
		this->size = other.size;
		if (arr)
			delete[] arr;
		this->arr = new T[size];
		for (int i = 0; i < other.size; i++)
			this->arr[i] = other.arr[i];
	}
	~TVOC() {
		size = 0;
		delete[] arr;
	}


	template<typename T>
	friend std::istream& operator>>(std::istream& in, TVOC<T>& S);

	template<typename T> 
	friend std::ostream& operator<<(std::ostream& out, TVOC<T>& S);


	T& operator[](int ind)	{
		if (ind < 0 || ind >= size)
			throw  out_of_board();
		else
			return arr[ind];
	}

	void SetCount(int c)
	{
		size = c;
	}

	int GetCount()	{
		return size;
	}

	void Sort()	{
		qsort(arr, size, sizeof(T), compare<T>);
	}

	void SortD()	{
		int k = 1, i = 0;
		while (arr[i].P == arr[i + 1].P){
			k++;
			i++;
		}
		qsort(arr, k, sizeof(T), compare<T>);
		qsort(arr+k, size-k, sizeof(T), compare<T>);
	}


	//перевод для фр. слов, в первых 2 структурах
	T* FindFra(char Translation[20], ostream &out) {
		TVOC tmp(*this);
		qsort(tmp.arr, tmp.size, sizeof(T), compare<T>);
		T structTmp;
		strcpy_s(structTmp.FrWord, Translation);

		T* t = (T*)bsearch(&structTmp, tmp.arr, tmp.size, sizeof(T), compareFind<T>);
		if (t == NULL)
		{
			throw nenaiden();
		}
		else
		{
			out << *t;
			return t;
		}
	}


	T* FindEng(char Translation[20], ostream &out) {
		TVOC tmp(*this);
		qsort(tmp.arr, tmp.size, sizeof(T), compare<T>);
		T structTmp;
		strcpy_s(structTmp.EngWord, Translation);

		T* t = (T*)bsearch(&structTmp, tmp.arr, tmp.size, sizeof(T), compare<T>);
		if (t == NULL)
		{
			throw nenaiden();
		}
		else
		{
			out << *t;
			return t;
		}
	}
	/*void push_back(Fan1 copy)
	{
		T *copy1 = fan_humans;
		n++;
		fan_humans = new T[n];
		for (int i = 0; i < n - 1; i++)
			fan_humans[i] = copy1[i];
		strcpy(fan_humans[n - 1].Name, copy.Name);
		fan_humans[n - 1].detention = copy.detention;
		fan_humans[n - 1].country = copy.country;
		fan_humans[n - 1].birth = copy.birth;
	}
	void push_back(Fan2 copy)
	{
		T *copy1 = fan_humans;
		n++;
		fan_humans = new T[n];
		for (int i = 0; i < n - 1; i++)
			fan_humans[i] = copy1[i];
		strcpy(fan_humans[n - 1].Name, copy.Name);
		fan_humans[n - 1].detention = copy.detention;
		fan_humans[n - 1].passport = copy.passport;
	}
	void delete_elem(int del)
	{
		for (int i = del; i < n - 1; i++)
		{
			std::swap(fan_humans[i], fan_humans[i + 1]);
		}
		T* copy = new T[n];
		for (int i = 0; i < n; i++)
		{
			copy[i] = fan_humans[i];
		}
		if (fan_humans)
			delete[] fan_humans;
		fan_humans = new T[n - 1];
		n--;
		for (int i = 0; i < n; i++)
		{
			fan_humans[i] = copy[i];
		}
	}*/
};




template<typename T>
std::istream& operator>>(std::istream& in, TVOC<T>& S){
	in >> S.size;
	if (S.arr)
		delete[] S.arr;

	in.ignore();
	
	S.arr = new T[S.size];
	for (int i = 0; i < S.size; i++)	{
		in >> S.arr[i];
	}
	return in;
}



template<typename T>
std::ostream& operator<<(std::ostream& out, TVOC<T>& S){
	for (int i = 0; i < S.size; i++)
		out << S.arr[i];
	return out;
}



//int searchfunc(const void* key, const void* elem)
//{
//	return strcmp((char*)key, ((Fan2*)elem)->Name);
//}
