#pragma once
#include <raylib.h>
#include <vector>

extern const Color darkGrey;
//extern lets us declare a variable in one file and use it in another
extern const Color green;
extern const Color red;
extern const Color orange;
extern const Color yellow;
extern const Color purple;
extern const Color cyan;
extern const Color blue;
extern const Color lightblue;
extern const Color darkblue;

std::vector<Color> GetCellColors();