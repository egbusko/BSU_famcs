#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>  
#include <string>  
#include "MyClass.h"


#define TXT 1
#define X1 2
#define Y1 3
#define X2 4
#define Y2 5

#define RED 6
#define GREEN 7
#define BLUE 8
#define B 9

// The string that appears in the application's title bar.  
static TCHAR szTitle[] = _T("Rectangles application / C_5_win");
static TCHAR szWindowClass[] = _T("win32app");

HINSTANCE hInst;
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);

int CALLBACK WinMain(
	_In_ HINSTANCE hInstance,
	_In_ HINSTANCE hPrevInstance,
	_In_ LPSTR     lpCmdLine,
	_In_ int       nCmdShow
)
{
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_APPSTARTING);
	wcex.hbrBackground = (HBRUSH)(3);

	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	

	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"), _T("Win32 Guided Tour"), NULL);
		return 1;
	}

	hInst = hInstance;

	// The parameters to CreateWindow explained:  
	// szWindowClass: the name of the application  
	// szTitle: the text that appears in the title bar  
	// WS_OVERLAPPEDWINDOW: the type of window to create  
	// CW_USEDEFAULT, CW_USEDEFAULT: initial position (x, y)  
	// 500, 100: initial size (width, length)  
	// NULL: the parent of this window  
	// NULL: this application does not have a menu bar  
	// hInstance: the first parameter from WinMain  
	// NULL: not used in this application  
	HWND hWnd = CreateWindow( szWindowClass, szTitle, WS_OVERLAPPEDWINDOW, CW_USEDEFAULT, CW_USEDEFAULT, 
		1000, 600, NULL,NULL, hInstance, NULL);

	HWND edit_text = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | WS_BORDER, 150, 5, 100, 20, hWnd, (HMENU)TXT, hInstance, NULL);
	HWND edit_x1 = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | ES_NUMBER | WS_BORDER, 150, 30, 100, 20, hWnd, (HMENU)X1, hInstance, NULL);
	HWND edit_y1 = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | ES_NUMBER | WS_BORDER, 150, 55, 100, 20, hWnd, (HMENU)Y1, hInstance, NULL);
	HWND edit_x2 = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | ES_NUMBER | WS_BORDER, 150, 80, 100, 20, hWnd, (HMENU)X2, hInstance, NULL);
	HWND edit_y2 = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | ES_NUMBER | WS_BORDER, 150, 105, 100, 20, hWnd, (HMENU)Y2, hInstance, NULL);
	
	HWND edit_red = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | ES_NUMBER | WS_BORDER, 150, 130, 100, 20, hWnd, (HMENU)RED, hInstance, NULL);
	HWND edit_green = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | ES_NUMBER | WS_BORDER, 150, 155, 100, 20, hWnd, (HMENU)GREEN, hInstance, NULL);
	HWND edit_blue = CreateWindow("edit", "", WS_VISIBLE | WS_CHILD | ES_NUMBER | WS_BORDER, 150, 180, 100, 20, hWnd, (HMENU)BLUE, hInstance, NULL);
	HWND button = CreateWindow("button", "Count", WS_VISIBLE | WS_CHILD, 150, 210, 100, 20, hWnd, (HMENU)B, hInstance, NULL);

	if (!hWnd)
	{
		MessageBox(NULL, _T("Call to CreateWindow failed!"), _T("Win32 Guided Tour"), NULL);
		return 1;	
	}

	ShowWindow(hWnd,nCmdShow);
	UpdateWindow(hWnd);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}



LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	PAINTSTRUCT ps;
	HDC hdc;
	
	static char is_sq[] = "Is square";
	static char isnt_sq[] = "Is not square";

	static char *temp = new char[1024];
	static int x1_ = 0, y1_ = 0, x2_ = 0, y2_ = 0, red_ = 0, green_ = 0, blue_ = 0;
	static char *out = new char[1000];
	static string str;
	

	TCHAR text_rect[] = _T("Enter text of   rect: ");
	TCHAR x1_koord[] = _T("Enter   x1    koord: ");
	TCHAR y1_koord[] = _T("Enter   y1    koord: ");
	TCHAR x2_koord[] = _T("Enter   x2    koord: ");
	TCHAR y2_koord[] = _T("Enter   y2    koord: ");
	TCHAR r_color[] = _T("Enter  red     color: ");
	TCHAR g_color[] = _T("Enter  green color: ");
	TCHAR b_color[] = _T("Enter  blue   color: ");

	HWND text = GetDlgItem(hWnd, TXT);
	HWND x1 = GetDlgItem(hWnd, X1);
	HWND y1 = GetDlgItem(hWnd, Y1);
	HWND x2 = GetDlgItem(hWnd, X2);
	HWND y2 = GetDlgItem(hWnd, Y2);
	HWND red = GetDlgItem(hWnd, RED);
	HWND green = GetDlgItem(hWnd, GREEN);
	HWND blue = GetDlgItem(hWnd, BLUE);

	switch (message)
	{

	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);

		TextOut(hdc, 5, 5, text_rect, _tcslen(text_rect));
		TextOut(hdc, 5, 30, x1_koord, _tcslen(x1_koord));
		TextOut(hdc, 5, 55, y1_koord, _tcslen(y1_koord));
		TextOut(hdc, 5, 80, x2_koord, _tcslen(x2_koord));
		TextOut(hdc, 5, 105, y2_koord, _tcslen(y2_koord));

		TextOut(hdc, 5, 130, r_color, _tcslen(r_color));
		TextOut(hdc, 5, 155, g_color, _tcslen(g_color));
		TextOut(hdc, 5, 180, b_color, _tcslen(b_color));

		EndPaint(hWnd, &ps);


		if (y2_ != 0)
		{
			hdc = GetDC(hWnd);
			image_rect rect_win(x1_, y1_, x2_, y2_, red_, green_, blue_, out);
			int squ = rect_win.win_square_or_not();
			HBRUSH brush;
			brush = CreateSolidBrush(RGB(red_, green_, blue_));
			SelectObject(hdc, brush);
			Rectangle(hdc, x1_, y1_, x2_, y2_);
			DeleteObject(brush);

			TextOut(hdc, x1_ + (x2_ - x1_) / 4, y1_ + (y2_ - y1_) / 2, out, strlen(out));

			if(squ==1)
				TextOut(hdc, x1_ + (x2_ - x1_) / 4, y1_ + (y2_ - y1_) / 4, is_sq, strlen(is_sq));
			else 
				TextOut(hdc, x1_ + (x2_ - x1_) / 4, y1_ + (y2_ - y1_) / 4, isnt_sq, strlen(isnt_sq));

			ReleaseDC(hWnd, hdc);
		}
		break;
	case WM_COMMAND:
		if (LOWORD(wParam) == B)
		{
			GetWindowText(x1, temp, 4);		x1_ = atoi(temp);
			GetWindowText(y1, temp, 4);		y1_ = atoi(temp);
			GetWindowText(x2, temp, 4); 	x2_ = atoi(temp);
			GetWindowText(y2, temp, 4);		y2_ = atoi(temp);

			GetWindowText(red, temp, 4);	red_ = atoi(temp);
			GetWindowText(green, temp, 4);	green_ = atoi(temp);
			GetWindowText(blue, temp, 4);	blue_ = atoi(temp); 
			GetWindowText(text, temp, 7);	out = temp;
			InvalidateRect(hWnd, nullptr, FALSE);
			//InvalidateRect( hWnd, const RECT *lpRect,				BOOL       bErase			);
		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}
	return 0;
}