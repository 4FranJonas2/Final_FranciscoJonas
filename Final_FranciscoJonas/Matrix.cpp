#include "Matrix.h"

void matrixSetUp(Matrix matrix[MAX_ROWS][MAX_COLS])
{
	//seteo muros borde superior
	for (int j = 0; j < MAX_COLS; j++)
	{
		matrix[0][j].type = CellType::WALL;
	}

	//seteo muros borde inferior
	for (int j = 0; j < MAX_COLS; j++)
	{
		matrix[MAX_ROWS - 1][j].type = CellType::WALL;
	}

	//seteo muros izquierda
	for (int i = 0; i < MAX_ROWS; i++)
	{
		matrix[i][0].type = CellType::WALL;
	}

	//seteo muros derecha
	for (int i = 0; i < MAX_ROWS; i++)
	{
		matrix[i][MAX_COLS - 1].type = CellType::WALL;
	}
}
