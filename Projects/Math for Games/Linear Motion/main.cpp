/******************************************************************************

                          Console Game Framework
                          ======================

This application provides a very simple framework for a console game. The main
purpose is to run a game loop at a typical gaming frame rate (e.g. 50 frames per second)
and execute an 'OnEachFrame' function which will contain your game code.

*******************************************************************************/
#include <iostream>
#include <Windows.h>



const float GRAVITY = -9.8f;
const int FRAME_RATE = 50;


/******************************************************************************
Returns true if the specified key is currently held down. 'keyCode' is an ASCII 
value. Common values are:

    Escape  27
    A       65
    B       66
    C       67
    a       97
    b       98
    c       99

*******************************************************************************/
bool IsKeyDown(int keyCode)
{
    return (GetKeyState(keyCode) & 0x8000) != 0;
}

/******************************************************************************
This function executes once when the game starts up.
*******************************************************************************/
void Initialize()
{
    //
    // Place your game initialization code here
    //

    std::cout << "\n\nGame started\n\n";
}

/******************************************************************************
This function executes once each frame. 'deltaTime' is the time elapsed from
the previous frame (in seconds). Return false from this function to terminate
the game.
*******************************************************************************/
bool OnEachFrame(float deltaTime)
{
    // Here is an example of shuting down the game when the ESCAPE key is pressed.
    // To test for the letter A, use IsKeyDown('A')
    if (IsKeyDown(27))
    {
        return false;
    }

    //
    // Place your per-frame code here
    //

    // Return true to continue running the game, or false to terminate the game.
    return true;
}

/******************************************************************************
This function executes once just before the game shuts down
*******************************************************************************/
void Shutdown()
{
    //
    // Place your game shutdown code here
    //

    std::cout << "\n\nGame finished\n\n";
}

/******************************************************************************
*******************************************************************************/
void main()
{
    // Initialize the game
    Initialize();

    // Run the game loop
    while (true)
    {
        float deltaTime = 1.0f / FRAME_RATE;

        // If 'OnEachFrame' returns false, break out of the game loop, otherwise
        // delay by the appropiate interval to simulate the desired frame rate.
        if (OnEachFrame(deltaTime))
        {
            Sleep((DWORD)(1000.0f / FRAME_RATE));
        }
        else
        {
            break;
        }
    }

    Shutdown();
}