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
	srand(time(0));

	Player player;
	MatchStatus game;

	DrawArena(posx, posy);

	do
	{
		char userInput = _getch();

		PlayerUpdate(player,userInput);

		DrawGameplay();

	} while (!game.exitSimulation);

}
