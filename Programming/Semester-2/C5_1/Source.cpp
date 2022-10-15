#include <iostream>
#include <string>
#include "MyClass.h"
#include <windows.h>
using namespace std;


int main() 
{	
	//rectangle rect_obj(x_1,y_1,x_2,y_2); 
	//rectangle rect_obj;
	//rect_obj.square_or_not();
	//rect_obj.string_status();
	//rect_obj.painting _rect();
	   

	int x_1, y_1, x_2, y_2, r_c, g_c, b_c; string txt;
		cout << "Enter the coordinates of 2 corners: \n";
		cin >> x_1>> y_1>> x_2>> y_2;
	cout << "Enter the RGB\n";
	cin >> r_c >> g_c >> b_c;
	cout << "Enter the text - ";
	cin >> txt;
	image_rect obj_2(x_1, y_1, x_2, y_2, r_c, g_c, b_c, txt);
	system("cls");



 	obj_2.painting_rect(obj_2.get_red(), obj_2.get_green(), obj_2.get_blue());
	obj_2.rect_status();

	system("pause");
	return 0;
}