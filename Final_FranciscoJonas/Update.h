#pragma once
#include "Draw.h"

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

void UpdatePlayerCellNone(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void UpdatePlayerCellWall(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void CheckNextCell(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void UpdatePause(Player& player, SimulationStatus& simulation, MainMenu& mainMenu, MENU& menu);
void GameLogic(Player& player, DIRECTION& playerDir, Matrix matrix[MAX_ROWS][MAX_COLS]);