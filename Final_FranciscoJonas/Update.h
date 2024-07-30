#pragma once
#include "Player.h"

struct SimulationStatus
{
	bool pauseStatus = false;
	bool menuStatus = false;
	bool endSimulation = false;
	bool playGameOk = false;
};

struct MainMenu
{
	bool menuOk = false;

};

MainMenu mainMenu;
SimulationStatus simulation;

void UpdatePlayerCellNone(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void UpdatePlayerCellWall(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void CheckNextCell(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void UpdatePause(Player& player);
void GameLogic(Player& player);