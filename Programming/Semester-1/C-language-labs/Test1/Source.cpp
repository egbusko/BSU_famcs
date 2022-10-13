//Бусько Егор 5гр


#include <iostream>

using namespace std;
//
//int * get2and4(int a)
//{
//	int out[2];
//	out[0] = (a - a / 1000 - a % 100)/100;
//	out[1] = (a - a / 100 - a % 10) / 10;
//	return out;
//}


int main()
{
	/*int arr[6],arr2[12],k=0;
	cout << "Enter 6 numbers which have 4 numerals" << endl;
	for (int i = 0; i < 6; i++)
		cin >> arr[i];*/
	int arr[6] = { 1234,2356,2364,6897,3464,7890 };
	int arr2[12], k = 0;
//---------------------------------------------------	
	for (int i = 0; i < 6; i++)
	{
		arr2[k+1] = arr[i] % 10;
		arr[i] = arr[i] / 100;
		arr2[k] = arr[i] % 10;
		k =k+2;
	}
	for (int k = 0; k < 12; k++)
		cout << arr2[k] << " ";
	cout << endl;

	
	int n=12, j;
	for (int k = 0; k < n; )
	{
		if ((arr2[k] % 3 == 0)&&(arr2[k]!=0))
		{
			j = k;
			for (int i = j; i < n-1; i++)
 				arr2[i] = arr2[i + 1];
			n--;
		}
		else
		k++;	
	}

	for (int k = 0; k < n; k++)
	{
		cout << arr2[k] << " ";
	}
	cout << endl;
	k = 0;

	int N;
	cout << "Enter N"<<endl;
	cin >> N;
	int **matr = new int*[N];
	for (int i = 0; i < N; i++)
		matr[i] = new int[N];

	for (int j = 0; j < N; j++)
	{
		for (int i = 0; i < N; i++)
		{
			if (k == n)
			{
				k = 0;
			}
			matr[i][j] = arr2[k];
			k++;
		}
	}

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
			cout << matr[i][j] << " ";
		cout << endl;
	}

		//for (int i = 0; i < N; i++)
	//	for (int j = 0; j < N; j++)

	for (int i = 0; i < N; i++)
		delete[] matr[i];
	delete[]matr;

	system("pause");
	return 0;
}