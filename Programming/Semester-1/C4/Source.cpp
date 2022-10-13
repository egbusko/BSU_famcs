//#include <iostream>	
//using namespace std;
//int main()
//{
//	const int n=3;
//	int mas[n][n];
//	int i ,j;
//	for (i = 0; i < n;i++)
//		for (j = 0; j < n;j++)
//			cin >> mas[i][j];
//	cout << endl;
//
//			for (i = 0; i < n; i++)
//			{
//				for (j = 0; j < n; j++)
//				{
//					if (j < i)
//						cout << "  ";
//					else cout << mas[i][j] << " ";
//				}
//				cout << endl;
//			}
//			cout << endl;
//
//	for (int i = 0; i < n; i++) 
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if ((i == j) || (i + j == n - 1))
//				cout << mas[i][j] << " ";
//			else cout << "  ";
//		}
//		cout << endl;
//	}
//	cout << endl;
//
//			for (i = 0; i < n; i++)
//			{
//				for (j = 0; j<=i; j++)
//					cout<< mas[i][j]<<" ";
//			cout << endl;
//			}
//
//	system("pause");
//	return 0;
//}


#include <iostream>
#include <cmath>
using namespace std;


#define mass_size 4


int ex()
{
	const int n = 3;
	int mas[n][n], mas2[n][n], arr[n*n];
	int i, j;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
			cin >> mas[i][j];
	cout << endl;
	int f = 0;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++)
		{
			arr[f] = mas[i][j];
			f++;
		}
	f = 0;

	for (j = 0; j < n; j++)
		for (i = n - 1; i >= 0; i--)
		{
			mas2[i][j] = arr[f];
			f++;
		}

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << mas[i][j] << " ";
		cout << endl;
	}
	cout << endl;

	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
			cout << mas2[i][j] << " ";
		cout << endl;
	}
	system("pause");
	return 0;
}



void rotate ( int m[][mass_size], int row, int col)
{
	int t = 0, n,a, b, c;
	n = m[row][col];
	a = m[mass_size-1-col][row];
	b = m[mass_size-1-row][mass_size - 1 - col];
	c = m[col][mass_size - 1 - row];

	m[row][col] = c;
	m[mass_size - 1 - col][row] =n;
	m[mass_size - 1 - row][mass_size - 1 - col] =a;
	m[col][mass_size - 1 - row]= b;
	return ;
}

int ex2()
{
	/*const int mass_size = 4;*/
	int mass[mass_size][mass_size] = { {1,2,3,4} , {1,2,3,4} , {1,2,3,4}, {1,2,3,4} };

	//int mass[mass_size][mass_size] = { {0, 1, 2, 3, 4}, {10, 11, 12,13 , 14} , {20,21,22,23,24}, {30,31,32,33,34}, {40,41,42,43,44} };

	int circle_count = 0;
	for (int i = 0; i < mass_size/2+1 ; i++)
	{
		for (int j = circle_count; j < mass_size -1- circle_count ; j++)
		{
			rotate(mass, i, j);
		}
		circle_count++;
	}
		return 0;
}

int main()
{
	return ex();
	//return ex2();
}