#include <iostream>
#include "MyClass.h"
using namespace std;


void printing(Array_ mas_1, Array_ mas_2)
{
	cout << "The first  array: ";
	if (mas_1.GetArray()[0] < 0)
		cout << "Empty";
	else
		mas_1.out_array();
	cout << endl;
	cout << "The second array: ";
	mas_2.out_array();
	cout << endl;
}



int main()
{
	int n;
	cout << "Enter the size: ";
	cin >> n; cout << endl;

	Array_ mas_1(n), mas_2(n),mas_3(mas_1);
	mas_1.in_array();
	mas_2.in_array();
	cout << "------------------------------------------";

	
	cout << "\n\n-----------Test for equality--------------\n";
	bool res_equal = mas_1 == mas_2;
	printing(mas_1, mas_2);
	if (res_equal)
		cout << "result=" << res_equal << "  =>  Arrays are equal\n\n";
	else
		cout << "result=" << res_equal << "  =>  Arrays are Not equal\n\n";



	cout << "\n\n---------Test for Not equality------------\n";
	bool res_not_equal = mas_1 != mas_2;
	printing(mas_1, mas_2);
	if (res_not_equal)
		cout << "result=" << res_not_equal << "  =>  Arrays are Not equal\n\n";
	else
		cout << "result=" << res_not_equal << "  =>  Arrays are equal\n\n";



	cout << "\n\n---------Comparing (sign more)------------\n";
	bool res_more = mas_1 > mas_2;
	printing(mas_1, mas_2);
	if (res_more)
		cout << "result=" << res_more << "  =>  1>2 by sum of all elements\n\n";
	else
		cout << "result=" << res_more << "  =>  1!>2 by sum of all elements\n\n";



	cout << "\n\n---------Comparing (sign less)------------\n";
	bool res_less = mas_1 < mas_2;
	printing(mas_1, mas_2);
	if (res_less)
		cout << "result=" << res_less << "  =>  1<2 by sum of all elements\n\n";
	else
		cout << "result=" << res_less << "  =>  1!<2 by sum of all elements\n\n";



	cout << "\n\n-----Comparing (sign more & equal)--------\n";
	bool res_more_equal = mas_1 >= mas_2;
	printing(mas_1, mas_2);
	if (res_more_equal)
		cout << "result=" << res_more_equal << "  =>  1>=2 by sum of all elements\n\n";
	else
		cout << "result=" << res_more_equal << "  =>  1<2 by sum of all elements\n\n";



	cout << "\n\n-----Comparing (sign less & equal)--------\n";
	bool res_less_equal = mas_1 <= mas_2;
	printing(mas_1, mas_2);
	if (res_less_equal)
		cout << "result=" << res_less_equal << "  =>  1<=2 by sum of all elements\n\n";
	else
		cout << "result=" << res_less_equal << "  =>  1>2 by sum of all elements\n\n";
	



	cout << "\n--------------Operator '>>'---------------";
	cout << "\nReDefine the 1st array:\n";
	cin >> mas_1;

	cout << "\n\n--------------Operator '<<'---------------";
	cout << "\nThe second array: " << mas_2<<"\n";
	   



	cout << "\n\n---Summation of 2 arrays into the 3-------\n";
	printing(mas_1, mas_2);
	mas_3 = mas_1 + mas_2;
	cout << "The Total  array: "; mas_3.out_array(); cout << "\n\n";
	


	cout << "\n\n------Deleting the same elements----------\n";
	mas_1 - mas_2;
	printing(mas_1, mas_2); cout << "\n";


	cout << "------------------------------------------\n";
	system("pause");
	return 0;
}