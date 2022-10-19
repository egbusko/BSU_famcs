#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <windows.h>

using namespace std;


//кол-во строк в файле
/*
int AmountOfRows(string filename) {
	ifstream in(filename);
	int amount = 0;
	string c;
	while (getline(in, c)) {
		amount++;
	}
	in.close();
	return amount;
}
*/

//функция стравнения без шаблонов
/*
int compPri(const void * elem1, const void * elem2) {
	structPrice* st1 = (structPrice*)elem1, *st2 = (structPrice*)elem2;
	
	if(strcmp(st1->Name, st2->Name) ==0)
		return 0;
	else if (strcmp(st1->Name, st2->Name) > 1)
		return 1;
	else 
		return -1;
}*/



struct nenaiden {};




struct structMed {
	char Name[35];
	char myDate[8];
	char Section[10];
	int Count;

	char* operator[](const int index) {
		return Name;
	}

	bool operator == (const structMed &other) {
		if (strcmp(this->Name, other.Name) == 0)
				return true;
		else return false;
	}
	
	friend istream& operator >>(istream&in, structMed&S) {
		in.getline(S.Name, 35, '\n');
		in >> S.myDate >> S.Section >> S.Count;
		return in;
	}
	friend ostream& operator <<(ostream&out, const structMed&S) {
		out << S.Name << " " << S.myDate << " " << S.Section << " " << S.Count << endl;
		return out;
	}
};



struct structPrice {
	char Name[35];
	double Price;

	char* operator[](const int index)	{
		return Name;
	}

	bool operator == (const structPrice &other) {
		if (strcmp(this->Name, other.Name) == 0)
			return true;
		else return false;
	}

	friend istream& operator >>(istream&in, structPrice&S) {
		in.getline(S.Name, 35, '\n');
		in >> S.Price;
		return in;
	}
	friend ostream& operator <<(ostream&out, const structPrice&S) {
		out << S.Name << " "  << S.Price << endl;
		return out;
	}
};



struct structMed_Price {
	char Name[35];
	char myDate[8];
	char Section[10];
	double Price;
	int Count;

	char* operator[](const int index) {
		return Name;
	}

	bool operator == (const structMed_Price &other) {
		if (strcmp(this->Name, other.Name) == 0)
			return true;
		else return false;
	}

	friend istream& operator >>(istream&in, structMed_Price&S) {
		in.getline(S.Name, 35, '\n');
		in >> S.myDate >> S.Section >> S.Price >> S.Count;
		return in;
	}
	friend ostream& operator <<(ostream&out, const structMed_Price&S) {
		out << S.Name << " " << S.myDate << " " << S.Section << " " << S.Count << " " << S.Price << endl;
		return out;
	}
};




template <class T>
int comp(const void * elem1, const void * elem2) {
	T*el1 = (T*)elem1, *el2 = (T*)elem2;
	return strcmp(el1->Name, el2->Name);
}

template <class T>
int compReverse(const void * elem1, const void * elem2) {
	T*el1 = (T*)elem1, *el2 = (T*)elem2;
	return strcmp(el2->Name, el1->Name);
}


//template <class T>
//int comp(const void * elem1, const void * elem2) {
//	T*el1 = (T*)elem1, *el2 = (T*)elem2;
//
//	if (strcmp(el1->Name, el2->Name) == 0)
//		return 0;
//	else if (strcmp(el1->Name, el2->Name) > 1)
//		return -1;
//	else
//		return 1;
//}
//


//template <class T>
//int compReverse(const void * elem1, const void * elem2) {
//	T*el1 = (T*)elem1, *el2 = (T*)elem2;
//
//	if (strcmp(el1->Name, el2->Name) == 0)
//		return 0;
//	else if (strcmp(el1->Name, el2->Name) > 1)
//		return 1;
//	else
//		return -1;
//}



////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////





class Medcine
{
public:
	virtual void In(istream& stream) = 0;
	virtual void Out(ostream& stream) = 0;
	virtual void Sort() = 0;
	virtual void SortDown() = 0;

	/*virtual void Printing() = 0;
	virtual void PrintArr() = 0;
	virtual void Union() = 0;
	virtual void intersection() = 0;
	virtual void symrazn() = 0;*/
};



