#include "GamePlay.h"
#include <iostream>
#include "Constants.h"
#include "Menu.h"
#include "Utils.h"
#include "Draw.h"

//main loop del juego
void GameLoop()
{
	SetWindowSize();
	InitDraw();
	

	system("pause");
}

//dibujado incial del juego
void InitDraw()
{
	ChangeConsoleFont(fontSizeX, fontSizeY);
	//DrawArenaLimits();
	SetPixel();
}