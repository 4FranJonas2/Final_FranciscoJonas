#include "Menu.h"

using namespace std;

namespace gameMenus
{
	void Input()
	{

	}
	void Update(SCENEMANAGER& simStat)
	{
		if (_kbhit())
		{
			switch (_getch())
			{
			case '1':
				system("cls");
				simStat = SCENEMANAGER::PLAY;
				break;

			case '2':
				system("cls");
				simStat = SCENEMANAGER::PLAY;
				break;

			case '3':
				system("cls");
				simStat = SCENEMANAGER::PLAY;
				break;

			case '4':
				system("cls");
				simStat = SCENEMANAGER::PLAY;
				break;

			case ESC:
				system("cls");
				simStat = SCENEMANAGER::PLAY;
				break;

			default:
				break;
			}
		}
	}
	void Draw(SCENEMANAGER simStat)
	{
		switch (simStat)
		{
		case SCENEMANAGER::NONE:
			break;
		case SCENEMANAGER::MENU:
			DrawMainMenu();
			break;
		case SCENEMANAGER::PLAY:
			break;
		case SCENEMANAGER::CREDITS:
			DrawCredits();
			break;
		case SCENEMANAGER::RULES:
			DrawRules();
			break;
		case SCENEMANAGER::RESET:
			break;
		case SCENEMANAGER::RESUME:
			break;
		case SCENEMANAGER::WINLOSE:
			DrawResetMenu();
			break;
		case SCENEMANAGER::EXIT:
			break;
		default:
			break;
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
		cout << "\n";
		cout << "  Press ESC to go back..." << endl;
	}
	void DrawResetMenu()
	{
		Gotoxy(0, arenaDrawPosY + MAX_COLS);

		cout << "        MATCH ENDS " << endl;
		cout << "\n\n";
		cout << "  Press T to reset and continue playing." << endl;
		cout << "\n";
		cout << "  Press ESC to go back... " << endl;
	}
}