class Med : public Medcine
{
	int size;
	structMed* Mas;
public:
	Med() {
		size = 0;
		Mas = nullptr;
	}
	Med(int tSize) {
		size = tSize;
		Mas = new structMed[size];
	}
	Med(Med & other) {
		size = other.size;
		Mas = new structMed[size];
		for (int i = 0; i < size; i++)
			Mas[i] = other.Mas[i];
	}
	~Med() {
		delete[]Mas;
	}
	int GetSize() { return size; }
	structMed *GetArray() { return Mas; }

	
	void In(istream& stream)
	{
		stream >> size;
		Mas = new structMed[size];

		for (int i = 0; i < size; i++) {
			stream.ignore();
			stream >> Mas[i];
		}
	}

	void Out(ostream& stream) {
		for (int i = 0; i < size; i++)
		{
			cout << Mas[i];
			stream << Mas[i];
		}

	}

	void Sort() override {
		qsort(Mas, size, sizeof(structMed), comp<structMed>);
	}

	void SortDown() override {
		qsort(Mas, size, sizeof(structMed), compReverse<structMed>);
	}

	void CmpFunc() {
		if (Mas[0] == Mas[1])
			cout << endl << "YYEEAH" << endl;
		else
			cout << "POP" << endl;
	}

	structMed* poiskstudent(char name2[35], ostream &out) {
		Med T(*this);
		qsort(T.Mas, T.size, sizeof(structMed), comp<structMed>);
		structMed K;
		strcpy_s(K.Name, name2);

		structMed* t = (structMed*)bsearch(&K, T.Mas, T.size, sizeof(structMed), comp<structMed>);
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

	/*CString createstr()
	{
		CString res;
		for (int i = 0; i < count; i++) {
			CString a;
			a.Format(("%s"), Mas[i].Name);
			res += a;
			res += "\r\t";
			a.Format(("%s"), Mas[i].myDate);
			res += a;
			res += "\r\t";
			a.Format(("%s"), Mas[i].Section);
			res += a;
			res += "\r\t";
			a.Format(("%d"), Mas[i].Count);
			res += a;
			res += "\r\n";
		}
		return res;
	}*/






	/*void Printing() override {
		for (int i = 0; i < size; i++)
			cout << arr[i] << "  ";
		cout << endl;

		for (int i = 0; i < size2; i++)
			cout << arr2[i] << "  ";
		cout << endl;
	}*/

	/*void PrintArr() override {
		for (int i = 0; i < size_3; i++)
			cout << arr_3[i] << "  ";
		cout << endl;
	}*/

	/*void Union() {
		delete[]arr_3;
		size_3 = size + size2;
		arr_3 = new T[size_3];
		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2, size2, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while ((i < size) && (j < size2))
		{
			if (arr[i] < arr2[j])
				arr_3[k++] = arr[i++];
			else
			{
				if (arr[i] > arr2[j])
					arr_3[k++] = arr2[j++];
				else
				{
					arr_3[k++] = arr[i++];
					j++;
					size_3--;
				}
			}
		}

		while (i < size)
		{
			arr_3[k++] = arr[i++];
		}

		while (j < size2)
		{
			arr_3[k++] = arr2[j++];
		}
	}*/

	/*void intersection() override {
		delete[]arr_3;
		size_3 = size;
		arr_3 = new T[size_3];
		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2, size2, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while (i < size)
		{
			while (j < size2)
			{
				if (arr[i] == arr2[j])
				{
					arr_3[k++] = arr2[j++];
				}
				else
				{
					j++;
				}
			}
			j = 0;
			i++;
		}
		if (k == 0)
		{
			//throw pustoicont();
		}
		size_3 = k;
		T *y = new T[size_3];				//перезаписываем arr, т.к. кол-во  эл-тов
													//в пересечении может быть меньше чем мы выделили в начале фун-ции
		for (int p = 0; p < k; p++)
			y[p] = arr_3[p];

		delete[]arr_3;
		arr_3 = new T[size_3];
		for (int p = 0; p < k; p++)
			arr_3[p] = y[p];
		delete[] y;
	}*/

	/*void symrazn() override {
		delete[]arr_3;
		size_3 = size + size2;
		arr_3 = new T[size_3];
		qsort(arr, size, sizeof(T), comp<T>);
		qsort(arr2, size2, sizeof(T), comp<T>);
		int i = 0, j = 0, k = 0;
		while ((i < size) && (j < size2))
		{
			if (arr[i] < arr2[j])
				arr_3[k++] = arr[i++];
			else
			{
				if (arr[i] > arr2[j])
					arr_3[k++] = arr2[j++];
				else
				{
					i++;
					j++;
					size_3 -= 2;
				}
			}
		}

		while (i < size)
		{
			arr_3[k++] = arr[i++];
		}

		while (j < size2)
		{
			arr_3[k++] = arr2[j++];
		}
	}*/
};





class Price : public Medcine
{
	int size;
	structPrice* Mas;
public:
	Price() {
		size = 0;
		Mas = nullptr;
	}
	Price(int tSize) {
		size = tSize;
		Mas = new structPrice[size];
	}
	Price(Price & other) {
		size = other.size;
		Mas = new structPrice[size];
		for (int i = 0; i < size; i++)
			Mas[i] = other.Mas[i];
	}
	~Price() {
		delete[]Mas;
	}
	int GetSize() { return size; }
	structPrice *GetArray() { return Mas; }


