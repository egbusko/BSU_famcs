#include "MyClass.h"
#include <iostream>
#include <string>
#include <windows.h>
#include <cmath>


rectangle::rectangle() {
	x1 = 800; 	y1 = 400;
	x2 = 1300;	y2 = 700;
}
rectangle::rectangle(int x_1, int y_1, int x_2, int y_2) {
	x1 = x_1;	 y1 = y_1;
	x2 = x_2;	 y2 = y_2;
}
rectangle::rectangle(const rectangle &other) {
	x1 = other.x1;	 y1 = other.y1;
	x2 = other.x2;	 y2 = other.y2;
}
rectangle::~rectangle() {
	cout << "Deleting object\n";
}

void rectangle::square_or_not()
{
	if (x2 - x1 == y2 - y1)
		cout << "This is square\n";
	else
		cout << "This is NOT square\n";
}

bool rectangle::win_square_or_not()
{
	if (x2 - x1 == y2 - y1)
		return 1;
	else
		return 0;
}


void rectangle::painting_rect()
{
	/* »щем окно и берем его под контороль дл€ выполнени€ операций интеpфейса GDI */
	HWND console = FindWindow("ConsoleWindowClass", NULL);
	HDC dc = GetDC(console);
	HBRUSH hBrushBlueKing = CreateSolidBrush(RGB(134, 255, 5));

	SelectObject(dc, hBrushBlueKing);
	Rectangle(dc, x1, y1, x2, y2);
}

void rectangle::painting_rect(int r_c, int g_c, int b_c) {
	HWND console = FindWindow("ConsoleWindowClass", NULL);
	HDC dc = GetDC(console);
	HBRUSH hBrushBlueKing = CreateSolidBrush(RGB(r_c, g_c, b_c));

	SelectObject(dc, hBrushBlueKing);
	Rectangle(dc, x1, y1, x2, y2);
}

void rectangle::string_status()
{
	cout << "Rectangle with coordinates: (" << x1 << "," << y1 << ") and (" << x2 << "," << y2 << ")\n";
}




///////////////////////////////////////////////////////////////////////////////////
int image_rect::get_red() {
	return red_color;
}
int image_rect::get_green() {
	return green_color;
}
int image_rect::get_blue() {
	return blue_color;
}

image_rect::image_rect() :rectangle()
{
	red_color = 126;
	green_color = 5;
	blue_color = 255;
	text = "Purple rectangle";
}
image_rect::image_rect(int r_c, int g_c, int b_c, string txt) :rectangle()
{
	red_color = r_c;
	green_color = g_c;
	blue_color = b_c;
	text = txt;
}
image_rect::image_rect(int x_1, int y_1, int x_2, int y_2, int r_c, int g_c, int b_c, string txt) :rectangle(x_1, y_1, x_2, y_2)
{
	red_color = r_c;
	green_color = g_c;
	blue_color = b_c;
	text = txt;
}


int image_rect::perimeter_diagonal()
{
	int res, perimeter, diagonal;
	perimeter = (x2 - x1) * 2 + (y2 - y1) * 2;
	diagonal = sqrt((x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1));
	res = perimeter * diagonal;
	return res;
}


void image_rect::rect_status()
{
	cout << "-------------------------------------------\n";
	string_status();
	square_or_not();
	cout << "Perimeter*diagonal  =  " << perimeter_diagonal() << " square pixels\n"
		<< "Text of rectangle - " << text << endl;
	cout << "-------------------------------------------\n";
}

//char image_rect::rect_stat_win()
//{
//	//cout << "-------------------------------------------\n";
//	string str;
//	str[0] = x1 / 100 + 48;
//	str[1] = x1 % 100-	+ 48;
//
//	//string_status();
//	//square_or_not();
//	cout << "Perimeter*diagonal  =  " << perimeter_diagonal() << " square pixels\n"
//		<< "Text of rectangle - " << text << endl;
//	cout << "-------------------------------------------\n";
//}