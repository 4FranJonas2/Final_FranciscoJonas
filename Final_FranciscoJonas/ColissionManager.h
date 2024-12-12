#pragma once

#include "Player.h"
#include "Matrix.h"

namespace gameColision
{
	void CheckNextCellPlayer(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player, SCENEMANAGER& simStat, gamePlayer::DIRECTION playerdir
		, int nextPosXP1, int nextPosYP1, int nextPosXP2, int nextPosYP2);
	void UpdatePlayerCellNone(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player);
	void UpdatePlayerWhenColision(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player);
	void CheckWhoLose(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player, SCENEMANAGER& simStat);
}