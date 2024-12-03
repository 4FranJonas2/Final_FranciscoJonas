#pragma once

#include "Utils.h"

namespace gameMenus
{
	void Input();
	void Update(SCENEMANAGER& simStat);
	void Draw(SCENEMANAGER simStat);
	
	void DrawCredits();
	void DrawMainMenu();
	void DrawRules();
	void DrawResetMenu();
}
