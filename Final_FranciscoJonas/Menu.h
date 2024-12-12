#pragma once

#include "Utils.h"

namespace gameMenus
{
	void UpdateMainMenu(SCENEMANAGER& simStat);
	void UpdatePauseMenu(SCENEMANAGER& simStat, bool& endGame, bool& resetGame);
	
	void DrawCredits();
	void DrawMainMenu();
	void DrawRules();
	void DrawWinLoseMenu();
	void DrawPause();
	void DrawExitMenu();
}
