#include "game.h"
#include <iostream>

Game::Game() {
	grid = Grid();  //initialize a grid instance
	gameOver = false;
	this->numrows = grid.numRows;   //unsure if this is used correctly
	this->numcols = grid.numCols;

}

Game::~Game()
{
}

void Game::Draw()
{
	grid.Draw();
}

void Game::HandleInput()
{
	int keyPressed = GetKeyPressed();   //change to mouse input
	if (gameOver && keyPressed != 0)   //default of GetKeyPressed is 0
	{
		gameOver = false;
		Reset();
	}
	//if statement should lock input in grid area while game is in motion
	
	/*
	switch (keyPressed)     //functions like multiple if statements, end with break to end reading earler, can also use "default:" at end 
	{
	case KEY_LEFT:
		MoveBlockLeft();
		break;
	case KEY_RIGHT:
		MoveBlockRight();
		break;
	case KEY_DOWN:
		MoveBlockDown();
		UpdateScore(0, 1);
		break;
	case KEY_UP:
		RotateBlock();
		break;

	}
	*/
}



void Game::Reset() {

	grid.Initialize();

}

void Game::Generate()   //actually move to grid if we are keeping info 
{
	for (int Genrow = 0; Genrow < numrows; Genrow++) {
		for (int Gencolumn = 0; Gencolumn < numcols; Gencolumn++) {
			/*
			conditions:
			if =1 and CountNeighbors = 1 then =0
			if =1 and CountNeighbors = 2 | CountNeighbors = 3  then =1  no change
			if =1 and CountNeighbors = 4, then =0
			if =0 and CountNeighbors = 3, then =1
			*/
			switch (CountNeighbors(Genrow, Gencolumn)) {  //define thise still
			case 1:
				grid.CurrentGrid[Genrow][Gencolumn] = 0;
				break;
			case 3:
				grid.CurrentGrid[Genrow][Gencolumn] = 1;
				break;
			case 4:
				grid.CurrentGrid[Genrow][Gencolumn] = 0;
				break;
			default:
				break;
			}

			grid.CurrentToPast();
		}
	}
}

int Game::CountNeighbors(int row,int column)
{
	
	int sum = 0;

	if (grid.NotRightEdge(column)) {
		sum = sum + grid.PastGrid[row][column + 1];
		sum = sum + grid.PastGrid[row - 1][column + 1];
		sum = sum + grid.PastGrid[row + 1][column + 1];
		//std::cout << grid.PastGrid[row][column + 1];
	}
	if (grid.NotLeftEdge(column)) {
		sum = sum + grid.PastGrid[row][column - 1];
		sum = sum + grid.PastGrid[row - 1][column - 1];
		sum = sum + grid.PastGrid[row + 1][column - 1];
	}
	if (grid.NotTopEdge(row)) {
		sum = sum + grid.PastGrid[row - 1][column];
		sum = sum + grid.PastGrid[row - 1][column - 1];
		sum = sum + grid.PastGrid[row - 1][column + 1];
	}
	if (grid.NotBottomEdge(row)) {
		sum = sum + grid.PastGrid[row + 1][column];
		sum = sum + grid.PastGrid[row + 1][column - 1];
		sum = sum + grid.PastGrid[row + 1][column + 1];
		//std::cout << sum;
	}
	  //need edge cases. Can do with if statements here or by creating a bool method in grid and call it here. That is probably smarter

	/*
	how chat gpt does it:  //might be more beneficial to pass in PastGrid, so we don't access it externally every time. If speed issues persist, try that. Will need to reinvent grids though
	// Function to count neighbors around a specific cell
	int countNeighbors(const std::vector<std::vector<int>>& grid, int x, int y) {
		int count = 0;
		for (int i = -1; i <= 1; ++i) {
			for (int j = -1; j <= 1; ++j) {
				if (i == 0 && j == 0) continue;  // Skip the cell itself
				int ni = x + i;
				int nj = y + j;
				if (ni >= 0 && ni < HEIGHT && nj >= 0 && nj < WIDTH) {
					count += grid[ni][nj];
				}
			}
		}
		return count;
	}
	
	*/
	
	return sum;

}

void Game::TestCase()
{
	grid.CurrentGrid[10][6] = 1;
	grid.CurrentGrid[10][4] = 1;
	grid.CurrentGrid[9][5] = 1;
	grid.CurrentGrid[8][6] = 1;
	grid.CurrentGrid[8][4] = 1;
	grid.CurrentGrid[11][5] = 1;
	grid.PastGrid[10][6] = 1;
	grid.PastGrid[10][4] = 1;
	grid.PastGrid[9][5] = 1;
	grid.PastGrid[8][6] = 1;
	grid.PastGrid[8][4] = 1;
	grid.PastGrid[11][5] = 1;
}

void Game::GameClearCurrentGrid()
{
	grid.ClearCurrentGrid();
}

bool Game::IsLifeOutside()
{
	return false;
}
