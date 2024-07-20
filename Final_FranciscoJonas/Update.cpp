#include "Update.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Constants.h"
#include "Utils.h"
#include "Matrix.h"

//input
Player PlayerUpdate(Player auxPlayer)
{
	MatchStatus game;
	Matrix matrix[MAX_ROWS][MAX_COLS];
	Player Auxplayer;

	char userInput = _getch();

	//update
	switch (userInput)
	{
	case 'w':
	case 'W':
		Auxplayer.nextPosY--;
		break;

	case 'a':
	case 'A':
		Auxplayer.nextPosX--;
		break;

	case 's':
	case 'S':
		Auxplayer.nextPosY++;
		break;

	case 'd':
	case 'D':
		Auxplayer.nextPosX++;
		break;

	case 'p':
	case 'P':
		game.exitSimulation = true;
		break;

	case 'e':
	case 'E':
		matrix[Auxplayer.posY][Auxplayer.posX].type = CellType::NONE;
		break;

	default:
		break;
	}

	if (Auxplayer.nextPosX < 0)
		Auxplayer.nextPosX = 0;
	else if (Auxplayer.nextPosX >= MAX_COLS)
		Auxplayer.nextPosX = MAX_COLS - 1;

	if (Auxplayer.nextPosY < 0)
		Auxplayer.nextPosY = 0;
	else if (Auxplayer.nextPosY >= MAX_ROWS)
		Auxplayer.nextPosY = MAX_ROWS - 1;

	Auxplayer.posX = Auxplayer.nextPosX;
	Auxplayer.posY = Auxplayer.nextPosY;

	return Auxplayer;
}

