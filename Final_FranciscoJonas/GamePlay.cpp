#pragma once
#include "GamePlay.h"

namespace gamePlay
{
	DIRECTION playerDir;
	DIRECTION playerDir2;
	Player player;
	Player player2;
	Matrix matrix[MAX_ROWS][MAX_COLS];
	SCENEMANAGER simStat;

	//main loop del juego
	void GameLoop()
	{
		srand(time(0));
		// simulation loop
		Init();

		while (simStat != SCENEMANAGER::NONE)
		{
			Input();
			Update();
			Draw();
		}



		//pause loop
		while (!simulation.pauseStatus)
		{
			

			//gameplay loop
			while (!player.gameOver && !player2.gameOver)
			{



			}

			if (!player.playerIsAlive || !player2.player2IsAlive)
			{
			}
			else
			{
				UpdatePause(player, player2, simulation, mainMenu, menu);
			}
		}


	}


	void Init()
	{
		//SetWindowSize();
		HideCursor();
		ChangeConsoleFont(fontSizeX, fontSizeY);
		matrixSetUp(matrix);
		playerSetUp(player, matrix, player.initPlayerPosX, player.initPlayerPosY, playerDir);
		playerSetUp(player2, matrix, player2.initPlayer2PosX, player2.initPlayer2PosY, playerDir2);

	}
	void Input()
	{
		switch (simStat)
		{
		case SCENEMANAGER::NONE:
			break;
		case SCENEMANAGER::MENU:
			break;
		case SCENEMANAGER::CREDITS:
			break;
		case SCENEMANAGER::PLAY:
			InputPlayer1(player, matrix, playerDir);
			InputPlayer2(player2, matrix, playerDir2);
			break;
		case SCENEMANAGER::RESET:
			break;
		case SCENEMANAGER::RESUME:
			break;
		case SCENEMANAGER::WINLOSE:
			break;
		case SCENEMANAGER::EXIT:
			break;
		default:
			break;
		}
	}
	void Update()
	{
		switch (simStat)
		{
		case SCENEMANAGER::NONE:
			break;
		case SCENEMANAGER::MENU:
			break;
		case SCENEMANAGER::CREDITS:
			break;
		case SCENEMANAGER::PLAY:
			GameLogicpPayer1(player, playerDir, matrix);
			GameLogicpPayer2(player2, playerDir2, matrix);
			break;
		case SCENEMANAGER::RESET:
			break;
		case SCENEMANAGER::RESUME:
			break;
		case SCENEMANAGER::WINLOSE:
			UpdateTryAgain(player, player2, simulation, matrix, playerDir, playerDir2);

			break;
		case SCENEMANAGER::EXIT:
			break;
		default:
			break;
		}
	}
	void Draw()
	{
		switch (simStat)
		{
		case SCENEMANAGER::NONE:
			break;
		case SCENEMANAGER::MENU:
			break;
		case SCENEMANAGER::CREDITS:
			break;
		case SCENEMANAGER::PLAY:
			Draw(matrix, player);
			DrawGamePlayMenu(player);
			DrawGamePlayMenu(player);
			DrawMatrixCellPlayer1(matrix, player);
			DrawMatrixCellPlayer2(matrix, player2);
			Sleep(50);
			break;
		case SCENEMANAGER::RESET:
			break;
		case SCENEMANAGER::RESUME:
			break;
		case SCENEMANAGER::WINLOSE:
			DrawResetMenu();
			break;
		case SCENEMANAGER::EXIT:
			break;
		default:
			break;
		}
	}
}









































