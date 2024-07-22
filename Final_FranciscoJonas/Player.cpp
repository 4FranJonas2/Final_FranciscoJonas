#include "Player.h"
#include <iostream>

Player SetPlayerPosition(Player& auxPlayer, int xStartposition, int yStartPosition)
{
	//posicion inicial MainPlayer
	
	auxPlayer.nextPosX = xStartposition;
	auxPlayer.nextPosY = yStartPosition;
	auxPlayer.posX = auxPlayer.nextPosX;
	auxPlayer.posY = auxPlayer.nextPosY;

	return auxPlayer;
}