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
			player.wallDeath = true;
		}

		//si se colisiona con la estela del player 1
		if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::COLORP1)
		{
			CheckWhoLose(matrix, player, simStat);
		}

		//si se coliciona con la estela del player 2
		if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::COLORP2)
		{
			CheckWhoLose(matrix, player, simStat);
		}

		//colision entre players
		if (matrix[player.nextPosX][player.nextPosY].type == gameMatrix::CellType::PLAYER && playerdir != gamePlayer::DIRECTION::STOP)
		{
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
	void CheckWhoLose(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player, SCENEMANAGER& simStat)
	{
		if (player.isPlayer1)
		{
			player.gameOver = true;
			player.playerIsAlive = false;
			player.MatchesLost++;
			player.death++;
			simStat = SCENEMANAGER::WINLOSE;
		}
		else if (!player.isPlayer1 )
		{
			player.gameOver = true;
			player.playerIsAlive = false;
			player.MatchesLost++;
			player.death++;
			simStat = SCENEMANAGER::WINLOSE;
		}
	}
}