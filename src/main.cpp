#include <iostream>
#include "lib/Timer.h"
#include "lib/Console.h"
#include "lib/Graphics.h"
#include "lib/UserInput.h"
#include "lib/TetrisBlock.h"
#include "lib/resources/Shapes.h"
#include <Windows.h>

using namespace std;

int main()
{
    Timer timer;
    Shapes shapes;
    Console console;
    UserInput input;
    Timer gameTimer;
    Graphics graphics(12, 24);
    TetrisBlock BlueRicky(shapes.teewave, &graphics);
    BlueRicky.setAbsolutePosition(graphics.getWidth()/2 - 2, 0);
    graphics.DrawGameBorder(graphics.getWidth(), graphics.getHeight());
    
    gameTimer.setState(false);

    while(true) 
    {
        bool updated = input.checkUserInput(&BlueRicky);
        gameTimer.setState(!updated);

        if(timer.interval(1000))
        {
            gameTimer.setState(false);
            BlueRicky.down();
        }

        if (!gameTimer.getState()) 
        {
            gameTimer.setState(true);
            graphics.clearAll();

            BlueRicky.show();

            console.drawToConsole(graphics);
            Sleep(100);
        }
    }
    
}