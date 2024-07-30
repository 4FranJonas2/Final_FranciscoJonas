#pragma once
#include "Update.h"
#include "Draw.h"
#include "Input.h"

enum class MENU
{
	NUL,
	PLAY,
	RULES,
	CREDITS,
	EXIT,
	PAUSE
};

void MenuLogic();
void Menu();