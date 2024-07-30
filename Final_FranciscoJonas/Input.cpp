#include "Input.h"

void InputInGame(Player& player, Matrix matrix[MAX_ROWS][MAX_COLS],DIRECTION& playerDir)
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

void InputInMenu(MENU& menu)
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case '1':
			system("cls");
			menu = MENU::PLAY;
			break;

		case '2':
			system("cls");
			menu = MENU::RULES;
			break;

		case '3':
			system("cls");
			menu = MENU::CREDITS;
			break;

		case '4':
			system("cls");
			menu = MENU::EXIT;
			break;

		case ESC:
			system("cls");
			menu = MENU::NUL;
			break;

		default:
			break;
		}
	}
}