#pragma once
#include "Constants.h"



enum class CellType
{
	NONE = 1,
	PLAYER,
	COLOR,
	WALL
};

struct Matrix
{
	CellType type = CellType::NONE;
};

Matrix matrix[MAX_ROWS][MAX_COLS];

void matrixSetUp(Matrix matrix[MAX_ROWS][MAX_COLS]);

