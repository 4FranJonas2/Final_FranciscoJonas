#pragma once
#include "Utils.h"

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

void matrixSetUp(Matrix matrix[MAX_ROWS][MAX_COLS]);

