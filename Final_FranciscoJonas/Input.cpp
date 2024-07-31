#include "Input.h"

void InputPlayer1(Player& player, Matrix matrix[MAX_ROWS][MAX_COLS], DIRECTION& playerDir)
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

void InputPlayer2(Player& player, Matrix matrix[MAX_ROWS][MAX_COLS], DIRECTION& playerDir)
{
	int possibleMoves = 4;
	int move = 0;
	int lastMove = 0;

	move = rand() % possibleMoves;
	move = CheckBotMove(move, lastMove);

	switch (move)
	{
	case 1:
		playerDir = DIRECTION::LEFT;
		lastMove = move;
		break;

	case 2:
		playerDir = DIRECTION::RIGHT;
		lastMove = move;
		break;

	case 3:
		playerDir = DIRECTION::UP;
		lastMove = move;
		break;

	case 4:
		playerDir = DIRECTION::DOWN;
		lastMove = move;
		break;

	default:
		break;
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

int CheckBotMove(int move, int lastMove)
{
	int possibleMoves = 4;
	int newMove = 0;

	bool upNoDown = (lastMove == (move - 1));
	bool downNoUp = (lastMove == (move + 1));
	bool leftNoRight = (lastMove == (move - 1));

	if (upNoDown)
	{
		do
		{
			newMove = rand() % possibleMoves;

		} while (!upNoDown);
	}

	else if (downNoUp)
	{
		do
		{
			newMove = rand() % possibleMoves;

		} while (!downNoUp);
	}

	else if (leftNoRight)
	{
		do
		{
			newMove = rand() % possibleMoves;

		} while (!leftNoRight);
	}

	return newMove;
}