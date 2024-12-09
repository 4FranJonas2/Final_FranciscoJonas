#pragma once

#include "Utils.h"

namespace gameMatrix
{
	enum class CellType
	{
		NONE = 1,
		PLAYER,
		COLORP1,
		COLORP2,
		WALL
	};

	struct Matrix
	{
		CellType type = CellType::NONE;
	};

	void InitMatrix(Matrix matrix[][MAX_COLS], Vector2 playerPos);

	void DrawPlayer(char characterToDraw);
	void DrawWallCell(char characterToDraw);
	void DrawColorCell(int characterToDraw);
	void DrawCellPlayer(Matrix matrix[][MAX_COLS]);
	void DrawMatrix(Matrix matrix[][MAX_COLS]);
}