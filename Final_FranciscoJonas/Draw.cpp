#include "Draw.h"
#include <iostream>
#include <Windows.h>
#include "Utils.h"

//void DrawWhiteCube(char characterToDraw)
//{
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
//	cout << characterToDraw;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), transparent);
//}
//
//void DrawOrangeCube(char characterToDraw)
//{
//
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), orange);
//	cout << characterToDraw;
//	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), transparent);
//}

void DrawPlayerCell(char characterToDraw)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), white);
	cout << characterToDraw;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), transparent);
}

void DrawWallCell(char characterToDraw)
{

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), orange);
	cout << characterToDraw;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), transparent);
}

void DrawColorCell(char characterToDraw)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), BLUE);
	cout << characterToDraw;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), transparent);
}

void DrawMatrixCell(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player)
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			if (matrix[i][j].type == CellType::PLAYER)
			{
				Gotoxy(arenaDrawPosX + i, arenaDrawPosY + j);
				DrawPlayerCell(white);
			}

			else if (matrix[i][j].type == CellType::COLOR)
			{
				Gotoxy(arenaDrawPosX + i, arenaDrawPosY + j);
				DrawColorCell(BLUE);
			}
		}
	}
}

void DrawGamePlayMenu(Player& player)
{
	Gotoxy(menuPosX, menuPosY);

	cout << " GAME STATS" << endl;
	cout << "\n" << endl;
	cout << " Matches Won: " << player.MatchesWon << endl;
	cout << " Matches Lost: " << player.MatchesLost << endl;
	cout << "\n" << endl;
	cout << " CellColored: " << player.cellColored << endl;
	cout << "\n" << endl;
	cout << " Kills: " << player.kills << endl;
	cout << " Deaths: " << player.death << endl;
	cout << "\n" << endl;
	cout << " Points: " << player.points << endl;
	cout << "\n\n" << endl;
	cout << " Press P to PAUSE game." << endl;
	cout << " Press E to back MENU." << endl;
	cout << " Press R to RESUME game." << endl;
	cout << "\n\n" << endl;

}

void Draw(Matrix matrix[MAX_ROWS][MAX_COLS], Player& auxPlayer)
{
	system("cls");

	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			Gotoxy(arenaDrawPosX + i, arenaDrawPosY + j);

			switch (matrix[i][j].type)
			{
			case CellType::NONE:
				cout << " ";
				break;

			case CellType::PLAYER:
				DrawPlayerCell(playerChar);
				break;

			case CellType::WALL:
				DrawWallCell(noneChar);
				break;

			case CellType::COLOR:
				DrawColorCell(BLUE);
				break;

			default:
				break;
			}
		}
		cout << endl;
	}
}

void DrawCredits()
{
	system("cls");

	Gotoxy(arenaDrawPosX, arenaDrawPosY);

	cout << "      CREDITS " << endl;
	cout << "\n\n" << endl;
	cout << "Made by FRANCISCO JONAS" << endl;
	cout << "\n" << endl;
	cout << "   FINAL INTEGRADOR" << endl;
	cout << "\n\n" << endl;
	cout << " Press ESC to go back..." << endl;
	cout << "\n" << endl;

	system("pause");

	system("cls");

}

void DrawMainMenu()
{

	cout << "    TRON " << endl;
	cout << "   by Fran" << endl;
	cout << "\n";
	cout << "    MENU  " << endl;
	cout << "\n\n";
	cout << "1.  PLAY " << endl;
	cout << "\n";
	cout << "2.  RULES " << endl;
	cout << "\n";
	cout << "3. CREDITS " << endl;
	cout << "\n";
	cout << "4.  EXIT " << endl;
	cout << "\n\n";
}
