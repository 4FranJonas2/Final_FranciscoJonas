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
		srand(time(NULL));
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
		bool isPlayer1;
		//SetWindowSize();
		HideCursor();
		ChangeConsoleFont(fontSizeX, fontSizeY);
		gameMatrix::InitMatrix(matrix, player.spawnPos);
		isPlayer1 = true;
		gamePlayer::InitPlayer(player, playerDir, isPlayer1);
		isPlayer1 = false;
		gamePlayer::InitPlayer(player2, playerDir, isPlayer1);
		simStat = SCENEMANAGER::MENU;
	}
	void Input()
	{
		switch (simStat)
		{
		case SCENEMANAGER::NONE:
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
			gameColision::CheckNextCellPlayer(matrix, player);
			gameColision::CheckNextCellPlayer(matrix, player2);
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
			gameMenus::UpdateMainMenu(simStat);
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
			gameMenus::DrawMainMenu();
			break;
		case SCENEMANAGER::CREDITS:
			gameMenus::DrawCredits();
			break;
		case SCENEMANAGER::RULES:
			gameMenus::DrawRules();
			break;
		case SCENEMANAGER::PLAY:
			//Draw(matrix, player);
			gamePlayer::DrawGamePlayUI(player);
			gameMatrix::DrawMatrix(matrix);
			gameMatrix::DrawPlayer(playerChar);
			gameMatrix::DrawWallCell(noneChar);
			//gameMatrix::DrawColorCell(player.cellColored.)
			gameMatrix::DrawCellPlayer(matrix);
			gameMatrix::DrawCellPlayer(matrix);
			Sleep(50);
			break;
		case SCENEMANAGER::RESET:
			break;
		case SCENEMANAGER::RESUME:
			break;
		case SCENEMANAGER::WINLOSE:
			gameMenus::DrawWinLoseMenu();
			break;
		case SCENEMANAGER::EXIT:
			gameMenus::DrawExitMenu();
			break;
		default:
			break;
		}
	}
}









































