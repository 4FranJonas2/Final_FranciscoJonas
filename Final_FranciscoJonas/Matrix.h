#pragma once
#include "Constants.h"
#include "Utils.h"
#include "Player.h"

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



