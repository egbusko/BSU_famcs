#include "Header.h"
#include <iostream>
#include <fstream>
#include <string>
using namespace std;




int main()
{
	TVOC<EngFr> A;
	ifstream fInTxt_1("InFile1.txt");
	fInTxt_1 >> A;
	fInTxt_1.close();


	////cout<<A[0].EngWord
	//int t[20];
	//int u = 0;
	//int k = 1;
	//for (int i = 0; i < A.GetCount(); i++)
	//{
	//	if (strcmp((A[i].EngWord), (A[i + 1].EngWord)) == 0)
	//		k++;

	//	if (strcmp((A[i].EngWord), (A[i + 1].EngWord)) != 0)
	//	{
	//		t[u] = k;
	//		u++;
	//		k = 1;
	//	}
	//}

	//cout << "                         " <<t[0] << t[1] << t[2] << t[3];


	A.Sort();
	cout << " ----------First  (Sorted on words) EngFr ---------- \n\n";
	cout << A;
	cout << " --------------------------------------------------- \n\n\n";


	ofstream OutFile1("Output1.txt");
	OutFile1 << " ----------First  (Sorted on words) EngFr ---------- \n\n";
	OutFile1 << A;
	OutFile1 << " ---------------------------------------------------\n\n\n";
	OutFile1.close();






	char tmpname1[20];
	cout << endl << " Enter translation: ";
	cin >> tmpname1;
	try {
		A.FindEng(tmpname1, cout);
	}
	catch (nenaiden) {
		cout << "nenaiden" << endl;
	}
	cout << "\n\n\n\n";




	TVOC<FrEng> B;
	ifstream fInTxt_2("InFile2.txt");
	fInTxt_2 >> B;
	fInTxt_2.close();

	B.SortD();
	cout << " ----------Second  (Sorted  on types)  FrEng ---------- \n\n";
	cout << B;
	cout << " ------------------------------------------------------ \n\n\n";

	ofstream OutFile2("Output2.txt");
	OutFile2 << " ----------Second  (Sorted on types)  FrEng---------- \n\n";
	OutFile2 << B;
	OutFile2 << " ------------------------------------------------ \n\n\n";
	OutFile2.close();




	char tmpname2[20];
	cout << endl << " Enter translation: ";
	cin >> tmpname2;
	try {
		B.FindFra(tmpname2, cout);
	}
	catch (nenaiden) {
		cout << "nenaiden" << endl;
	}
	cout << "\n\n\n\n";
	





	





	TVOC<EngCounter> C(A.GetCount());

	bool temp = false;
	int pos = 0;

	for (int i = 0; i < A.GetCount(); i++)
	{
		for (int j = 0; j < C.GetCount(); j++)
		{
			if (strcmp((C[j].EngWord), (A[i].EngWord)) == 0)
			{
				temp = true;
				C[j].counter++;
				break;
			}
		}

		if (temp == false)
		{
			strcpy_s(C[pos].EngWord, A[i].EngWord);
			C[pos].P = A[i].P;
			C[pos].counter = 1;
			pos++;
		}
		temp = false;
	}


	C.SetCount(pos);


	//C.SortD();

	ofstream OutFile3("Output3.txt");
	OutFile3 << " ----------Third  (Sorted on types)  EngCounter ---------- \n\n";
	OutFile3 << C;
	OutFile3 << " ------------------------------------------------ \n\n\n";
	OutFile3.close();




	cout << endl;
	system("pause");
	return 0;
}
