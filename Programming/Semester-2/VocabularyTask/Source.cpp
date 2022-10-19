#include <iostream>
#include <fstream>
#include <string>
#include <list>
//#include <map>
using namespace std;


struct wMixed{
	string word;
	int sum;
};

struct Voc{
	string word;
	int chance;
	int sum;
};





int comp1(const void * a, const void * b){
	return (*(string*)a > *(string*)b);
}


void swap(string *a, int i, int j)
{
	string s = a[i];
	a[i] = a[j];
	a[j] = s;
}

bool NextSet(string *a, int n)
{
	int j = n - 2;
	while (j != -1 && a[j] >= a[j + 1]) j--;
	if (j == -1)
		return false;		// больше перестановок нет
	int k = n - 1;
	while (a[j] >= a[k]) k--;
	swap(a, j, k);
	int l = j + 1, r = n - 1; // сортируем оставшуюся часть последовательности
	while (l < r)
		swap(a, l++, r--);
	return true;
}

void Print(string *a, int n)  
{
	static int num = 1; 
	cout << num++ << ": ";
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
	cout << endl;
}



void PrintingAllSwaps(list<Voc> ForCheckSumList)
{
	int lSize = 0;
	for (auto i = ForCheckSumList.begin(); i != ForCheckSumList.end(); i++)
		lSize++;

	string *ListToPrint = new string [lSize];
	
	int j = 0;
	for (auto i = ForCheckSumList.begin(); i != ForCheckSumList.end(); i++)
	{
		ListToPrint[j] = i->word;
		j++;
	}

	qsort(ListToPrint, lSize, sizeof(string), comp1);

	/*for (int i = 0; i < lSize; i++)
		cout << ListToPrint[i] << " ";
	cout << endl;*/

	
	Print(ListToPrint, lSize);
	while (NextSet(ListToPrint, lSize))
		Print(ListToPrint, lSize);

	cout << endl << endl;
	system("pause");
}




bool check_for_letters(string mixed_word, string voc_word)
{
	//cout << mixed_word << " " << voc_word << endl;
	int k = 0;
	if (mixed_word.length() == voc_word.length())
	{

		for (int i = 0; i < mixed_word.length(); i++)
		{
			for (int j = 0; j < mixed_word.length(); j++)
			{
				if (mixed_word[i] == voc_word[j])
				{
					k++;
				}
				
			}
			if (k == 0)
				return 0;

			k = 0;
		}
		return 1;
	}
}




void fSentence(list<Voc> myVoc, const list<wMixed> toTranslate)
{
	//Находим слова, у которых одинаковые суммы и проверяем ф-ей одинаковые в их составе буквы 

	list<Voc> ForCheckSumList;

	for (auto i = toTranslate.begin(); i != toTranslate.end(); i++)
	{
		//+ Оставляем в листе слова, с наибольшей вероятностью

		Voc ForCheckSumStruct;
		ForCheckSumStruct.chance = -1;

		for (auto j = myVoc.begin(); j != myVoc.end(); j++)
		{	   
			if (i->sum == j->sum)
			{
				int per = check_for_letters(i->word, j->word);

				if (per == 1 && ForCheckSumStruct.chance < j->chance)
				{
					ForCheckSumStruct.chance = j->chance;
					ForCheckSumStruct.word = j->word;
					ForCheckSumStruct.sum = j->sum;
				}
			}

		}
		//только после того, как выбрали слово с наиб. вероятностью, закидываем его в лист для вывода
		if (ForCheckSumStruct.chance != -1)
			ForCheckSumList.push_back(ForCheckSumStruct);
	}	


	PrintingAllSwaps(ForCheckSumList);
	
}



int main() 
{
	ifstream fVocabulary("vocabulary.txt");
	if (fVocabulary.is_open())
		cout << "+" << endl;
	else
		cout << "-" << endl;

	list<Voc> myVoc;

	int i = 0;
	while(!fVocabulary.eof() )
	{
		Voc vWord;
		fVocabulary >> vWord.word;
		vWord.word = vWord.word.substr(0, vWord.word.length() - 1);    //Удаляем запятую
		fVocabulary >> vWord.chance;

		int sSum = 0;
		for (int i = 0; i < vWord.word.length(); i++)
			sSum += vWord.word[i];

		vWord.sum = sSum;

		myVoc.push_back(vWord);
	}
	cout << endl;
	fVocabulary.close();


			/*for (auto i = myVoc.begin(); i != myVoc.end(); i++)
				cout << i->word << " " << i->chance << " " << i->sum << endl;*/
			

	

	ifstream fTranslate("to_translate.txt");

	if (fTranslate.is_open())
		cout << "+" << endl;
	else
		cout << "-" << endl;



	string tempStr;

	while (!fTranslate.eof())
	{
		list<wMixed> toTranslate;

		getline(fTranslate, tempStr);

		int start = 0, found = 0;
		while (found <= tempStr.length() /*&& found>=0*/)		//в while это условие уже учитывается
		{
			wMixed mWord;

			found = tempStr.find(" ", start);
			mWord.word = tempStr.substr(start, found - start);
			start = found + 1;


			int sSum = 0;
			for (int i = 0; i < mWord.word.length(); i++)
				sSum += mWord.word[i];
			mWord.sum = sSum;

			toTranslate.push_back(mWord);

			if (found + 1 == tempStr.length())
				break;
		}


		//поочереди, для каждой строки
		fSentence(myVoc, toTranslate);

		/*for (auto i = toTranslate.begin(); i != toTranslate.end(); i++)
			cout << i->word << " " << i->sum << endl;
		cout << endl;*/
	}



	/*string tempStr;
	while (!fTranslate.eof())
	{
		list<wMixed> lTranslate;
		getline(fTranslate, tempStr);
				
		
		int j=0;
		while(tempStr[j] != '\0')
		{
			wMixed mWord;
			string tmp;

			while (tempStr[j] != ' '&&tempStr[j] != '\0')
			{
				tmp += tempStr[j];
				j++;
			}
			mWord.word = tmp;
			cout << mWord.word<<" ";
			

			int sSum = 0;
			for (int i = 0; i < mWord.word.length(); i++)
				sSum += mWord.word[i];
			mWord.sum = sSum;

			lTranslate.push_back(mWord);


			if (tempStr[j] =='\0' )
				break;
			j++;
		}
		fSentence(tempStr, lTranslate);
	}*/

	//system("pause");
	return 0;
}