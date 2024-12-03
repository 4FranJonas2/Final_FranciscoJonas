#pragma once

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

namespace gameMatrix
{
	void MatrixInit(Matrix matrix[][MAX_COLS]);
	void DrawPlayerCell(char characterToDraw);
	void DrawWallCell(char characterToDraw);
	void DrawColorCell(int characterToDraw);
	void DrawCellPlayer(Matrix matrix[][MAX_COLS]);
	void DrawMatrix(Matrix matrix[][MAX_COLS]);
}