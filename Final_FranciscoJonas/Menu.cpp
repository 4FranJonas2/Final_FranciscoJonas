#include "Menu.h"

using namespace std;

void MenuLogic(MainMenu& mainMenu, SimulationStatus& simulation, MENU& menu)
{
	switch (menu)
	{
	case MENU::PLAY:
		mainMenu.menuOk = true;
		simulation.playGameOk = true;
		simulation.pauseStatus = false;
		break;

	case MENU::RULES:
		DrawRules();
		break;

	case MENU::CREDITS:
		DrawCredits();
		break;

	case MENU::EXIT:
		mainMenu.menuOk = true;
		simulation.pauseStatus = true;
		simulation.menuStatus = true;
		simulation.endSimulation = true;
		break;

	default:
		break;
	}
}

void Menu(MainMenu& mainMenu, SimulationStatus& simulation, MENU& menu)
{
	menu = MENU::NUL;

	do
	{
		if (menu == MENU::NUL)
		{
			DrawMainMenu();
		}
		InputInMenu(menu);
		MenuLogic(mainMenu, simulation, menu);

	} while (!mainMenu.menuOk);

}