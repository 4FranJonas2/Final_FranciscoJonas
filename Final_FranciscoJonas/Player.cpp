#include "Player.h"

namespace gamePlayer
{
	Player InitPlayer(Player& auxPlayer, DIRECTION& playerDir, bool isFirstPlayer)
	{
		auxPlayer.gameOver = false;
		bool pauseStatus = false;
		bool menuStatus = false;
		bool endSimulation = false;
		auxPlayer.playerIsAlive = true;
		playerDir = DIRECTION::STOP;

		//spawn point
		if (isFirstPlayer)
		{
			auxPlayer.spawnPos.x = initPlayerPosX;
			auxPlayer.spawnPos.y = initPlayerPosY;
			auxPlayer.isPlayer1 = true;
		}
		else
		{
			auxPlayer.spawnPos.x = initPlayer2PosX;
			auxPlayer.spawnPos.y = initPlayer2PosY;
		}

		auxPlayer.nextPosX = auxPlayer.spawnPos.x;
		auxPlayer.nextPosY = auxPlayer.spawnPos.y;
		auxPlayer.posX = auxPlayer.nextPosX;
		auxPlayer.posY = auxPlayer.nextPosY;

		return auxPlayer;
	}
	void InputPlayer(Player& player, DIRECTION& playerDir, SCENEMANAGER& simStat)
	{
		if (_kbhit())
		{
			if (player.isPlayer1)
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

				case ESC:
					system("cls");
					simStat = SCENEMANAGER::PAUSE;
					break;

				default:
					break;
				}
			}

			if (!player.isPlayer1)
			{
				switch (_getch())
				{
				case UP:
					playerDir = DIRECTION::UP;
					break;

				case DOWN:
					playerDir = DIRECTION::DOWN;
					break;

				case LEFT:
					playerDir = DIRECTION::LEFT;
					break;

				case RIGHT:
					playerDir = DIRECTION::RIGHT;
					break;

				default:
					break;
				}
			}
		}
	}
	void UpdatePlayer(Player& player, DIRECTION& playerDir)
	{
		switch (playerDir)
		{
		case DIRECTION::STOP:
			break;

		case DIRECTION::LEFT:
			player.nextPosX--;
			break;

		case DIRECTION::RIGHT:
			player.nextPosX++;
			break;

		case DIRECTION::UP:
			player.nextPosY--;
			break;

		case DIRECTION::DOWN:
			player.nextPosY++;
			break;

		default:
			break;
		}
	}
	void DrawGamePlayUI(int& matchWon, int& matchLost, int& cellColored, int& kills, int& deaths, int& points)
	{
		Gotoxy(menuPosX, menuPosY);

		cout << "  GAME STATS" << endl;
		cout << "\n" << endl;
		cout << "  Matches Won: " << matchWon << endl;
		cout << "  Matches Lost: " << matchLost << endl;
		cout << "\n" << endl;
		cout << "  CellColored: " << cellColored << endl;
		cout << "\n";
		cout << "  Kills: " << kills << endl;
		cout << "  Deaths: " << deaths << endl;
		cout << "\n";
		cout << "  Points: " << points << endl;
		cout << "\n\n";
		cout << "  Press ESC to PAUSE game." << endl;
		cout << "\n\n" << endl;
	}
}