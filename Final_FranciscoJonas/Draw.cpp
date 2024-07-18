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

void DrawOrangeCube(int posX,int posY)
{
	Gotoxy(posX, posY);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), orange);
	cout << "  ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
}

void DrawArenaLimits(const int posx, const int posy)
{
	ChangeConsoleFont(fontSizeX, fontSizeY);

	DrawOrangeCube(posx,posy);
	for (int i = 0; i < cols; i++)
	{
		DrawOrangeCube(posx+i, posy);
	}

	DrawOrangeCube(posx*2, posy);
	cout << endl;
	for (int i = 0; i < rows; i++)
	{
		DrawOrangeCube(posx+i, posy);
		for (int j = 0; j < cols; j++)
		{
			cout << "  ";
		}
		DrawOrangeCube(posx*2, posy+i);
		cout << endl;
	}
	DrawOrangeCube(((posx*2)-1),((posy*2)-1));

	for (int i = 0; i < cols; i++)
	{
		DrawOrangeCube(posx, posy+i);
	}
	DrawOrangeCube(posx, posy);
	cout << endl;
	cout << endl;

}