#pragma once
#include "Grid.h"

class Game {
public:
	Game();
	~Game();
	void Draw();
	void HandleInput();
	void Reset();
	void Generate();
	int CountNeighbors(int row, int column);
	bool gameOver;
	int numcols;  //I added these
	int numrows;
	void TestCase();
	void GameClearCurrentGrid();

private:
	bool IsLifeOutside();
	//bool LifeAbove;
	//bool LifeLeft;
	//bool LifeRight;
	//bool LifeBelow;
	Grid grid;

};
