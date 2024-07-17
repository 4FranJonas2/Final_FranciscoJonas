#include "Draw.h"
#include "Constants.h"
#include "Utils.h"
#include <iostream>

void DrawWhiteCube()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 40);
	cout << "  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}


void Drawpixel()
{
	//Get a console handle
	HWND myconsole = GetConsoleWindow();
	//Get a handle to device context
	HDC mydc = GetDC(myconsole);

	int pixel = 0;

	//Choose any color
	COLORREF COLOR = RGB(255, 255, 255);

	//Draw pixels
	for (double i = 0; i < PI * 4; i += 0.05)
	{
		SetPixel(mydc, pixel, (int)(50 + 25 * cos(i)), COLOR);
		pixel += 1;
	}

	ReleaseDC(myconsole, mydc);
	cin.ignore();
}

void SetPixel()
{
	Gotoxy(posx, posy);
	Drawpixel();
}

void DrawArenaLimits()
{
	DrawWhiteCube();
	for (int i = 0; i < cols; i++)
	{
		DrawWhiteCube();
	}
	DrawWhiteCube();
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		cout << (i + 1);
		cout << " ";
		for (int j = 0; j < cols; j++)
		{
			cout << "  ";
		}
		cout << (i + 1) << endl;
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 219);
	cout << "  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	for (int i = 0; i < cols; i++)
	{
		cout << (i + 1);
		cout << " ";
	}
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 219);
	cout << "  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << endl;
	cout << endl;

}