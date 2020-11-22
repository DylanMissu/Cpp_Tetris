#include <iostream>
#include "lib/Timer.h"
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
    UserInput input;
    Timer inputTimer;
    Graphics graphics(12, 24);
    TetrisBlock BlueRicky(shapes.hero);
    graphics.DrawGameBorder(12, 24);

    inputTimer.setState(false);

    while(true) 
    {
        bool updated = input.checkUserInput(&BlueRicky);
        inputTimer.setState(!updated);


        if(timer.getElapsedMillis() > 500)
        {
            inputTimer.setState(false);
            timer.resetTimer();
            BlueRicky.down();
        }

        if (!inputTimer.getState()) 
        {
            graphics.ClearRect(1, 0, 10, 23);
            if (system("CLS")) system("clear");

            inputTimer.setState(true);
            BlueRicky.show(graphics);

            cout <<  graphics.DrawBuffer() << endl;

            Sleep(200);
        }
    }
    
}