#pragma once
#include <iostream>
#include <Windows.h>
#include "Matrix.h"

enum class DIRECTION
{
	STOP = 1,
	LEFT,
	RIGHT,
	UP,
	DOWN
};


struct Player
{
	//position
	int posX = 0;
	int posY = 0;
	int nextPosX = 0;
	int nextPosY = 0;
	//stats
	char playerName = 0;
	int points = 0;
	int timeplayed = 0;
	int death = 0;
	int kills = 0;
	int cellColored = 0;
	int MatchesWon = 0;
	int MatchesLost = 0;
	//spawns
	int initPlayerPosX = 2;
	int initPlayerPosY = 2;
	//playerstatus
	bool gameOver = false;
};

DIRECTION playerDir;
Player player;

Player playerSetUp(Player& auxPlayer, Matrix matrix[MAX_ROWS][MAX_COLS], int spawnPosX, int spawnPosY);