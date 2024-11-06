#pragma once
#include <vector>
#include <raylib.h>

class Grid {

public:
	Grid();
	void Initialize();
	void Print();
	void Draw();
	bool IsCellOutside(int row, int column);
	int CurrentGrid[20][10];    //understand that this is a matrix and how it works. also need to understand syntax of vectors std::vector<Color> colors;
	int PastGrid[20][10];    //try using past grid, to create current grid, then draw current grid
	bool IsCellEmpty(int row, int column);
	int numRows;
	int numCols;



private:
	//int numRows;
	//int numCols;
	int cellSize;
	std::vector<Color> colors;
};


