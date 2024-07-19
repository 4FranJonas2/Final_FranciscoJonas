#include "Draw.h"
#include "Constants.h"
#include "Utils.h"
#include <iostream>
#include <Windows.h>

void DrawWhiteCube()
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
	cout << "  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void DrawOrangeCube()
{
	
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), orange);
	cout << "  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void DrawArenaLimits(const int posx, const int posy)
{

	ChangeConsoleFont(fontSizeX, fontSizeY);

	Gotoxy(posx, posy);
	DrawOrangeCube();
	for (int i = 0; i < cols; i++)
	{
		Gotoxy((posx+i)+1, posy);
		DrawOrangeCube();
		//DrawOrangeCube();
	}
	DrawOrangeCube();	
	cout << endl;

	for (int i = 0; i < rows+1; i++)
	{
		Gotoxy(posx, (posy+i)+1);
		DrawOrangeCube();

		for (int j = 0; j < cols; j++)
			cout << "  ";
		
		DrawOrangeCube();
		cout << endl;
	}

	Gotoxy(posx, posy + cols);
	DrawOrangeCube();
	for (int i = 0; i < cols; i++)
	{
		DrawOrangeCube();
	}

	DrawOrangeCube();
	cout << endl;
	cout << endl;

}