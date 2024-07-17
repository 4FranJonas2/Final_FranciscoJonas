#pragma once
#include <iostream>
#include<Windows.h>
#include "Constants.h"

void SetWindowSize();

void Gotoxy(int posX, int posY);

void HideCursor();

//confirmaciones de inputs
bool IsCorrectInput(int& userInput);

bool IsCorrectInput(char& userInput);

bool IsCorrectInput(string& userInput);

void ChangeConsoleFont(int sizeX, int sizeY);
