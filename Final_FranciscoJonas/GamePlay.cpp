#pragma once
#include "GamePlay.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Menu.h"
#include "Utils.h"

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

		//InitCleanSpace();
		playerSetUp(player, matrix, player.initPlayerPosX, player.initPlayerPosY);
		matrixSetUp(matrix);

		do
		{
			//menu loop
			do
			{
				Menu();

			} while (!mainMenu.menuOk);

			Draw(matrix, player);

			do
			{
				//pause loop
				while (!player.gameOver)
				{
					//gameplay loop
					InputInGame(player, matrix);
					GameLogic(player);
					DrawGamePlayMenu(player);
					DrawMatrixCell(matrix, player);
					Sleep(50);
				}

				UpdatePause(player);

			} while (!simulation.pauseStatus);

		} while (!simulation.menuStatus);

	} while (!simulation.endSimulation);
}








































