#include <iostream>
#include "MyClass.h"
using namespace std;


void printing(Weight wei_1, Weight wei_2)
{
	cout << "The first  weight: ";
	wei_1.out_weight();

	cout << "The second weight: ";
	wei_2.out_weight();
}



int main()
{
	double mul_num, div_num;
	Weight wei_1, wei_2, wei_3;
	wei_1.in_weight();
	wei_2.in_weight();
	cout << "------------------------------------------";

	

	cout << "\n\n-----------Test for equality--------------\n";
	bool res_equal = wei_1 == wei_2;
	printing(wei_1, wei_2);
	if (res_equal)
		cout << "result=" << res_equal << "  =>  Weights are equal\n\n";
	else
		cout << "result=" << res_equal << "  =>  Weights are Not equal\n\n";

	

	cout << "\n\n---------Comparing (sign more)------------\n";
	bool res_more = wei_1 > wei_2;
	printing(wei_1, wei_2);
	if (res_more)
		cout << "result=" << res_more << "  =>  weight 1>2 \n\n";
	else
		cout << "result=" << res_more << "  =>  weight 1!>2 \n\n";



	cout << "\n\n---------Comparing (sign less)------------\n";
	bool res_less = wei_1 < wei_2;
	printing(wei_1, wei_2);
	if (res_less)
		cout << "result=" << res_less << "  =>  weight 1<2 \n\n";
	else
		cout << "result=" << res_less << "  =>  weight 1!<2 \n\n";



	cout << "\n\n-----Comparing (sign more & equal)--------\n";
	bool res_more_equal = wei_1 >= wei_2;
	printing(wei_1, wei_2);
	if (res_more_equal)
		cout << "result=" << res_more_equal << "  =>  weight 1>=2 \n\n";
	else
		cout << "result=" << res_more_equal << "  =>  weight 1<2 \n\n";


	


	cout << "\n\n--------------Operator '>>'---------------";
	cout << "\nReDefine the 2nd weight:\n";
	cin >> wei_2;

	cout << "\n\n--------------Operator '<<'---------------";
	cout << "\nThe second array: " << wei_2 << "\n\n";





	cout << "\n\n---Summation of 2 weights into the 3-------\n";
	printing(wei_1, wei_2);
	wei_3 = wei_1 + wei_2;
	cout << "The Total  array: "; wei_3.out_weight(); cout << "\n\n";


	cout << "\n------Raznost of 2 weights----------\n";
	wei_3 = wei_1 - wei_2;
	printing(wei_1, wei_2);
	cout << "Raznost: "; wei_3.out_weight();
	cout << "\n\n";


	cout << "\n-----------Multiplication-----------\n";
	cout << "Enter the number: "; cin >> mul_num;
	wei_3 = wei_1 * mul_num;
	wei_1.out_weight();
	cout << "Multipl: "; wei_3.out_weight();
	cout << "\n\n";


	cout << "\n-------------Division---------------\n";
	cout << "Enter the number: "; cin >> div_num;
	wei_3 = wei_1 / div_num;
	wei_1.out_weight();
	cout << "Division: "; wei_3.out_weight();
	cout << "\n";

	cout << "------------------------------------------\n";
	system("pause");
	return 0;
}