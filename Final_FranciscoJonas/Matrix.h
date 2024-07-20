#pragma once
#include "Constants.h"

enum class CellType
{
	NONE = 1,
	PLAYER,
	COLOR
};

struct Matrix
{
	CellType type = CellType::NONE;

};

struct Player
{
	int posY = 0;
	int posX = 0;
	int nextPosY = 0;
	int nextPosX = 0;
};

