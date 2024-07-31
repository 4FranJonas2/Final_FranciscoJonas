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
void UpdatePlayer2CellNone(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void UpdatePlayerCellWall(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void CheckNextCellPlayer1(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void CheckNextCellPlayer2(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void UpdatePause(Player& player, Player& player2, SimulationStatus& simulation, MainMenu& mainMenu, MENU& menu);
void UpdateTryAgain(Player& player, Player& player2, SimulationStatus& simulation, MainMenu& mainMenu, MENU& menu, Matrix matrix[MAX_ROWS][MAX_COLS], DIRECTION playerDir, DIRECTION playerDir2);
void GameLogicpPayer1(Player& player, DIRECTION& playerDir, Matrix matrix[MAX_ROWS][MAX_COLS]);
void GameLogicpPayer2(Player& player, DIRECTION& playerDir, Matrix matrix[MAX_ROWS][MAX_COLS]);

