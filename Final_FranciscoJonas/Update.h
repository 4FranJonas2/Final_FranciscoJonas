#pragma once
#include "Constants.h"
#include "Utils.h"
#include "Matrix.h"
#include "Player.h"

enum class Movemments
{
	STOP = 1,
	UP,
	DOWN,
	RIGTH,
	LEFT
};

struct MatchStatus
{
	bool exitSimulation = false;
	bool siteSelection = false;
};

//Movemments dir;

Player PlayerUpdate(Player& auxPlayer);