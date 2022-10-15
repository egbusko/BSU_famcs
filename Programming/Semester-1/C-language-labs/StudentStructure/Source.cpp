#include<iostream> 
#include<string.h> 
using namespace std;

struct student {
	int nz;
	char faculty[5];
	char form_edu[10];
	char name[20];
	char surname[30];
};


int cmpstud(const void * st1, const void * st2) {
	student * a1 = (student*)st1;
	student * a2 = (student*)st2;

	if (strcmp(a1->faculty, a2->faculty) == 0) {
		if (strcmp(a1->surname, a2->surname) == 0) {
			return strcmp(a1->name, a2->name);
		}
		else return strcmp(a1->surname, a2->surname);
	}

	else return strcmp(a1->faculty, a2->faculty);


}

void MySort(student *M, int n) {
	qsort(M, n, sizeof(student), cmpstud);
}

int main() {
	FILE *file;
	file = new FILE;
	freopen_s(&file, "sourc.txt", "r", stdin);		//גגמה ט גûגמה ג פאיכ 
	freopen_s(&file, "res.txt", "w", stdout);

	student *M2;
	int n;

	cin >> n;
	M2 = new student[n];
	for (int i = 0; i < n; i++) {
		cin >> M2[i].nz >> M2[i].faculty >> M2[i].form_edu >> M2[i].name >> M2[i].surname;
	}

	MySort(M2, n);
	for (int i = 0; i < n; i++) {
		cout << M2[i].nz << " " << M2[i].faculty << " " << M2[i].form_edu << " " << M2[i].name << " " << M2[i].surname << endl;
	}
	cout << sizeof(student);

	//system("pause"); 
	return 0;

}