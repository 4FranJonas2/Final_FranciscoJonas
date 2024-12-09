#include "ColissionManager.h"

namespace gameColision
{
	void CheckNextCellPlayer(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player)
	{
		if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::NONE)
		{
			player.cellColored++;
			UpdatePlayerCellNone(matrix, player);
		}

		else if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::WALL)
		{
			UpdatePlayerCellWall(matrix, player);
		}

		else if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::COLORP1
			|| matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::COLORP2)
		{
			player.gameOver = true;
			player.playerIsAlive = false;
			player.MatchesLost++;
		}

		else if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::PLAYER)
		{
			player.gameOver = true;
			player.MatchesLost++;
		}
	}
	void UpdatePlayerCellNone(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player)
	{
		matrix[player.posX][player.posY].type = gameMatrix::CellType::COLORP1;
		//matrix[player.posX][player.posY].type = CellType::COLORP2;
		player.posX = player.nextPosX;
		player.posY = player.nextPosY;
		matrix[player.posX][player.posY].type = gameMatrix::CellType::PLAYER;
	}
	void UpdatePlayerCellWall(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player)
	{
		matrix[player.posX][player.posY].type = gameMatrix::CellType::PLAYER;
		player.nextPosX = player.posX;
		player.nextPosY = player.posY;
		player.posX = player.nextPosX;
		player.posY = player.nextPosY;
		matrix[player.posX][player.posY].type = gameMatrix::CellType::PLAYER;
	}
}