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
			PastGrid[row][column] = 0;
		}
	}
}

void Grid::ClearCurrentGrid()
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

/*
int Grid::EdgeCell(int row, int column)
{
	
	if (row == numRows)
	{
		return 1;
	}
	if (row == 0)
	{
		return 3;
	}
	if (column == 0)
	{
		return 4;
	}
	if (column == numCols)
	{
		return 2;
	}
}
*/

bool Grid::NotLeftEdge(int column)
{
	if (column == 0)
	{
		return false;
	}
	return true;
}

bool Grid::NotRightEdge(int column)
{
	if (column == numCols)
	{
		return false;
	}
	return true;
}

bool Grid::NotTopEdge(int row)
{
	if (row == 0)
	{
		return false;
	}
	return true;
}

bool Grid::NotBottomEdge(int row)
{
	if (row == numRows)
	{
		return false;
	}
	return true;
}

void Grid::CurrentToPast()
{
	for (int CtProw = 0; CtProw < numRows; CtProw++)
	{
		for (int CtPcolumn = 0; CtPcolumn < numCols; CtPcolumn++){

			PastGrid[CtProw][CtPcolumn] = CurrentGrid[CtProw][CtPcolumn];
		}
	}
}
