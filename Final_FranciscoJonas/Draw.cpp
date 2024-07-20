#include "Draw.h"
#include <iostream>
#include <Windows.h>
#include "Constants.h"
#include "Utils.h"
#include "Matrix.h"

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

void DrawArena(const int posx, const int posy)
{
	Matrix matrix[MAX_ROWS][MAX_COLS];

	ChangeConsoleFont(fontSizeX, fontSizeY);

	cout << "  ";
	for (int i = 0; i < MAX_COLS; i++)
	{
		cout << (i + 1);
		cout << " ";
	}
	cout << " " << endl;
	for (int i = 0; i < MAX_ROWS; i++)
	{
		cout << (i + 1);
		cout << " ";
		for (int j = 0; j < MAX_COLS; j++)
		{
			switch (matrix[i][j].type)
			{
			case CellType::NONE:
				cout << noneChar;
				break;
			default:
				break;
			}
			cout << " ";
		}
		cout << (i + 1) << endl;
	}
	cout << "  ";
	for (int i = 0; i < MAX_COLS; i++)
	{
		cout << (i + 1);
		cout << " ";
	}
	cout << " " << endl;
}

void DrawGameplay()
{
	Matrix matrix[MAX_ROWS][MAX_COLS];
	Player player;

	//draw
	system("cls");
	cout << "  ";
	for (int i = 0; i < MAX_COLS; i++)
	{
		cout << (i + 1);
		cout << " ";
	}
	cout << " " << endl;
	for (int i = 0; i < MAX_ROWS; i++)
	{
		cout << (i + 1);
		cout << " ";
		for (int j = 0; j < MAX_COLS; j++)
		{
			if (i == player.posY && j == player.posX)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 32);
			}
			switch (matrix[i][j].type)
			{
			case CellType::NONE:
				cout << noneChar;
				break;
			
			default:
				break;
			}
			if (i == player.posY && j == player.posX)
			{
				SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
			}
			cout << " ";
		}
		cout << (i + 1) << endl;
	}
	cout << "  ";
	for (int i = 0; i < MAX_COLS; i++)
	{
		cout << (i + 1);
		cout << " ";
	}
	cout << " " << endl;
}
	