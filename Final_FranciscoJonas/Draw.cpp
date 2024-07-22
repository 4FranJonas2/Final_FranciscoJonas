#include "Draw.h"
#include <iostream>
#include <Windows.h>

void DrawWhiteCube(char characterToDraw)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
	cout << characterToDraw;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), transparent);
}

void DrawOrangeCube(char characterToDraw)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), orange);
	cout << characterToDraw;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), transparent);
}

void DrawArena(Player player, const char noneChar, const char playerChar)
{
	Matrix matrix[MAX_ROWS][MAX_COLS];

	ChangeConsoleFont(fontSizeX, fontSizeY);

	system("cls");
	DrawOrangeCube(noneChar);
	for (int i = 0; i < MAX_COLS; i++)
	{
		DrawOrangeCube(noneChar);
		DrawOrangeCube(noneChar);
	}
	DrawOrangeCube(noneChar);
	cout << endl;

	for (int i = 0; i < MAX_ROWS; i++)
	{
		DrawOrangeCube(noneChar);

		for (int j = 0; j < MAX_COLS; j++)
		{
			if (i == player.posY && j == player.posX)
			{
				matrix[i][j].type = CellType::PLAYER;
			}

			switch (matrix[i][j].type)
			{
			case CellType::NONE:
				cout << noneChar;
				break;

			case CellType::PLAYER:
				DrawWhiteCube(playerChar);
				break;

			default:
				break;
			}

			cout << noneChar;
		}
		DrawOrangeCube(noneChar);

		cout << endl;
	}

	DrawOrangeCube(noneChar);
	for (int i = 0; i < MAX_COLS; i++)
	{
		DrawOrangeCube(noneChar);
		DrawOrangeCube(noneChar);
	}
	DrawOrangeCube(noneChar);
	cout << endl;
}

void DrawGameplay(Player player, const char noneChar, const char playerChar)
{
	Matrix matrix[MAX_ROWS][MAX_COLS];

	ChangeConsoleFont(fontSizeX, fontSizeY);

	//draw
	system("cls");
	DrawOrangeCube(noneChar);
	for (int i = 0; i < MAX_COLS; i++)
	{
		DrawOrangeCube(noneChar);
		DrawOrangeCube(noneChar);
	}
	DrawOrangeCube(noneChar);
	cout << endl;

	for (int i = 0; i < MAX_ROWS; i++)
	{
		DrawOrangeCube(noneChar);

		for (int j = 0; j < MAX_COLS; j++)
		{
			if (i == player.posY && j == player.posX)
			{
				matrix[i][j].type = CellType::PLAYER;
			}

			switch (matrix[i][j].type)
			{
			case CellType::NONE:
				cout << noneChar;
				break;

			case CellType::PLAYER:
				DrawWhiteCube(playerChar);
				break;

			default:
				break;
			}

			cout << noneChar;
		}
		DrawOrangeCube(noneChar);

		cout << endl;
	}

	DrawOrangeCube(noneChar);
	for (int i = 0; i < MAX_COLS; i++)
	{
		DrawOrangeCube(noneChar);
		DrawOrangeCube(noneChar);
	}
	DrawOrangeCube(noneChar);
	cout << endl;
}
