#include "GamePlay.h"
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include "Constants.h"
#include "Menu.h"
#include "Utils.h"
#include "Draw.h"
#include "Update.h"

//main loop del juego
void GameLoop()
{
	MatchStatus game;
	Player player;
	DrawArena(posx, posy);

	do
	{
		DrawGameplay();
		PlayerUpdate(player);

	} while (!game.exitSimulation);

}
