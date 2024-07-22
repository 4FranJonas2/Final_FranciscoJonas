#pragma once
#include "Constants.h"
#include "Utils.h"
#include "Matrix.h"
#include "Player.h"

const char noneChar = ' ';
const char playerChar = ' ';

void DrawWhiteCube(char characterToDraw);
void DrawOrangeCube(char characterToDraw);
void DrawArena(Player player, const char noneChar, const char playerChar);
void DrawGameplay(Player player, const char noneChar, const char playerChar);