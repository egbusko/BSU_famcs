#pragma once
#include <iostream>	
#include <string>
using namespace std;



class Phone
{
	string surname;
	string name;
	string patron;
	string adress;
	string phone_number;
	int time_in_hours;
	int time_in_min;
	int time_out_hours;
	int time_out_min;
	
public:

	Phone() {
		surname = "";
		name = "";
		patron = "";
		adress = "";
		phone_number = "";
		time_in_hours = 0;
		time_in_min = 0;
		time_out_hours = 0;
		time_out_min = 0;
	}

	string GetName()				{	return name;				}
	void SetName(string s1)			{	name = s1;					}
	void ShowName()					{	cout << name/* << endl*/;		}

	string GetSurname()				{	return surname;				}
	void SetSurname(string s1)		{	surname = s1;				}
	void ShowSurname()				{	cout << surname /*<< endl*/;	}

	string GetPatron()				{	return patron;				}
	void SetPatron(string s1)		{	patron = s1;				}
	void ShowPatron()				{	cout << patron << endl;		}

	string GetAdress()				{	return adress;				}
	void SetAdress(string s1)		{	adress = s1;				}
	void ShowAdress()				{	cout << adress << endl;		}

	string GetNumber()				{	return phone_number;		}
	void SetNumber(string s1)		{	phone_number = s1;			}
	void ShowNumber()				{	cout << phone_number << endl;}



	int GetSpeechInHours()			{	return time_in_hours;		}
	void SetSpeechInHours(int n1)	{	time_in_hours = n1;			}
	void ShowSpeechInHours()		{	cout << time_in_hours << endl;}

	int GetSpeechInMin()			{	return time_in_min;			}
	void SetSpeechInMin(int n1)		{	time_in_min = n1;			}
	void ShowSpeechInMin()			{	cout << time_in_min << endl;}

	int GetSpeechOutHours()			{	return time_out_hours;		}
	void SetSpeechOutHours(int n1)	{	time_out_hours = n1;		}
	void ShowSpeechOutHours()		{	cout << time_out_hours << endl;}

	int GetSpeechOutMin()			{	return time_out_min;		}
	void SetSpeechOutMin(int n1)	{	time_out_min = n1;			}
	void ShowSpeechOutMin()			{	cout << time_out_min << endl;}





	void In(istream& stream )	{
		stream >> surname >> name >> patron >> adress >> phone_number 
			   >> time_in_hours   >> time_in_min >> time_out_hours >> time_out_min;
	}


	void Out(ostream& stream)	{
		stream << GetSurname() << " " << GetName()   << " " << GetPatron() << " " 
			   << GetAdress()  << " " << GetNumber() << " "
			   << GetSpeechInHours()  << " " << GetSpeechInMin()  << " "
			   << GetSpeechOutHours() << " " << GetSpeechOutMin() << endl;
	}
	


	void WriteToBin(ostream& stream)
	{
		size_t len = surname.length() + 1;
		stream.write((char*)&len, sizeof(len));
		stream.write((char*)surname.c_str(), len);

		len = name.length() + 1;
		stream.write((char*)&len, sizeof(len));
		stream.write((char*)name.c_str(), len);
		
		len = patron.length() + 1;
		stream.write((char*)&len, sizeof(len));
		stream.write((char*)patron.c_str(), len);

		len = adress.length() + 1;
		stream.write((char*)&len, sizeof(len));
		stream.write((char*)adress.c_str(), len);

		len = phone_number.length() + 1;
		stream.write((char*)&len, sizeof(len));
		stream.write((char*)phone_number.c_str(), len);

		stream.write((char*)&time_in_hours, sizeof(time_in_hours));
		stream.write((char*)&time_in_min, sizeof(time_in_min));
		stream.write((char*)&time_out_hours, sizeof(time_out_hours));
		stream.write((char*)&time_out_min, sizeof(time_out_min));
	}



