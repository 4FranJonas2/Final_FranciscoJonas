#include "Player.h"
#include <iostream>
#include "Matrix.h"

Player playerSetUp(Player& auxPlayer, Matrix matrix[MAX_ROWS][MAX_COLS], int spawnPosX, int spawnPosY)
{

	auxPlayer.gameOver = false;
	bool pauseStatus = false;
	bool menuStatus = false;
	bool endSimulation = false;
	DIRECTION playerDir = DIRECTION::STOP;

	//spawn point

	auxPlayer.nextPosX = spawnPosX;
	auxPlayer.nextPosY = spawnPosY;
	auxPlayer.posX = auxPlayer.nextPosX;
	auxPlayer.posY = auxPlayer.nextPosY;

	matrix[auxPlayer.posX][auxPlayer.posY].type = CellType::PLAYER;

	return auxPlayer;
}