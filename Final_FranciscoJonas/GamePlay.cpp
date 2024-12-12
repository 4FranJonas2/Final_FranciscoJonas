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
		//SetWindowSize();
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
		HideCursor();
		ChangeConsoleFont(fontSizeX, fontSizeY);
		InitGameEntities();
		simStat = SCENEMANAGER::MENU;
	}
	void Input()
	{
		switch (simStat)
		{
		case SCENEMANAGER::NONE:
			break;
		case SCENEMANAGER::PLAY:
			gamePlayer::InputPlayer(player, playerDir, simStat);
			gamePlayer::InputPlayer(player2, playerDir2, simStat);
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
			InitGameEntities();
			break;
		case SCENEMANAGER::PLAY:
			gamePlayer::UpdatePlayer(player, playerDir);	
			gamePlayer::UpdatePlayer(player2, playerDir2);
			gameMenus::UpdateInGameMenu(simStat,player.gameOver);
			gameColision::CheckNextCellPlayer(matrix, player);
			gameColision::CheckNextCellPlayer(matrix, player2);
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
			InitGameEntities();
			break;
		case SCENEMANAGER::RESUME:

			simStat = SCENEMANAGER::PLAY;
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
		case SCENEMANAGER::MENU:
			gameMenus::DrawMainMenu();
			break;
		case SCENEMANAGER::CREDITS:
			gameMenus::DrawCredits();
			break;
		case SCENEMANAGER::RULES:
			gameMenus::DrawRules();
			break;
		case SCENEMANAGER::PAUSE:
			gameMenus::DrawPause();
			gameMatrix::DrawCell(matrix);
			break;
		case SCENEMANAGER::PLAY:
			gamePlayer::DrawGamePlayUI(player.MatchesWon,player.MatchesLost, player.cellColored, player.kills, player.death, player.points);
			gameMatrix::DrawCell(matrix);
			//Draw(matrix, player);
			//gameMatrix::DrawMatrix(matrix);
			//gameMatrix::DrawPlayer(playerChar);
			//gameMatrix::DrawWallCell(noneChar);
			//gameMatrix::DrawColorCell(player.cellColored.)
			//gameMatrix::DrawCellPlayer(matrix);
			Sleep(50);
			break;
		case SCENEMANAGER::RESET:
			gamePlayer::DrawGamePlayUI(player.MatchesWon, player.MatchesLost, player.cellColored, player.kills, player.death, player.points);
			gameMatrix::DrawCell(matrix);
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
	void InitGameEntities()
	{
		bool isPlayer1;

		gameMatrix::InitMatrix(matrix, player.spawnPos, player2.spawnPos);
		isPlayer1 = true;
		gamePlayer::InitPlayer(player, playerDir, isPlayer1);
		isPlayer1 = false;
		gamePlayer::InitPlayer(player2, playerDir, isPlayer1);
		if (!matchEnd)
		{
			playerDir = gamePlayer::DIRECTION::STOP;
			playerDir2 = gamePlayer::DIRECTION::STOP;
		}
	}
}









































