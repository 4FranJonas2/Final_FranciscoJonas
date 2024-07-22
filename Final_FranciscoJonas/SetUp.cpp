#include "SetUp.h"
#include <iostream>

void SetUp(Player& player)
{
	//posicion inicial MainPlayer
	
	player = SetPlayerPosition(player, player.mainPlayerStartPosX, player.mainplayerStartPosY);
	
}