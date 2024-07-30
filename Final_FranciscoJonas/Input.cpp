#include "Input.h"
#include <iostream>
#include <conio.h>
#include "Menu.h"


void InputInGame(Player& player, Matrix matrix[MAX_ROWS][MAX_COLS])
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

			/*case 'e':
			case 'E':
				player.gameOver = false;
				mainMenu.menuOk = false;
				simulation.pauseStatus = true;
				break;*/

		case 'p':
		case 'P':
			player.gameOver = true;
			break;

			/*case 'r':
			case 'R':
				player.gameOver = false;
				break;*/

		default:
			break;
		}
	}
}

void InputInMenu()
{
	MENU menu;

	if (_kbhit())
	{
		switch (_getch())
		{
		case '1':
			menu = MENU::PLAY;
			break;

		case '2':
			menu = MENU::RULES;
			break;

		case '3':
			menu = MENU::CREDITS;
			break;

		case '4':
			menu = MENU::EXIT;
			break;

		case 'ESC':
			DrawMainMenu();
			break;

		default:
			break;
		}
	}
}