#include "GamePlay.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>


//main loop del juego
void GameLoop()
{
	srand(time(0));
	HideCursor();

	Player player;
	MatchStatus game;

	DrawArena(player,noneChar,playerChar);

	SetUp(player);

	do
	{
		player = PlayerUpdate(player);

		DrawGameplay(player,noneChar,playerChar);

	} while (!game.exitSimulation);

}
