#include "game.h"
#

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
	for (int row = 0; row < numrows; row++) {
		for (int column = 0; column < numcols; column++) {
			/*
			conditions:
			if =1 and CountNeighbors = 1 then =0
			if =1 and CountNeighbors = 2 | CountNeighbors = 3  then =1  no change
			if =1 and CountNeighbors = 4, then =0
			if =0 and CountNeighbors = 3, then =1
			*/
			switch (CountNeighbors(row,column)) {  //define thise still
			case 1:
				grid.CurrentGrid[row][column] = 0;
			case 3:
				grid.CurrentGrid[row][column] = 1;
				break;
			case 4:
				grid.CurrentGrid[row][column] = 0;
				break;
			default:
				break;
			}

			//probably need grid.PastGrid = grid.CurrentGrid;
		}
	}
}

int Game::CountNeighbors(int row,int column)
{
	
	int sum = 0;
	sum = sum + grid.PastGrid[row-1][column];  //need edge cases. Can do with if statements here or by creating a bool method in grid and call it here. That is probably smarter
	sum = sum + grid.PastGrid[row][column-1];
	sum = sum + grid.PastGrid[row][column+1];
	sum = sum + grid.PastGrid[row+1][column];
	return sum;
	
}

bool Game::IsLifeOutside()
{
	return false;
}
