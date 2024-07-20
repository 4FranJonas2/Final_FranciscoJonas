#pragma once
#include "Constants.h"
#include "Utils.h"
#include "Matrix.h"

struct MatchStatus
{
	bool exitSimulation = false;
	bool siteSelection = false;
};

Player PlayerUpdate(Player auxPlayer);