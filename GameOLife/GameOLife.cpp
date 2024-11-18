// GameOLife.cpp : This file contains the 'main' function. Program execution begins and ends there.
// 
// next steps 11/5/24: define mouse input, get edge cases of generate() countNeighbors(), put on github
// 
// //added to github, order is wrong in flow here. Map out from test case through generation
//

#include <iostream>
#include <raylib.h>
#include "colors.h"
#include "game.h"

using namespace std;

//define timing system - call later to handle game updates
double lastUpdateTime = 0;

bool EventTriggered(double interval)
{
    double currentTime = GetTime(); //GetTime from raylib
    if (currentTime - lastUpdateTime >= interval)
    {
        lastUpdateTime = currentTime;
        return true;
    }
    return false;
}


int main()
{
    const int screenWidth = 300;
    const int screenHeight = 600;

    const int FullWidth = 500;
    const int FullHeight = 620;

    InitWindow(FullWidth, FullHeight, "Riley's Original Game Tetris");
    // computer graphics coordinate system starts at top left of a window
    SetTargetFPS(30);

    

    Game game = Game();  //need to define

    game.Draw();

    if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON)) {
        // Get mouse position when left button is clicked
        Vector2 mousePosition = GetMousePosition();
        //maybe cast to int? and enter those into matrix
        game.Draw();
    }


    //create a GameStart() button and variable
    
    game.TestCase();

    // && GameStart() == true

    while (WindowShouldClose() == false) {

        game.HandleInput();

        /*   was here, i am moving below for now. Should probably check definitions of each function
        if (EventTriggered(0.2))
        {
            game.Generate();
        }
        */

        BeginDrawing();
        ClearBackground(darkblue); //check that I need the clearBackground still

        if (game.gameOver) //still define  - maybe with button to reset
        {
            //DrawTextEx(font, "GAME OVER", { 320,450 }, 24, 2, WHITE);
        }

         game.Draw();

        if (EventTriggered(1))
        {
            //game.Draw();
            game.Generate();
            //game.GameClearCurrentGrid();  need to iron out the flow again. 
        }
        

        //game.Draw();
        
        EndDrawing();  //understand better when this happens and general timing of this system
    }

    CloseWindow();
    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
