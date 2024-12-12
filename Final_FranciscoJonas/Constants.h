#pragma once
#include <iostream>
#include<Windows.h>
#include <conio.h>

using namespace std;

//simControl
const bool simEnd = false;
const bool matchEnd = false;


//Menu control
const char ESC = 27;
const char UP = 72;
const char DOWN = 80;
const char RIGHT = 77;
const char LEFT = 75;

//Menu position
const int menuPosX = 10;
const int menuPosY = 2;

//console size
const int WIDTH = 50;
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

//spawn pos
const int initPlayerPosX = 2;
const int initPlayerPosY = 2;
const int initPlayer2PosX = (MAX_ROWS - 3);
const int initPlayer2PosY = (MAX_COLS - 3);
