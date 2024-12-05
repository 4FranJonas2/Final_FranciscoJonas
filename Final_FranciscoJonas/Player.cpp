#include "Player.h"

namespace gamePlayer
{
	Player InitPlayer(Player& auxPlayer, DIRECTION& playerDir)
	{
		auxPlayer.gameOver = false;
		bool pauseStatus = false;
		bool menuStatus = false;
		bool endSimulation = false;
		auxPlayer.playerIsAlive = true;
		playerDir = DIRECTION::STOP;

		//spawn point
		auxPlayer.nextPosX = auxPlayer.spawnPos.x;
		auxPlayer.nextPosY = auxPlayer.spawnPos.y;
		auxPlayer.posX = auxPlayer.nextPosX;
		auxPlayer.posY = auxPlayer.nextPosY;

		return auxPlayer;
	}
	void InputPlayer(Player& player, DIRECTION& playerDir)
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