#include "Menu.h"

#include <iostream>
#include "Utils.h"

using namespace std;

MENU menu;

void MenuLogic()
{
	switch (menu)
	{
	case MENU::PLAY:
		system("cls");
		mainMenu.menuOk = true;
		simulation.playGameOk = true;
		break;

	case MENU::RULES:
		system("cls");

		break;

	case MENU::CREDITS:
		system("cls");
		DrawCredits();
		menu = MENU::NUL;
		break;

	case MENU::EXIT:
		simulation.menuStatus = true;
		simulation.endSimulation = true;
		break;

	default:
		break;
	}
}

void Menu()
{
	Gotoxy(menuPosX, menuPosY);

	DrawMainMenu();
	InputInMenu();
	MenuLogic();

}