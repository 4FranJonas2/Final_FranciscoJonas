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
		int points = 0;
		int death = 0;
		int kills = 0;
		int cellColored = 0;
		int MatchesWon = 0;
		int MatchesLost = 0;
		//spawns
		Vector2 spawnPos;
		
		//playerstatus
		bool gameOver = false;
		bool playerIsAlive = false;
		bool isPlayer1 = false;
		bool wallDeath = false;
	};

	Player InitPlayer(Player& auxPlayer, DIRECTION& playerDir, bool isPlayer1);
	void InputPlayer(Player& player, DIRECTION& playerDir, SCENEMANAGER& simStat);
	void UpdatePlayer(Player& player, DIRECTION& playerDir);
	void DrawGamePlayUI(int& matchWon, int& matchLost, int& cellColored, int& kills, int& deaths, int& points, bool isPlayer1);
}