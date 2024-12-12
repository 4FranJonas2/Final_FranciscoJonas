#include "Menu.h"

using namespace std;

namespace gameMenus
{
	void UpdateMainMenu(SCENEMANAGER& simStat)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case '1':
				system("cls");
				if (simStat == SCENEMANAGER::EXIT)
				{
					simStat = SCENEMANAGER::NONE;
				}
				else
					simStat = SCENEMANAGER::PLAY;
				break;
			case '2':
				system("cls");
				if (simStat == SCENEMANAGER::EXIT)
				{
					simStat = SCENEMANAGER::MENU;
				}
				else
					simStat = SCENEMANAGER::RULES;
				break;
			case '3':
				system("cls");
				simStat = SCENEMANAGER::CREDITS;
				break;
			case '4':
				system("cls");
				simStat = SCENEMANAGER::EXIT;
				break;
			case ESC:
				system("cls");
				if (simStat == SCENEMANAGER::PLAY)
				{
					simStat = SCENEMANAGER::PAUSE;
				}
				if (simStat==SCENEMANAGER::CREDITS || simStat == SCENEMANAGER::RULES)
				{
					simStat = SCENEMANAGER::MENU;
				}
				break;

			default:
				break;
			}
		}
	}
	void UpdatePauseMenu(SCENEMANAGER& simStat, bool& endGame, bool& resetGame)
	{
		//Pause Menu
		if (simStat == SCENEMANAGER::PAUSE)
		{
			if (_kbhit())
			{
				switch (_getch())
				{
				case ESC:
					system("cls");
					simStat = SCENEMANAGER::RESUME;
					break;
				case '2':
					system("cls");
					simStat = SCENEMANAGER::RESET;
					resetGame = true;
					break;
				case '3':
					system("cls");
					simStat = SCENEMANAGER::MENU;
					endGame = true;
					break;
				default:
					break;
				}
			}
		}

		//WinLoseMenu
		if (simStat == SCENEMANAGER::WINLOSE)
		{
			if (_kbhit())
			{
				switch (_getch())
				{
				case ESC:
					system("cls");
					simStat = SCENEMANAGER::RESET;
					resetGame = true;
					break;
				case '3':
					system("cls");
					simStat = SCENEMANAGER::MENU;
					endGame = true;
					break;
				default:
					break;
				}
			}
		}
	}

	void DrawCredits()
	{
		Gotoxy(0, arenaDrawPosY);

		cout << "        CREDITS " << endl;
		cout << "\n\n" << endl;
		cout << "  Made by FRANCISCO JONAS" << endl;
		cout << "\n" << endl;
		cout << "    FINAL INTEGRADOR" << endl;
		cout << "\n\n" << endl;
		cout << "  Press ESC to go back..." << endl;
		cout << "\n" << endl;
	}
	void DrawMainMenu()
	{
		Gotoxy(0, menuPosY);

		cout << "      TRON " << endl;
		cout << "     by Fran" << endl;
		cout << "\n";
		cout << "      MENU  " << endl;
		cout << "\n\n";
		cout << "  1.  PLAY " << endl;
		cout << "\n";
		cout << "  2.  RULES " << endl;
		cout << "\n";
		cout << "  3. CREDITS " << endl;
		cout << "\n";
		cout << "  4.  EXIT " << endl;
		cout << "\n\n";
	}
	void DrawRules()
	{
		Gotoxy(0, arenaDrawPosY);

		cout << "        RULES " << endl;
		cout << "\n\n";
		cout << "  Use  WASD to move and draw lines." << endl;
		cout << "\n";
		cout << "  Won by making your opponent crash into your line or theirs " << endl;
		cout << "\n";
		cout << "  If you hit a Colored line or the other player, you lose." << endl;
		cout << "\n\n";
		cout << "  Press ESC to go back..." << endl;
	}
	void DrawWinLoseMenu()
	{
		Gotoxy(0, arenaDrawPosY + MAX_COLS-2);

		cout << "        MATCH ENDS " << endl;
		cout << "\n\n";
		cout << "  Press ESC to restart." << endl;
		cout << "\n";
		cout << "  Press 3 to go back to MENU " << endl;
	}
	void DrawPause()
	{
		Gotoxy(menuPosX, menuPosY);

		cout << "      GAME PAUSE" << endl;
		cout << "\n\n";
		cout << "   (ESC) to  RESUME " << endl;
		cout << "\n";
		cout << "  2.  RESET " << endl;
		cout << "\n";
		cout << "  3. BACK TO MENU " << endl;
		cout << "\n\n";
	}
	void DrawExitMenu()
	{
		Gotoxy(0, arenaDrawPosY);

		cout << "                 EXIT " << endl;
		cout << "\n\n";
		cout << "  Are you sure you want to leave de game ?" << endl;
		cout << "\n";
		cout << "     1. YES               2. NO " << endl;
	}
}