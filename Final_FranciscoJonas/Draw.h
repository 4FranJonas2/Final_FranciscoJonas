#pragma once
#include "Player.h"

enum class MENU
{
	NUL,
	PLAY,
	RULES,
	CREDITS,
	EXIT,
	PAUSE
};

void DrawPlayerCell(char characterToDraw);
void DrawWallCell(char characterToDraw);
void DrawColorCell(int characterToDraw);
void DrawMatrixCellPlayer1(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void DrawMatrixCellPlayer2(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void DrawGamePlayMenu(Player& player);
void Draw(Matrix matrix[MAX_ROWS][MAX_COLS], Player& auxPlayer);
void DrawCredits();
void DrawMainMenu();
void DrawRules();
void DrawResetMenu();