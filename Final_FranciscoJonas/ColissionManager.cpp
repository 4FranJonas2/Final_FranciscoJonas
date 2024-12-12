#include "ColissionManager.h"

namespace gameColision
{
	void CheckNextCellPlayer(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player, SCENEMANAGER& simStat, gamePlayer::DIRECTION playerdir)
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
			CheckWhoLose(matrix, player, simStat);
			//UpdatePlayerWhenColision(matrix, player);
		}

		if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::COLORP1)
		{
			CheckWhoLose(matrix, player, simStat);
			//UpdatePlayerWhenColision(matrix, player);
		}

		if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::COLORP2)
		{
			CheckWhoLose(matrix, player, simStat);
			//UpdatePlayerWhenColision(matrix, player);
		}

		//if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::PLAYER && playerdir != gamePlayer::DIRECTION::STOP)
		//{
		//	CheckWhoLose(matrix, player, simStat);
		//	//UpdatePlayerWhenColision(matrix, player);
		//}
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

	void CheckWhoLose(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player, SCENEMANAGER& simStat)
	{
		if (player.isPlayer1 && player.playerIsAlive)
		{
			player.gameOver = true;
			player.playerIsAlive = false;
			player.MatchesLost++;
			simStat = SCENEMANAGER::WINLOSE;
		}
		else if (!player.isPlayer1 && player.player2IsAlive)
		{
			player.gameOver = true;
			player.player2IsAlive = false;
			player.MatchesLost++;
			simStat = SCENEMANAGER::WINLOSE;
		}
	}
}