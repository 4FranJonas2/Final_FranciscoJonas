#include "Utils.h"
#include <iostream>
#include<Windows.h>
#include "Constants.h"

void SetWindowSize()
{
    // Obtener el manejador de la consola
    HANDLE hConsola = GetStdHandle(STD_OUTPUT_HANDLE);

    // Crear una estructura de tipo COORD para definir el nuevo tamaño del buffer de la consola
    COORD nuevoTamanoBuffer = { static_cast<SHORT>(WIDTH), static_cast<SHORT>(HEIGHT) };

    // Cambiar el tamaño del buffer
    if (!SetConsoleScreenBufferSize(hConsola, nuevoTamanoBuffer)) {
        std::cerr << "Error al cambiar el tamaño del buffer de la consola." << std::endl;
        return;
    }

    // Crear una estructura de tipo SMALL_RECT para definir el nuevo tamaño de la ventana de la consola
    SMALL_RECT nuevoTamanoVentana = { 0, 0, static_cast<SHORT>(WIDTH - 1), static_cast<SHORT>(HEIGHT - 1) };

    // Cambiar el tamaño de la ventana
    if (!SetConsoleWindowInfo(hConsola, TRUE, &nuevoTamanoVentana)) {
        std::cerr << "Error al cambiar el tamaño de la ventana de la consola." << std::endl;
        return;
    }

}

void Gotoxy(int posX, int posY)
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    COORD dwPos;
    dwPos.X = posX;
    dwPos.Y = posY;

    SetConsoleCursorPosition(hCon, dwPos);
}

void HideCursor()
{
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);

    CONSOLE_CURSOR_INFO cci;
    cci.dwSize = 2;
    cci.bVisible = false;

    SetConsoleCursorInfo(hCon, &cci);
}

bool IsCorrectInput(int& userInput)
{
    bool isCorrect = true;
    cin >> userInput;

    if (!cin)
        isCorrect = false;

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    return isCorrect;
}

bool IsCorrectInput(char& userInput)
{
    bool isCorrect = true;
    cin >> userInput;

    if (!cin)
        isCorrect = false;

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    return isCorrect;
}

bool IsCorrectInput(string& userInput)
{
    cin >> userInput;

    cin.clear();
    cin.ignore(INT_MAX, '\n');

    return true;
}