//4		� �������� ������ �������� ������ ������ �*� ������, ��������������� ������
//		�� ������� ��������� ����� ������� � ������.


#include <iostream>
#include<locale>		//��� ������ � ��� ���������
#include<cwctype>		//�-��� �� ��������
#include <string>
using namespace std;

int main()
{
	locale::global(locale("rus_rus.866"));

	wstring str;		//w-������ ������� ���������
	wstring str2;
	wcout << "Enter str" << endl;
	getline(wcin, str);
	
	for (int i=0; i<str.size(); i++)
	{
		if (str[i] == '*')
		{
			str2 += to_wstring(i+1);
			continue;
		}
		str2 +=str[i];
	}
	wcout << str2 << endl;
	system("pause");
	return 0;
}

//��������� ����� ������, ����������������� � ���������


//int main()
//{
//	locale::global(locale("rus_rus.866"));
//
//	wstring str;		//w-������ ������� ���������
//	wcout << "Enter str" << endl;
//	getline(wcin, str);
//
//	for (auto &r : str)
//	{
//		if (iswlower(r))	//��� �� ���������
//		{
//			r = towupper(r);		//� �������
//		}
//	}
//	wcout << str << endl;
//
//	system("pause");
//	return 0;
//}