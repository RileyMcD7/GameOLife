#include "grid.h"
#include <iostream>
#include "colors.h"


Grid::Grid()
{
	numRows = 20;
	numCols = 10;
	cellSize = 30;
	Initialize();  
	colors = GetCellColors();
}

void Grid::Initialize()
{
	for (int row = 0; row < numRows; row++) {
		for (int column = 0; column < numCols; column++) {
			CurrentGrid[row][column] = 0;
		}
	}
}

void Grid::Print()
{
	for (int row = 0; row < numRows; row++) {
		for (int column = 0; column < numCols; column++) {
			std::cout << CurrentGrid[row][column] << "";
		}
		std::cout << std::endl;
	}
}

void Grid::Draw()
{
	for (int row = 0; row < numRows; row++)
	{
		for (int column = 0; column < numCols; column++)
		{
			int cellValue = CurrentGrid[row][column];  //so we can fill the grid with 1s for life   might need this to be PastGrid just how main file is set up
			DrawRectangle(column * cellSize + 11, row * cellSize + 11, cellSize - 1, cellSize - 1, colors[cellValue]);
		}
	}
}

bool Grid::IsCellOutside(int row, int column)
{
	if (row >= 0 && row < numRows && column >= 0 && column < numCols)
	{
		return false;
	}
	return true;
}


bool Grid::IsCellEmpty(int row, int column)
{
	if (PastGrid[row][column] == 0)
	{
		return true;
	}
	return false;
}
