#pragma once
#include "Player.h"


//void DrawWhiteCube(char characterToDraw);
//void DrawOrangeCube(char characterToDraw);

void DrawPlayerCell(char characterToDraw);
void DrawWallCell(char characterToDraw);
void DrawColorCell(char characterToDraw);
void DrawMatrixCell(Matrix matrix[MAX_ROWS][MAX_COLS], Player& player);
void DrawGamePlayMenu(Player& player);
void Draw(Matrix matrix[MAX_ROWS][MAX_COLS], Player& auxPlayer);
void DrawCredits();
void DrawMainMenu();