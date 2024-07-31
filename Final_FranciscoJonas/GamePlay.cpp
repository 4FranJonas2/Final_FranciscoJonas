#pragma once
#include "GamePlay.h"

//main loop del juego
void GameLoop()
{
	DIRECTION playerDir;
	DIRECTION playerDir2;
	Player player;
	Player player2;
	Matrix matrix[MAX_ROWS][MAX_COLS];
	MainMenu mainMenu;
	SimulationStatus simulation;
	MENU menu;

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
			playerSetUp(player2, matrix, player2.initPlayer2PosX, player2.initPlayer2PosY, playerDir2);

			//pause loop
			while (!simulation.pauseStatus)
			{
				Draw(matrix, player);
				DrawGamePlayMenu(player);

				//gameplay loop
				while (!player.gameOver && !player2.gameOver)
				{
					InputPlayer1(player, matrix, playerDir);
					InputPlayer2(player2, matrix, playerDir2);
					GameLogicpPayer1(player, playerDir, matrix);
					GameLogicpPayer2(player2, playerDir2, matrix);
					DrawGamePlayMenu(player);
					DrawMatrixCellPlayer1(matrix, player);
					DrawMatrixCellPlayer2(matrix, player2);
					Sleep(50);
				}

				if (!player.playerIsAlive || !player2.player2IsAlive)
				{
					DrawResetMenu();
					UpdateTryAgain(player, player2, simulation, mainMenu, menu, matrix, playerDir, playerDir2);
				}
				else
				{
					UpdatePause(player, player2, simulation, mainMenu, menu);
				}
			}
		} while (!simulation.menuStatus);
	} while (!simulation.endSimulation);
}








































