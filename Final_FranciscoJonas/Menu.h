#pragma once

#include "Utils.h"

namespace gameMenus
{
	void UpdateMainMenu(SCENEMANAGER& simStat);
	void UpdateInGameMenu(SCENEMANAGER& simStat, bool& endGame);
	
	void DrawCredits();
	void DrawMainMenu();
	void DrawRules();
	void DrawWinLoseMenu();
	void DrawPause();
	void DrawExitMenu();
}
