#pragma once
#include "pch.h"
#include <windows.h>
#include <iostream>
#include <conio.h>
#include <fstream>
#include <string>
#include <mutex>
using namespace std;


struct Student {
	int num;
	char name[20];
	double grade;
};


int hashFunc(int studNum) {
	return studNum % 10;
}


class Journal {
	int size;
	Student* arr;
	Student w;

public:
	Journal() {
		size = 6;
		arr = new Student[6];
		arr[0].num = 18231;
		strncpy(arr[0].name, "Tim McGuiness", sizeof("Tim McGuiness"));
		arr[0].grade = 7.0;		
		arr[1].num = 18232;
		strncpy(arr[1].name, "Michal", sizeof("Michal"));
		arr[1].grade = 4.3;
		arr[2].num = 18233;
		strncpy(arr[2].name, "Dima", sizeof("Dima"));
		arr[2].grade = 8.6;
		arr[3].num = 18234;
		strncpy(arr[3].name, "Brat", sizeof("Brat"));
		arr[3].grade = 6.5;
		arr[4].num = 18235;
		strncpy(arr[4].name, "Lesha", sizeof("Lesha"));
		arr[4].grade = 7.8;
		arr[5].num = 18236;
		strncpy(arr[5].name, "Pavel", sizeof("Pavel"));
		arr[5].grade = 9.2;
	}

	Journal(int numStud) : size(numStud) {
		arr = new Student[numStud];
		int tmp = 1;
		for (int i = 0; i < this->size; i++) {
			arr[i].num = tmp++;
			strncpy(arr[i].name,"Dima", 20);
			arr[i].grade = tmp + 10;
		}
	}

	Journal(const Journal &other) {
		this->size = other.size;
		this->arr = new Student[other.size];
		for (int i = 0; i < other.size; i++) {
			this->arr[i].num = other.arr[i].num;
			strncpy(this->arr[i].name, other.arr[i].name, 20);
			this->arr[i].grade = other.arr[i].grade;
		}

	}

	~Journal() { delete[] arr; }

	int getSize() { return size; }
	Student* GetArray() { return arr; }
	Student* getStud(int i) {
		int tmp = getIndexbyId(i);
		return &arr[tmp-1];
	}

	int getIndexbyId(int id) {
		for (int i = 0; i < size; i++) {
			if (hashFunc(this->arr[i].num) == id) {
				return i + 1;
			}
		}
		return -1;
	}

	void changeStud(int id, char tname[], double tgrade) {
		for (int i = 0; i < size; i++) {
			if (hashFunc(this->arr[i].num) == id) {
				strncpy(this->arr[i].name, tname, 20);
				arr[i].grade = tgrade;
				break;
			}
		}
	}


	Journal & operator=(const Journal &other) {
		this->size = other.size;
		if (this->arr != nullptr) {
			delete[] this->arr;
		}
		this->arr = new Student[other.size];
		for (int i = 0; i < other.size; i++) {
			this->arr[i].num = other.arr[i].num;
			strncpy(this->arr[i].name, other.arr[i].name, 20);
			this->arr[i].grade = other.arr[i].grade;
		}
		return *this;
	}



	void wrConcole() {
		for (int i = 0; i < size; i++) {
			cout << arr[i].num << " ";
			cout << arr[i].name << " ";
			cout << arr[i].grade << " ";
			cout << endl;
		}
	}


	friend ostream &operator << (ostream &out, const Journal &obj) {
		out.write((char*)&obj.size, 4);
		int strSize;
		for (int i = 0; i < obj.size; i++) {
			out.write((char*)&obj.arr[i].num, 4);
			out.write((char*)obj.arr[i].name, 20);
			out.write((char*)&obj.arr[i].grade, 8);
		}
		return out;
	}

	friend istream &operator >> (istream &in, Journal &obj) {
		in.read((char*)&obj.size, 4);
		obj.arr = new Student[obj.size];
		for (int i = 0; i < obj.size; i++) {
			in.read((char*)&obj.arr[i].num, 4);
			in.read((char*)obj.arr[i].name, 20);
			in.read((char*)&obj.arr[i].grade, 8);
		}
		return in;
	}
};