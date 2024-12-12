#include "ColissionManager.h"

namespace gameColision
{
	void CheckNextCellPlayer(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player)
	{
		//si la siguiente celda esta vacia
		if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::NONE)
		{
			player.cellColored++;
			UpdatePlayerCellNone(matrix, player);
		}

		//si la siguiente celda es un muro
		else if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::WALL)
		{
			UpdatePlayerWhenColision(matrix, player);
		}

		if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::COLORP1)
		{
			/*player.gameOver = true;
			player.playerIsAlive = false;*/
			player.MatchesLost++;
			UpdatePlayerWhenColision(matrix, player);
		}

		if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::COLORP2)
		{
			/*player.gameOver = true;
			player.playerIsAlive = false;*/
			player.MatchesLost++;
			UpdatePlayerWhenColision(matrix, player);
		}

		if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::PLAYER)
		{
			/*player.gameOver = true;
			player.MatchesLost++;*/
			UpdatePlayerWhenColision(matrix, player);
		}
	}

	void UpdatePlayerCellNone(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player)
	{
		if (player.isPlayer1)
		{
			matrix[player.posX][player.posY].type = gameMatrix::CellType::COLORP1;
		}
		if(!player.isPlayer1)
		{
			matrix[player.posX][player.posY].type = gameMatrix::CellType::COLORP2;
		}

		player.posX = player.nextPosX;
		player.posY = player.nextPosY;
		matrix[player.posX][player.posY].type = gameMatrix::CellType::PLAYER;
	}
	void UpdatePlayerWhenColision(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player)
	{
		matrix[player.posX][player.posY].type = gameMatrix::CellType::PLAYER;
		player.nextPosX = player.posX;
		player.nextPosY = player.posY;
		player.posX = player.nextPosX;
		player.posY = player.nextPosY;
		matrix[player.posX][player.posY].type = gameMatrix::CellType::PLAYER;
	}
}