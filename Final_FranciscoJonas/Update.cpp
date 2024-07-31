#include "Update.h"

void UpdatePlayerCellNone(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player)
{
	matrix[player.posX][player.posY].type = CellType::COLORP1;
	player.posX = player.nextPosX;
	player.posY = player.nextPosY;
	matrix[player.posX][player.posY].type = CellType::PLAYER;
}

void UpdatePlayer2CellNone(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player)
{
	matrix[player.posX][player.posY].type = CellType::COLORP2;
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

void CheckNextCellPlayer1(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player)
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

void CheckNextCellPlayer2(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player)
{
	if (matrix[player.nextPosX][player.nextPosY].type == CellType::NONE)
	{
		player.cellColored++;
		UpdatePlayer2CellNone(matrix, player);
	}

	else if (matrix[player.nextPosX][player.nextPosY].type == CellType::WALL)
	{
		UpdatePlayerCellWall(matrix, player);
	}

	else if (matrix[player.nextPosX][player.nextPosY].type == CellType::COLORP1)
	{
		player.gameOver = true;
		player.player2IsAlive = false;
		player.kills++;
		player.MatchesWon++;
	}

	else if (matrix[player.nextPosX][player.nextPosY].type == CellType::COLORP2)
	{
		player.gameOver = true;
		player.player2IsAlive = false;
	}

	else if (matrix[player.nextPosX][player.nextPosY].type == CellType::PLAYER)
	{
		player.gameOver = true;
	}
}

void UpdatePause(Player& player, Player& player2, SimulationStatus& simulation, MainMenu& mainMenu, MENU& menu)
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

void UpdateTryAgain(Player& player, Player& player2, SimulationStatus& simulation, MainMenu& mainMenu, MENU& menu, Matrix matrix[MAX_ROWS][MAX_COLS], DIRECTION playerDir, DIRECTION playerDir2)
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

	case 't':
	case 'T':
		system("cls");
		player.gameOver = false;
		player2.gameOver = false;
		player.playerIsAlive = true;
		player2.player2IsAlive = true;
		matrixSetUp(matrix);
		playerSetUp(player, matrix, player.initPlayerPosX, player.initPlayerPosY, playerDir);
		playerSetUp(player2, matrix, player2.initPlayer2PosX, player2.initPlayer2PosY, playerDir2);
		break;

	default:
		break;
	}

}

void GameLogicpPayer1(Player& player, DIRECTION& playerDir, Matrix matrix[MAX_ROWS][MAX_COLS])
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

void GameLogicpPayer2(Player& player, DIRECTION& playerDir, Matrix matrix[MAX_ROWS][MAX_COLS])
{
	switch (playerDir)
	{
	case DIRECTION::STOP:
		break;

	case DIRECTION::LEFT:
		player.nextPosX--;
		CheckNextCellPlayer2(matrix, player);
		break;

	case DIRECTION::RIGHT:
		player.nextPosX++;
		CheckNextCellPlayer2(matrix, player);
		break;

	case DIRECTION::UP:
		player.nextPosY--;
		CheckNextCellPlayer2(matrix, player);
		break;

	case DIRECTION::DOWN:
		player.nextPosY++;
		CheckNextCellPlayer1(matrix, player);
		break;

	default:
		break;
	}
}