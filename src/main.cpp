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
    TetrisBlock BlueRicky(shapes.hero);
    graphics.DrawGameBorder(12, 24);

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
            graphics.ClearRect(1, 0, 10, 23);

            gameTimer.setState(true);
            BlueRicky.show(graphics);

            console.drawToConsole(graphics);

            Sleep(100);
        }
    }
    
}