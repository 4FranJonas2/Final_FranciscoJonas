#pragma once

#include "Player.h"
#include "Matrix.h"

namespace gameColision
{
	void CheckNextCellPlayer(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player, SCENEMANAGER& simStat, gamePlayer::DIRECTION playerdir);
	void UpdatePlayerCellNone(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player);
	void UpdatePlayerWhenColision(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player);
	void CheckWhoLose(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player, SCENEMANAGER& simStat);
}