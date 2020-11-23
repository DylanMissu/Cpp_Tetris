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
    int numCleared = 0;
    Timer timer;
    Console console;
    UserInput input;
    Timer gameTimer;
    Graphics graphics(12, 24);
    TetrisBlock tetrisBlock(&graphics);

    tetrisBlock.generateRandomBlock();
    tetrisBlock.setAbsolutePosition(graphics.getWidth()/2 - 2, 0);
    
    gameTimer.setState(false);

    while(true) 
    {
        bool updated = input.checkUserInput(&tetrisBlock);
        gameTimer.setState(!updated);

        if(timer.interval(500/(numCleared/8+1) + 50))
        {
            gameTimer.setState(false);
            tetrisBlock.down();
            numCleared += graphics.removeFullLines();
        }

        if (!gameTimer.getState()) 
        {
            gameTimer.setState(true);
            graphics.clearAll();

            tetrisBlock.show();

            console.drawToConsole(graphics);
            cout << "rows cleared: " << numCleared << endl;
            cout << "delay: " << (double)(500/(numCleared/8.0+1) + 50) << endl;
        }
    }
    
}