#pragma once
#include <iostream>
#include "Constants.h"

enum class SCENEMANAGER
{
	NONE,
	MENU,
	PLAY,
	CREDITS,
	RULES,
	RESET,
	RESUME,
	WINLOSE,
	EXIT
};

void SetWindowSize();

void Gotoxy(int posX, int posY);

void HideCursor();

//confirmaciones de inputs
bool IsCorrectInput(int& userInput);

bool IsCorrectInput(char& userInput);

bool IsCorrectInput(string& userInput);

void ChangeConsoleFont(int sizeX, int sizeY);