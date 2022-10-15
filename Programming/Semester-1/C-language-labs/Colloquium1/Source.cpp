//15
#include <iostream>;
using namespace std;
int count_numerals_in_number(int number)
{
	int k = 0;
	while (number > 0)
	{
		number /= 10;
		k++;
	}
	return k;
}

int* division_numbers_into_numerals(int number)
{
	int n;
	n= count_numerals_in_number(number);
	int *arr = new int[n+1];
	for (int i = n; i > 0; i--)
	{
		arr[i] = number % 10;
		number /= 10; 
	}
	arr[0] = n;
	return arr;
}
int main()
{
	int number;
	cin >> number;
	int*mas=division_numbers_into_numerals(number);
	for (int i=1;i<mas[0]+1;i++)
		cout << mas[i]<<" ";
	cout << endl;
	system("pause");
	return 0;
}