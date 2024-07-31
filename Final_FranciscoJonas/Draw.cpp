#include "Draw.h"

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

void DrawColorCell(int characterToDraw)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), characterToDraw);
	cout << noneChar;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), transparent);
}

void DrawMatrixCellPlayer1(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player)
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

			else if (matrix[i][j].type == CellType::COLORP1)
			{
				Gotoxy(arenaDrawPosX + i, arenaDrawPosY + j);
				DrawColorCell(BLUE);
			}
		}
	}
}

void DrawMatrixCellPlayer2(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player)
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

			else if (matrix[i][j].type == CellType::COLORP2)
			{
				Gotoxy(arenaDrawPosX + i, arenaDrawPosY + j);
				DrawColorCell(RED);
			}
		}
	}
}

void DrawGamePlayMenu(Player& player)
{
	Gotoxy(menuPosX, menuPosY);

	cout << "  GAME STATS" << endl;
	cout << "\n" << endl;
	cout << "  Matches Won: " << player.MatchesWon << endl;
	cout << "  Matches Lost: " << player.MatchesLost << endl;
	cout << "\n" << endl;
	cout << "  CellColored: " << player.cellColored << endl;
	cout << "\n";
	cout << "  Kills: " << player.kills << endl;
	cout << "  Deaths: " << player.death << endl;
	cout << "\n";
	cout << "  Points: " << player.points << endl;
	cout << "\n\n";
	cout << "  Press P to PAUSE game." << endl;
	cout << "\n";
	cout << "  On PAUSE: " << endl;
	cout << "  Press ESC to back MENU." << endl;
	cout << "  Press R to RESUME game." << endl;
	cout << "\n\n" << endl;
}

void Draw(Matrix matrix[MAX_ROWS][MAX_COLS], Player& auxPlayer)
{
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

			case CellType::COLORP1:
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
	Gotoxy(0, arenaDrawPosY);

	cout << "        CREDITS " << endl;
	cout << "\n\n" << endl;
	cout << "  Made by FRANCISCO JONAS" << endl;
	cout << "\n" << endl;
	cout << "    FINAL INTEGRADOR" << endl;
	cout << "\n\n" << endl;
	cout << "  Press ESC to go back..." << endl;
	cout << "\n" << endl;
}

void DrawMainMenu()
{
	Gotoxy(0, menuPosY);

	cout << "      TRON " << endl;
	cout << "     by Fran" << endl;
	cout << "\n";
	cout << "      MENU  " << endl;
	cout << "\n\n";
	cout << "  1.  PLAY " << endl;
	cout << "\n";
	cout << "  2.  RULES " << endl;
	cout << "\n";
	cout << "  3. CREDITS " << endl;
	cout << "\n";
	cout << "  4.  EXIT " << endl;
	cout << "\n\n";
}

void DrawRules()
{
	Gotoxy(0, arenaDrawPosY);

	cout << "        RULES " << endl;
	cout << "\n\n";
	cout << "  Use  WASD to move and draw lines." << endl;
	cout << "\n";
	cout << "  Won by making your opponent crash into your line or theirs " << endl;
	cout << "\n";
	cout << "  If you hit a Colored line or the other player, you lose." << endl;
	cout << "\n";
	cout << "  Press ESC to go back..." << endl;
}

void DrawResetMenu()
{
	Gotoxy(0, arenaDrawPosY + MAX_COLS);

	cout << "        MATCH ENDS " << endl;
	cout << "\n\n";
	cout << "  Press T to reset and continue playing." << endl;
	cout << "\n";
	cout << "  Press ESC to go back... " << endl;
}