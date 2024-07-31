#pragma once
#include "Update.h"

void InputPlayer1(Player& player, Matrix matrix[MAX_ROWS][MAX_COLS], DIRECTION& playerDir);
void InputPlayer2(Player& player, Matrix matrix[MAX_ROWS][MAX_COLS], DIRECTION& playerDir);
void InputInMenu(MENU& menu);
int CheckBotMove(int move, int lastMove);