	void ReadToBin(istream& in)
	{
		char s[1024];
		int numLetters = 0;

		in.read((char*)&numLetters, 4);
		in.read((char*)s, numLetters);
		surname = s;

		in.read((char*)&numLetters, 4);
		in.read((char*)s, numLetters);
		name = s;

		in.read((char*)&numLetters, 4);
		in.read((char*)s, numLetters);
		patron = s;

		in.read((char*)&numLetters, 4);
		in.read((char*)s, numLetters);
		adress = s;

		in.read((char*)&numLetters, 4);
		in.read((char*)s, numLetters);
		phone_number = s;
		

		in.read((char*)&time_in_hours, 4);
		in.read((char*)&time_in_min, 4);
		in.read((char*)&time_out_hours, 4);
		in.read((char*)&time_out_min, 4);

		cout << surname << " "<< name << " " << patron << " " << adress << " " << phone_number
			<< " " << time_in_hours << " " << time_in_min << " " << time_out_hours << " " << time_out_min;
		cout << endl;
	}
};









	

	void change_classes(Phone* mas_of_phones, int i, int j) {
		Phone perem_t;
		perem_t = mas_of_phones[i];
		mas_of_phones[i] = mas_of_phones[j];
		mas_of_phones[j] = perem_t;
	}


	void chast_1(Phone* mas_of_phones, int n) {
		for (int i = 0; i < n; i++)
		{
			cout << endl << "---------------------" << endl;
			mas_of_phones[i].ShowSurname();
			mas_of_phones[i].ShowName();
			mas_of_phones[i].ShowPatron();
			mas_of_phones[i].ShowAdress();
			mas_of_phones[i].ShowNumber();

			cout << mas_of_phones[i].GetSpeechInHours() << " " << mas_of_phones[i].GetSpeechInMin() << endl
				<< mas_of_phones[i].GetSpeechOutHours() << " " << mas_of_phones[i].GetSpeechOutMin();
			cout << endl << "---------------------" << endl;
		}
		string a; int b;		//переменные для временного хранения

		for (int i = 0; i < n; i++)
		{
			cout << "Enter name of person" << i + 1 << endl;
			cin >> a;
			mas_of_phones[i].SetName(a);
			//getline(cin, mas_of_phones[i].name);

			cout << "Enter surname of person" << i + 1 << endl;
			cin >> a;
			mas_of_phones[i].SetSurname(a);

			cout << "Enter patron of person" << i + 1 << endl;
			cin >> a;
			mas_of_phones[i].SetPatron(a);

			cout << "Enter adress of person" << i + 1 << endl;
			cin >> a;
			mas_of_phones[i].SetAdress(a);

			cout << "Enter phone_number of person" << i + 1 << endl;
			cin >> a;
			mas_of_phones[i].SetNumber(a);

			cout << "Enter time_in_hours of person" << i + 1 << endl;
			cin >> b;
			mas_of_phones[i].SetSpeechInHours(b);

			cout << "Enter time_in_min of person" << i + 1 << endl;
			cin >> b;
			mas_of_phones[i].SetSpeechInMin(b);

			cout << "Enter time_out_hours of person" << i + 1 << endl;
			cin >> b;
			mas_of_phones[i].SetSpeechOutHours(b);

			cout << "Enter time_out_min of person" << i + 1 << endl;
			cin >> b;
			mas_of_phones[i].SetSpeechOutMin(b);
			cout << endl;

			system("cls");
		}
		system("pause");
		system("cls");
	}


	void chast_a(Phone* mas_of_phones, int n) {
		int lim_hours, lim_min;
		cout << "Enter the limit of in_speech (hours)" << endl;
		cin >> lim_hours;
		cout << "Enter the limit of in_speech (min)" << endl;
		cin >> lim_min;

		for (int i = 0; i < n; i++)
		{
			if (mas_of_phones[i].GetSpeechInHours() > lim_hours)
			{
				cout << endl << "---------------------" << endl;
				mas_of_phones[i].ShowSurname();
				mas_of_phones[i].ShowName();
				mas_of_phones[i].ShowPatron();
				mas_of_phones[i].ShowAdress();
				mas_of_phones[i].ShowNumber();

				cout << mas_of_phones[i].GetSpeechInHours() << " " << mas_of_phones[i].GetSpeechInMin() << endl
					<< mas_of_phones[i].GetSpeechOutHours() << " " << mas_of_phones[i].GetSpeechOutMin();
				cout << endl << "---------------------" << endl;
			}
			cout << endl << endl;

			if (mas_of_phones[i].GetSpeechInHours() == lim_hours)
				if (mas_of_phones[i].GetSpeechInMin() > lim_min)
				{
					cout << endl << "---------------------" << endl;
					mas_of_phones[i].ShowSurname();
					mas_of_phones[i].ShowName();
					mas_of_phones[i].ShowPatron();
					mas_of_phones[i].ShowAdress();
					mas_of_phones[i].ShowNumber();

					cout << mas_of_phones[i].GetSpeechInHours() << " " << mas_of_phones[i].GetSpeechInMin() << endl
						<< mas_of_phones[i].GetSpeechOutHours() << " " << mas_of_phones[i].GetSpeechOutMin();
					cout << endl << "---------------------" << endl;
				}
		}
		system("pause");
		system("cls");
	}


	void chast_b(Phone* mas_of_phones, int n) {
		for (int i = 0; i < n; i++)
		{
			if (mas_of_phones[i].GetSpeechOutHours() != 0)
				if (mas_of_phones[i].GetSpeechOutMin() != 0)
				{
					cout << endl << "---------------------" << endl;
					mas_of_phones[i].ShowSurname();
					mas_of_phones[i].ShowName();
					mas_of_phones[i].ShowPatron();
					mas_of_phones[i].ShowAdress();
					mas_of_phones[i].ShowNumber();

					cout << mas_of_phones[i].GetSpeechInHours() << " " << mas_of_phones[i].GetSpeechInMin() << endl
						<< mas_of_phones[i].GetSpeechOutHours() << " " << mas_of_phones[i].GetSpeechOutMin();
					cout << endl << "---------------------" << endl;
				}
		}
		system("pause");
		system("cls");
	}



	void chast_c7(Phone* mas_of_phones, int num, ostream& stream_txt, ostream& stream_bin) {

		for (int i = 0; i < num; i++)
		{
			if ((mas_of_phones[i].GetSpeechOutHours() != 0) && (mas_of_phones[i].GetSpeechOutMin() != 0))
			{
				string surname = mas_of_phones[i].GetSurname();
				string name = mas_of_phones[i].GetName();
				string patron = mas_of_phones[i].GetPatron();
				string adress = mas_of_phones[i].GetAdress();
				string phone_number = mas_of_phones[i].GetNumber();
				int time_in_hours = mas_of_phones[i].GetSpeechInHours();
				int time_in_min = mas_of_phones[i].GetSpeechInMin();
				int time_out_hours = mas_of_phones[i].GetSpeechOutHours();
				int time_out_min = mas_of_phones[i].GetSpeechOutMin();

				stream_txt << "-----------------------------------------" << endl
					<< surname << " " << name << " " << patron << " " << adress << " " << phone_number << " "
					<< time_in_hours << "-" << time_in_min << " " << time_out_hours << "-" << time_out_min << endl;


				size_t len = surname.length() + 1;
				stream_bin.write((char*)&len, sizeof(len));
				stream_bin.write((char*)surname.c_str(), len);

				len = name.length() + 1;
				stream_bin.write((char*)&len, sizeof(len));
				stream_bin.write((char*)name.c_str(), len);

				len = patron.length() + 1;
				stream_bin.write((char*)&len, sizeof(len));
				stream_bin.write((char*)patron.c_str(), len);

				len = adress.length() + 1;
				stream_bin.write((char*)&len, sizeof(len));
				stream_bin.write((char*)adress.c_str(), len);

				len = phone_number.length() + 1;
				stream_bin.write((char*)&len, sizeof(len));
				stream_bin.write((char*)phone_number.c_str(), len);

				stream_bin.write((char*)&time_in_hours, sizeof(time_in_hours));
				stream_bin.write((char*)&time_in_min, sizeof(time_in_min));
				stream_bin.write((char*)&time_out_hours, sizeof(time_out_hours));
				stream_bin.write((char*)&time_out_min, sizeof(time_out_min));

			}
		}
	}

	

	void chast_c(Phone* mas_of_phones, int n) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - i - 1; j++) {
				if (mas_of_phones[j].GetSurname() > mas_of_phones[j + 1].GetSurname())
					change_classes(mas_of_phones, j, j + 1);

			}
		}

		for (int i = 0; i < n - 1; i++)
		{
			if (mas_of_phones[i].GetSurname() == mas_of_phones[i + 1].GetSurname())
			{
				if (mas_of_phones[i].GetName() > mas_of_phones[i + 1].GetName())
				{
					change_classes(mas_of_phones, i, i + 1);
				}
			}

		}


		for (int i = 0; i < n; i++)
		{
			cout << endl << "---------------------" << endl;
			mas_of_phones[i].ShowSurname();
			mas_of_phones[i].ShowName();
			mas_of_phones[i].ShowPatron();
			mas_of_phones[i].ShowAdress();
			mas_of_phones[i].ShowNumber();

			cout << mas_of_phones[i].GetSpeechInHours() << " " << mas_of_phones[i].GetSpeechInMin() << endl
				<< mas_of_phones[i].GetSpeechOutHours() << " " << mas_of_phones[i].GetSpeechOutMin();
			cout << endl << "---------------------" << endl;
		}

		system("pause");
		system("cls");
	}