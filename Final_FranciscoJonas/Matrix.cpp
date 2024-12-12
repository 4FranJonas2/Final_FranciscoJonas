#include "Matrix.h"

namespace gameMatrix
{
	void InitMatrix(Matrix matrix[][MAX_COLS], Vector2 playerPos, Vector2 player2Pos)
	{
		int playerPosX = playerPos.x;
		int playerPosY = playerPos.y;

		matrix[playerPosX][playerPosY].type = CellType::PLAYER;

		for (int i = 0; i < MAX_ROWS; i++)
		{
			for (int j = 0; j < MAX_COLS; j++)
			{
				matrix[i][j].type = CellType::NONE;
			}
		}

		//seteo muros borde superior
		for (int j = 0; j < MAX_COLS; j++)
		{
			matrix[0][j].type = CellType::WALL;
		}

		//seteo muros borde inferior
		for (int j = 0; j < MAX_COLS; j++)
		{
			matrix[MAX_ROWS - 1][j].type = CellType::WALL;
		}

		//seteo muros izquierda
		for (int i = 0; i < MAX_ROWS; i++)
		{
			matrix[i][0].type = CellType::WALL;
		}

		//seteo muros derecha
		for (int i = 0; i < MAX_ROWS; i++)
		{
			matrix[i][MAX_COLS - 1].type = CellType::WALL;
		}
	}
	void DrawCell(Matrix matrix[][MAX_COLS])
	{
		for (int i = 0; i < MAX_ROWS; i++)
		{
			for (int j = 0; j < MAX_COLS; j++)
			{
				if (matrix[i][j].type == CellType::PLAYER)
				{
					Gotoxy(arenaDrawPosX + i, arenaDrawPosY + j);
					DrawPlayer(white);
				}

				if (matrix[i][j].type == CellType::WALL)
				{
					Gotoxy(arenaDrawPosX + i, arenaDrawPosY + j);
					DrawWallCell(noneChar);
				}

				if (matrix[i][j].type == CellType::COLORP1)
				{
					Gotoxy(arenaDrawPosX + i, arenaDrawPosY + j);
					DrawColorCell(BLUE);
				}

				if (matrix[i][j].type == CellType::COLORP2)
				{
					Gotoxy(arenaDrawPosX + i, arenaDrawPosY + j);
					DrawColorCell(RED);
				}
			}
		}
	}
	
	//printean los tipos de celda en particular
	void DrawPlayer(char characterToDraw)
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
	void DrawColorCell(int characterToDraw)
	{
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), characterToDraw);
		cout << noneChar;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), transparent);
	}
}