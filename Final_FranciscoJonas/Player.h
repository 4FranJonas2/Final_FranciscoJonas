#pragma once

#include "Matrix.h"
#include "Utils.h"


namespace gamePlayer
{
	enum class DIRECTION
	{
		STOP = 1,
		LEFT,
		RIGHT,
		UP,
		DOWN
	};

	struct Player
	{
		//position player 1
		int posX = 0;
		int posY = 0;
		int nextPosX = 0;
		int nextPosY = 0;
		//position player 2
		int posP2X = 0;
		int posP2Y = 0;
		int nextPosP2X = 0;
		int nextPosP2Y = 0;
		//stats
		char playerName = 0;
		int points = 0;
		int timeplayed = 0;
		int death = 0;
		int kills = 0;
		int cellColored = 0;
		int MatchesWon = 0;
		int MatchesLost = 0;
		//spawns
		int initPlayerPosX = 2;
		int initPlayerPosY = 2;
		int initPlayer2PosX = (MAX_ROWS - 3);
		int initPlayer2PosY = (MAX_COLS - 3);
		//playerstatus
		bool gameOver = false;
		bool playerIsAlive = true;
		bool player2IsAlive = true;
	};

	Player InitPlayer(Player& auxPlayer, Matrix matrix[][MAX_COLS], int spawnPosX,
		int spawnPosY, DIRECTION& playerDir);
	void InputPlayer1(Player& player, Matrix matrix[][MAX_COLS], DIRECTION& playerDir);
	void GameLogicpPayer1(Player& player, DIRECTION& playerDir, Matrix matrix[][MAX_COLS]);
	void CheckNextCellPlayer(Matrix matrix[][MAX_COLS], Player& player);
	void UpdatePlayerCellNone(Matrix matrix[][MAX_COLS], Player& player);
	void UpdatePlayerCellWall(Matrix matrix[][MAX_COLS], Player& player);
	void DrawGamePlayUI(Player& player);
}