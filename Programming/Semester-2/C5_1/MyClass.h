#pragma once
#include <iostream>  
#include <string>
using namespace std;


class rectangle
{
protected:
	int x1, y1;
	int x2, y2;
public:
	rectangle();
	rectangle(int x_1, int y_1, int x_2, int y_2);
	rectangle(const rectangle &other);
	~rectangle();

	void square_or_not();
	void painting_rect();
	void painting_rect(int r_c, int g_c, int b_c);
	void string_status();
};



class image_rect:public rectangle
{
protected:
	int red_color, green_color, blue_color;
	string text;

public:
	int get_red();
	int get_green();
	int get_blue();

	image_rect();
	image_rect(int r_c, int g_c, int b_c, string txt);
	image_rect(int x_1, int y_1, int x_2, int y_2, int r_c, int g_c, int b_c, string txt);
	int perimeter_diagonal();
	void rect_status();
};
