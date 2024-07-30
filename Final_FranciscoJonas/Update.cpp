#include "Update.h"



void UpdatePlayerCellNone(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player)
{
	matrix[player.posX][player.posY].type = CellType::COLOR;
	player.posX = player.nextPosX;
	player.posY = player.nextPosY;
	matrix[player.posX][player.posY].type = CellType::PLAYER;
}

void UpdatePlayerCellWall(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player)
{
	matrix[player.posX][player.posY].type = CellType::PLAYER;
	player.nextPosX = player.posX;
	player.nextPosY = player.posY;
	player.posX = player.nextPosX;
	player.posY = player.nextPosY;
	matrix[player.posX][player.posY].type = CellType::PLAYER;
}

void CheckNextCell(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player)
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

	else if (matrix[player.nextPosX][player.nextPosY].type == CellType::COLOR)
	{
		player.gameOver = true;

	}

	else if (matrix[player.nextPosX][player.nextPosY].type == CellType::PLAYER)
	{
		player.gameOver = true;
	}
}

void UpdatePause(Player& player,SimulationStatus& simulation,MainMenu& mainMenu, MENU& menu)
{
	switch (_getch())
	{

	case ESC:
		system("cls");
		player.gameOver = false;
		simulation.pauseStatus = true;
		mainMenu.menuOk = false;
		menu = MENU::NUL;
		break;

	case 'r':
	case 'R':
		player.gameOver = false;
		break;

	default:
		break;
	}
}

void GameLogic(Player& player, DIRECTION& playerDir, Matrix matrix[MAX_ROWS][MAX_COLS])
{
	switch (playerDir)
	{
	case DIRECTION::STOP:
		break;

	case DIRECTION::LEFT:
		player.nextPosX--;
		CheckNextCell(matrix, player);
		break;

	case DIRECTION::RIGHT:
		player.nextPosX++;
		CheckNextCell(matrix, player);
		break;

	case DIRECTION::UP:
		player.nextPosY--;
		CheckNextCell(matrix, player);
		break;

	case DIRECTION::DOWN:
		player.nextPosY++;
		CheckNextCell(matrix, player);
		break;

	default:
		break;
	}
}