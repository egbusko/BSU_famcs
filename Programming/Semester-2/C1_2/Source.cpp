//4		В заданной строке заменить каждый символ «*» числом, соответствующим номеру
//		по порядку вхождения этого символа в строку.


#include <iostream>
#include<locale>		//для работы с рус символами
#include<cwctype>		//ф-ции со строками
#include <string>
using namespace std;

int main()
{
	locale::global(locale("rus_rus.866"));

	wstring str;		//w-расшир таблица кодировки
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

//Маленькие буквы строки, переформировывает в заглавные


//int main()
//{
//	locale::global(locale("rus_rus.866"));
//
//	wstring str;		//w-расшир таблица кодировки
//	wcout << "Enter str" << endl;
//	getline(wcin, str);
//
//	for (auto &r : str)
//	{
//		if (iswlower(r))	//явл ли маленькой
//		{
//			r = towupper(r);		//в большую
//		}
//	}
//	wcout << str << endl;
//
//	system("pause");
//	return 0;
//}