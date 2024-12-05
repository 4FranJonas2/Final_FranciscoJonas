#pragma once
#include "GamePlay.h"

#include "ColissionManager.h"
#include "Utils.h"
#include "Menu.h"


namespace gamePlay
{
	gamePlayer::DIRECTION playerDir;
	gamePlayer::DIRECTION playerDir2;
	gamePlayer::Player player;
	gamePlayer::Player player2;
	gameMatrix::Matrix matrix[MAX_ROWS][MAX_COLS];
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
	}


	void Init()
	{
		//SetWindowSize();
		HideCursor();
		ChangeConsoleFont(fontSizeX, fontSizeY);
		gameMatrix::InitMatrix(matrix, player.spawnPos);
		gamePlayer::InitPlayer(player, playerDir);
		gamePlayer::InitPlayer(player2, playerDir);
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
			gamePlayer::InputPlayer(player, playerDir);
			gamePlayer::InputPlayer(player2, playerDir2);
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
			gameMenus::UpdateMainMenu(simStat);
			break;
		case SCENEMANAGER::PLAY:
			gameMenus::UpdateInGameMenu(simStat,player.gameOver);
			gamePlayer::UpdatePlayer(player, playerDir);
			gamePlayer::UpdatePlayer(player2, playerDir2);
			break;
		case SCENEMANAGER::CREDITS:
			gameMenus::UpdateMainMenu(simStat);
			break;
		case SCENEMANAGER::RULES:
			gameMenus::UpdateMainMenu(simStat);
			break;
		case SCENEMANAGER::PAUSE:
			gameMenus::UpdateInGameMenu(simStat, player.gameOver);
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









































