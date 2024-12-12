#include "Player.h"

namespace gamePlayer
{
	Player InitPlayer(Player& auxPlayer, DIRECTION& playerDir, bool isPlayer1)
	{
		auxPlayer.gameOver = false;
		auxPlayer.playerIsAlive = true;
		playerDir = DIRECTION::STOP;
		auxPlayer.cellColored = 0;
		auxPlayer.wallDeath = false;

		//punto de spawn jugador 1
		if (isPlayer1)
		{
			auxPlayer.spawnPos.x = initPlayerPosX;
			auxPlayer.spawnPos.y = initPlayerPosY;
			auxPlayer.isPlayer1 = true;
			auxPlayer.playerIsAlive = true;
		}
		//punto de spawn jugador 2
		else
		{
			auxPlayer.spawnPos.x = initPlayer2PosX;
			auxPlayer.spawnPos.y = initPlayer2PosY;
			auxPlayer.playerIsAlive = true;
		}

		//seteo a los jugadores en sus posiciones inciales
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
	void DrawGamePlayUI(int& matchWon, int& matchLost, int& cellColored, int& kills, int& deaths, int& points, bool isPlayer1)
	{
		Gotoxy(menuPosX, menuPosY);

		if (isPlayer1)
		{
			cout << "  GAME STATS \n" << endl;
			cout << "  PLAYER 1 STATS: "<< endl;
			cout << "  Matches Won: " << matchWon << endl;
			cout << "  Matches Lost: " << matchLost << endl;
			cout << "  CellColored: " << cellColored << endl;
			cout << "  Kills: " << kills << endl;
			cout << "  Deaths: " << deaths << endl;
			cout << "  Points: " << points << endl;
			cout << "\n";
		}
		else
		{
			Gotoxy( 0, menuPosY+8);
			cout << "\n" << endl;
			cout << "  PLAYER 2 STATS: " << endl;
			cout << "  Matches Won: " << matchWon << endl;
			cout << "  Matches Lost: " << matchLost << endl;
			cout << "  CellColored: " << cellColored << endl;
			cout << "  Kills: " << kills << endl;
			cout << "  Deaths: " << deaths << endl;
			cout << "  Points: " << points << endl;
			cout << "\n\n";
			cout << " (while playing) Press ESC for PAUSE." << endl;
		}
		cout << "\n\n" << endl;
	}
}