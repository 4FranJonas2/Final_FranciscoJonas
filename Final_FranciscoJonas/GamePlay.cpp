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
	bool isReset = false;

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
		system("cls");
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
			if (player.gameOver)
			{
				InitGameEntities();
				player.gameOver = false;
			}
			break;
		case SCENEMANAGER::PLAY:
			gamePlayer::UpdatePlayer(player, playerDir);
			gamePlayer::UpdatePlayer(player2, playerDir2);
			gameColision::CheckNextCellPlayer(matrix, player, simStat, playerDir);
			gameColision::CheckNextCellPlayer(matrix, player2, simStat, playerDir2);
			AddPoints();
			break;
		case SCENEMANAGER::CREDITS:
			gameMenus::UpdateMainMenu(simStat);
			break;
		case SCENEMANAGER::RULES:
			gameMenus::UpdateMainMenu(simStat);
			break;
		case SCENEMANAGER::PAUSE:
			gameMenus::UpdatePauseMenu(simStat, player.gameOver, isReset);
			break;
		case SCENEMANAGER::RESET:
			InitGameEntities();
			break;
		case SCENEMANAGER::RESUME:
			simStat = SCENEMANAGER::PLAY;
			break;
		case SCENEMANAGER::WINLOSE:		
			gameMenus::UpdatePauseMenu(simStat, player.gameOver, isReset);
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
		case SCENEMANAGER::PAUSE:
			gameMenus::DrawPause();
			gameMatrix::DrawCell(matrix);
			break;
		case SCENEMANAGER::PLAY:
			gamePlayer::DrawGamePlayUI(player.MatchesWon, player.MatchesLost, player.cellColored,
				player.kills, player.death, player.points, player.isPlayer1);

			gamePlayer::DrawGamePlayUI(player2.MatchesWon, player2.MatchesLost, player2.cellColored,
				player2.kills, player2.death, player2.points, player2.isPlayer1);

			gameMatrix::DrawCell(matrix);
			Sleep(50);
			break;
		case SCENEMANAGER::RESET:
			gamePlayer::DrawGamePlayUI(player.MatchesWon, player.MatchesLost, player.cellColored,
				player.kills, player.death, player.points, player.isPlayer1);

			gamePlayer::DrawGamePlayUI(player2.MatchesWon, player2.MatchesLost, player2.cellColored,
				player2.kills, player2.death, player2.points, player2.isPlayer1);

			gameMatrix::DrawCell(matrix);
			break;
		case SCENEMANAGER::WINLOSE:
			gamePlayer::DrawGamePlayUI(player.MatchesWon, player.MatchesLost, player.cellColored,
				player.kills, player.death, player.points, player.isPlayer1);

			gamePlayer::DrawGamePlayUI(player2.MatchesWon, player2.MatchesLost, player2.cellColored,
				player2.kills, player2.death, player2.points, player2.isPlayer1);

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
		if (simStat == SCENEMANAGER::NONE || simStat == SCENEMANAGER::RESET || simStat == SCENEMANAGER::MENU)
		{
			//segun se necesite reiniciar vuelve a inicar la matrix y player a default
			bool isPlayer1;
			system("cls");
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
			if (isReset)
			{
				gameMatrix::DrawCell(matrix);
				playerDir = gamePlayer::DIRECTION::STOP;
				playerDir2 = gamePlayer::DIRECTION::STOP;
				simStat = SCENEMANAGER::PLAY;
				isReset = false;
			}
		}
	}
	void AddPoints()
	{
		if (player.isPlayer1 && player.playerIsAlive && !player2.playerIsAlive && !player2.wallDeath)
		{
			player.kills++;
			player.MatchesWon++;
			player.points += 100;
		}
		else if (!player.isPlayer1 && player2.playerIsAlive && !player.playerIsAlive && !player.wallDeath)
		{
			player2.kills++;
			player2.MatchesWon++;
			player2.points += 100;
		}
	}
}