	void In(istream& stream)
	{
		stream >> size;
		Mas = new structPrice[size];
		
		for (int i = 0; i < size; i++)	{
			stream.ignore();
			stream >> Mas[i];
		}
	}

	void Out(ostream& stream) {
		//char* tm;
		for (int i = 0; i < size; i++)
		{
			//tm = Mas[i][0];  cout << endl << "%%%%%" << tm << endl;
			cout<< Mas[i];
			stream << Mas[i];
		}
	}


	void Sort() override	{
		qsort(Mas, size, sizeof(structPrice), comp<structPrice>);
	}

	void SortDown() override	{
		qsort(Mas, size, sizeof(structPrice), compReverse<structPrice>);
	}
	
	void CmpFunc() {
		if (Mas[0] == Mas[1])
			cout << endl << "YYEEAH" << endl;
		else
			cout << "POP" << endl;
	}

	structPrice* poiskstudent(char name2[35], ostream &out) {
		Price T(*this);
		qsort(T.Mas, T.size, sizeof(structPrice), comp<structPrice>);
		structPrice K;
		strcpy_s(K.Name, name2);
		
		structPrice* t = (structPrice*)bsearch(&K, T.Mas, T.size, sizeof(structPrice), comp<structPrice>);
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

	/*CString createstr()
	{
		CString res;
		for (int i = 0; i < count; i++) {
			CString a;
			a.Format(("%s"), Mas[i].Name);
			res += a;
			res += "\r\t";
			a.Format(("%lf"), Mas[i].Price);
			res += a;
			res += "\r\n";
		}
		return res;
	}*/
};




class Med_Price : public Medcine
{
	int size;
	structMed_Price* Mas;
public:
	Med_Price() {
		size = 0;
		Mas = nullptr;
	}
	Med_Price(int tSize) {
		size = tSize;
		Mas = new structMed_Price[size];
	}
	Med_Price(Med_Price & other) {
		size = other.size;
		Mas = new structMed_Price[size];
		for (int i = 0; i < size; i++)
			Mas[i] = other.Mas[i];
	}
	~Med_Price() {
		delete[]Mas;
	}
	int GetSize() { return size; }
	structMed_Price *GetArray() { return Mas; }


	void In(istream& stream)
	{
		stream >> size;
		Mas = new structMed_Price[size];

		for (int i = 0; i < size; i++) {
			stream.ignore();
			stream >> Mas[i];
		}
	}

	void Out(ostream& stream) {
		for (int i = 0; i < size; i++)
		{
			cout << Mas[i];
			stream << Mas[i];
		}
	}

	void Sort() override {
		qsort(Mas, size, sizeof(structMed_Price), comp<structMed_Price>);
	}

	void SortDown() override {
		qsort(Mas, size, sizeof(structMed_Price), compReverse<structMed_Price>);
	}

	void CmpFunc() {
		if (Mas[0] == Mas[1])
			cout << endl << "YYEEAH" << endl;
		else
			cout << "POP" << endl;
	}

	structMed_Price* poiskstudent(char name2[35], ostream &out) {
		Med_Price T(*this);
		qsort(T.Mas, T.size, sizeof(structMed_Price), comp<structMed_Price>);
		structMed_Price K;
		strcpy_s(K.Name, name2);

		structMed_Price* t = (structMed_Price*)bsearch(&K, T.Mas, T.size, sizeof(structMed_Price), comp<structMed_Price>);
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

	/*CString createstr()
	{
		CString res;
		for (int i = 0; i < count; i++) {
			CString a;
			a.Format(("%s"), Mas[i].Name);
			res += a;
			res += "\r\t";
			a.Format(("%s"), Mas[i].myDate);
			res += a;
			res += "\r\t";
			a.Format(("%s"), Mas[i].Section);
			res += a;
			res += "\r\t";
			a.Format(("%d"), Mas[i].Count);
			res += a;
			res += "\r\t";
			a.Format(("%lf"), Mas[i].Price);
			res += a;
			res += "\r\n";
		}
		return res;
	}*/
};