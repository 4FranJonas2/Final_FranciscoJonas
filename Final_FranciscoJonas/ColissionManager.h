#pragma once

#include "Player.h"
#include "Matrix.h"

namespace gameColision
{
	void CheckNextCellPlayer(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player);
	void UpdatePlayerCellNone(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player);
	void UpdatePlayerCellWall(gameMatrix::Matrix matrix[][MAX_COLS], gamePlayer::Player& player);
}