#pragma once
#include "GamePlay.h"

DIRECTION playerDir;
Player player;
Matrix matrix[MAX_ROWS][MAX_COLS];
MainMenu mainMenu;
SimulationStatus simulation;
MENU menu;

//main loop del juego
void GameLoop()
{
	srand(time(0));
	// simulation loop
	do
	{
		//SetWindowSize();
		HideCursor();
		ChangeConsoleFont(fontSizeX, fontSizeY);

		//menu loop
		do
		{
			Menu(mainMenu, simulation, menu);

			matrixSetUp(matrix);
			playerSetUp(player, matrix, player.initPlayerPosX, player.initPlayerPosY, playerDir);
			//pause loop
			while (!simulation.pauseStatus)
			{
				Draw(matrix, player);

				//gameplay loop
				while (!player.gameOver)
				{
					InputInGame(player, matrix, playerDir);
					GameLogic(player, playerDir, matrix);
					DrawGamePlayMenu(player);
					DrawMatrixCell(matrix, player);
					Sleep(50);
				}

				UpdatePause(player, simulation, mainMenu, menu);
			}
		} while (!simulation.menuStatus);
	} while (!simulation.endSimulation);
}








































