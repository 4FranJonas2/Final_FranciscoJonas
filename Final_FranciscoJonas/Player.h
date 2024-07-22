#pragma once
#include <iostream>
#include <Windows.h>
#include "Constants.h"
#include "Utils.h"

struct Player
{
	int posY = 0;
	int posX = 0;
	int nextPosY = 0;
	int nextPosX = 0;
	int mainPlayerStartPosX = MAX_ROWS / 2;
	int mainplayerStartPosY = MAX_COLS / 2;

};

Player SetPlayerPosition(Player& auxPlayer, int xStartposition, int yStartPosition);