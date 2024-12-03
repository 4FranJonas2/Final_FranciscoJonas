#include "Player.h"

namespace gamePlayer
{
	Player InitPlayer(Player& auxPlayer, Matrix matrix[][MAX_COLS],
		int spawnPosX, int spawnPosY, DIRECTION& playerDir)
	{
		auxPlayer.gameOver = false;
		bool pauseStatus = false;
		bool menuStatus = false;
		bool endSimulation = false;
		auxPlayer.playerIsAlive = true;
		playerDir = DIRECTION::STOP;

		//spawn point
		auxPlayer.nextPosX = spawnPosX;
		auxPlayer.nextPosY = spawnPosY;
		auxPlayer.posX = auxPlayer.nextPosX;
		auxPlayer.posY = auxPlayer.nextPosY;

		matrix[auxPlayer.posX][auxPlayer.posY].type = CellType::PLAYER;

		return auxPlayer;
	}
	void InputPlayer1(Player& player, Matrix matrix[][MAX_COLS], DIRECTION& playerDir)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case 'a':
			case 'A':
				playerDir = DIRECTION::LEFT;
				break;

			case 'd':
			case 'D':
				playerDir = DIRECTION::RIGHT;
				break;

			case 'w':
			case 'W':
				playerDir = DIRECTION::UP;
				break;

			case 's':
			case 'S':
				playerDir = DIRECTION::DOWN;
				break;

			case 'p':
			case 'P':
				player.gameOver = true;
				break;

			default:
				break;
			}


		}
	}
	void GameLogicpPayer1(Player& player, DIRECTION& playerDir, Matrix matrix[][MAX_COLS])
	{
		switch (playerDir)
		{
		case DIRECTION::STOP:
			break;

		case DIRECTION::LEFT:
			player.nextPosX--;
			CheckNextCellPlayer1(matrix, player);
			break;

		case DIRECTION::RIGHT:
			player.nextPosX++;
			CheckNextCellPlayer1(matrix, player);
			break;

		case DIRECTION::UP:
			player.nextPosY--;
			CheckNextCellPlayer1(matrix, player);
			break;

		case DIRECTION::DOWN:
			player.nextPosY++;
			CheckNextCellPlayer1(matrix, player);
			break;

		default:
			break;
		}
	}
	void CheckNextCellPlayer(Matrix matrix[][MAX_COLS], Player& player)
	{
		if (matrix[player.nextPosX][player.nextPosY].type == CellType::NONE)
		{
			player.cellColored++;
			UpdatePlayerCellNone(matrix, player);
		}

		else if (matrix[player.nextPosX][player.nextPosY].type == CellType::WALL)
		{
			UpdatePlayerCellWall(matrix, player);
		}

		else if (matrix[player.nextPosX][player.nextPosY].type == CellType::COLORP1 || matrix[player.nextPosX][player.nextPosY].type == CellType::COLORP2)
		{
			player.gameOver = true;
			player.playerIsAlive = false;
			player.MatchesLost++;
		}

		else if (matrix[player.nextPosX][player.nextPosY].type == CellType::PLAYER)
		{
			player.gameOver = true;
			player.MatchesLost++;
		}
	}
	void UpdatePlayerCellNone(Matrix matrix[][MAX_COLS], Player& player)
	{
		matrix[player.posX][player.posY].type = CellType::COLORP1;
		//matrix[player.posX][player.posY].type = CellType::COLORP2;
		player.posX = player.nextPosX;
		player.posY = player.nextPosY;
		matrix[player.posX][player.posY].type = CellType::PLAYER;
	}
	void UpdatePlayerCellWall(Matrix matrix[][MAX_COLS], Player& player)
	{
		matrix[player.posX][player.posY].type = CellType::PLAYER;
		player.nextPosX = player.posX;
		player.nextPosY = player.posY;
		player.posX = player.nextPosX;
		player.posY = player.nextPosY;
		matrix[player.posX][player.posY].type = CellType::PLAYER;
	}
	void DrawGamePlayUI(Player& player)
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
}