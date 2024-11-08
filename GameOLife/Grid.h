#pragma once
#include <vector>
#include <raylib.h>

class Grid {

public:
	Grid();
	void Initialize();
	void ClearCurrentGrid();
	void Print();
	void Draw();
	bool IsCellOutside(int row, int column);
	int CurrentGrid[20][10];    
	int PastGrid[20][10];    //try using past grid, to create current grid, then draw current grid
	/*
	   something chatgpt cooked up for using vector within a vector to create a matrix. Probably better than the iterating process used currently
	#include <vector>

    std::vector<std::vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    std::vector<std::vector<int>> matrix2;

    // Assign matrix1 to matrix2
    matrix2 = matrix1;

	*/

	bool IsCellEmpty(int row, int column);
	int numRows;
	int numCols;
	//int EdgeCell(int row, int column);     not used currently. broken into four methods below
	bool NotLeftEdge(int row);
	bool NotRightEdge(int row);
	bool NotTopEdge(int column);
	bool NotBottomEdge(int column);
	void CurrentToPast();



private:
	//int numRows;
	//int numCols;
	int cellSize;
	std::vector<Color> colors;
};


