#pragma once
#include <iostream>
#include<Windows.h>
#include <conio.h>

using namespace std;

//simControl
const bool simEnd = false;

//Menu control
const char ESC = 27;

//Menu position
const int menuPosX = 10;
const int menuPosY = 2;

//console size
const int WIDTH = 100;
const int HEIGHT = 50;

//arena size
const int MAX_ROWS = 40;
const int MAX_COLS = 20;

//arena draw position
const int arenaDrawPosX = 40;
const int arenaDrawPosY = 5;

//colors
const int white = 255;
const int orange = 97;
const int transparent = 7;
const int RED = 204;
const int BLUE = 153;

//font
const int fontSizeX = 10;
const int fontSizeY = 15;
const char noneChar = ' ';
const char playerChar = ' ';