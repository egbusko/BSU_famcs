#include <windows.h>  
#include <stdlib.h>  
#include <string.h>  
#include <tchar.h>  
#include <cmath>
#define NUM 1000
#define TWOPI (2*3.14159)

static TCHAR szWindowClass[] = _T("win3_2app");
static TCHAR szWinName[] = _T("Test");

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);


int CALLBACK WinMain(HINSTANCE hT1, HINSTANCE hPrev, LPSTR lpszArgs, int WinMode)
{
	MSG msg;

	WNDCLASSEX wcl;

	wcl.cbSize = sizeof(WNDCLASSEX);
	wcl.lpfnWndProc = WndProc;
	wcl.style = CS_HREDRAW | CS_VREDRAW;
	
	wcl.cbClsExtra = 0;
	wcl.cbWndExtra = 0;
	wcl.hInstance = hT1;
	wcl.hIcon = LoadIcon(hT1, MAKEINTRESOURCE(IDI_APPLICATION));

	wcl.hCursor = LoadCursor(NULL, IDC_APPSTARTING);
	wcl.hbrBackground = (HBRUSH)(14);

	wcl.lpszMenuName = NULL;
	wcl.lpszClassName = szWindowClass;
	wcl.hIconSm = LoadIcon(wcl.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	
	if (!RegisterClassEx(&wcl))
	{
		
		MessageBox(NULL, _T("Call to RegisterClassEx failed!"),
			_T("Win32 Guided Tour"), NULL);
		return 1;
	}

	HWND hWnd = CreateWindow(szWindowClass, szWinName, WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, 400, 200, NULL, NULL, hT1, NULL);

	if (!hWnd)
	{
		DWORD l_error = GetLastError();
		MessageBox(NULL, _T("Call to CreateWindow failed!"),
			_T("Win32 Guided Tour"), NULL);
		return 1;
	}

	ShowWindow(hWnd, WinMode);
	UpdateWindow(hWnd);

	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

	LRESULT CALLBACK WndProc(HWND hWnd, UINT Msg, WPARAM wParam, LPARAM lParam)
	{
		WinName;
		static int cxClient, cyClient;
		HDC hdc;
		PAINTSTRUCT ps;
		int i;
		POINT pt[NUM];

		switch (Msg)
		{
		case WM_SIZE: 
					cxClient = LOWORD(lParam);
					cyClient = HIWORD(lParam);
					return 0;
		case WM_PAINT:
			hdc = BeginPaint(hWnd, &ps);

			//рисуем координатные оси
			MoveToEx(hdc, 0, cyClient / 2, NULL);
			LineTo(hdc, cxClient, cyClient / 2);
			MoveToEx(hdc, cxClient / 2, 0, NULL);
			LineTo(hdc, cxClient / 2, cyClient);
			
			//теперь рисуем стрелочки на осях
			//1:
			MoveToEx(hdc, (63 * cxClient) / 128, (2 * cyClient) / 64, NULL);
			LineTo(hdc, cxClient / 2, 0);
			MoveToEx(hdc, (65 * cxClient) / 128, (2 * cyClient) / 64, NULL);
			LineTo(hdc, cxClient / 2, 0);
			//2:
			MoveToEx(hdc, (126 * cxClient) / 128, (125 * cyClient) / 256, NULL);
			LineTo(hdc, cxClient, cyClient / 2);
			MoveToEx(hdc, (126 * cxClient) / 128, (131 * cyClient) / 256, NULL);
			LineTo(hdc, cxClient, cyClient / 2);

			for (i = 0; i < NUM; i++)
			{
				pt[i].x = i * cxClient / NUM;
				pt[i].y = (int)cyClient / 2*(1-sin(TWOPI*i/NUM));
			}
			
			////			 /\  дальше рисуем такую фигуру 
			////			 \/		+ размер массива надо поставить 2*NUM
			// 

			////			4  3
			////			 /\		-порядок прорисовки сторон
			////			 \/
			////			1  2
			////1:
			//for (i = 0; i < NUM / 2; i++)
			//{
			//	pt[i].x = i * cxClient / NUM;
			//	pt[i].y = (i * cyClient / NUM) + cyClient / 2;
			//}
			////2:
			//for (i = NUM / 2; i < NUM; i++)
			//{
			//	pt[i].x = i * cxClient / NUM;
			//	pt[i].y = pt[(NUM - i)].y;
			//}
			////3:
			//for (i = NUM; i < 3 * NUM / 2; i++)
			//{
			//	pt[i].x = pt[(2 * NUM - i)].x;
			//	pt[i].y = pt[(((-NUM) / 2) + i)].y - cyClient / 2;
			//}
			////4:
			//for (i = 3 * NUM / 2; i < 2 * NUM; i++)
			//{
			//	pt[i].x = pt[((2 * NUM) - i)].x;
			//	pt[i].y = pt[(i - (3 * NUM / 2))].y - cyClient / 2;
			//}

			Polyline(hdc, pt, NUM);
			return 0;

		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}
		return DefWindowProc(hWnd, Msg, wParam, lParam);
	}

