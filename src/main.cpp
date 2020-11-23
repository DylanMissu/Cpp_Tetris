#include <iostream>
#include "lib/Timer.h"
#include "lib/Console.h"
#include "lib/Graphics.h"
#include "lib/UserInput.h"
#include "lib/TetrisBlock.h"
#include <Windows.h>

using namespace std;

int main()
{
    Timer timer;
    Console console;
    UserInput input;
    Timer gameTimer;
    Graphics graphics(12, 24);
    TetrisBlock tetrisBlock(&graphics);
    tetrisBlock.generateRandomBlock();
    tetrisBlock.setAbsolutePosition(graphics.getWidth()/2 - 2, 0);
    graphics.DrawGameBorder(graphics.getWidth(), graphics.getHeight());
    
    gameTimer.setState(false);

    while(true) 
    {
        bool updated = input.checkUserInput(&tetrisBlock);
        gameTimer.setState(!updated);

        if(timer.interval(1000))
        {
            gameTimer.setState(false);
            tetrisBlock.down();
        }

        if (!gameTimer.getState()) 
        {
            gameTimer.setState(true);
            graphics.clearAll();

            tetrisBlock.show();

            console.drawToConsole(graphics);
            cout << rand() % 7 << endl;
            Sleep(100);
        }
    }
    
}