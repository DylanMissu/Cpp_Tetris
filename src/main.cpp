#include <iostream>
#include "lib/Graphics.h"
#include "lib/TetrisBlock.h"
#include "lib/resources/Shapes.h"
#include <Windows.h>

using namespace std;

int main()
{
    Shapes shapes;
    Graphics graphics(12, 24);
    graphics.DrawGameBorder(12, 24);

    TetrisBlock BlueRicky(shapes.blueRicky);

    bool updated = false;
    while(true) 
    {
        if(GetKeyState(VK_LEFT) & 0x8000)
        {
            updated = false;
            BlueRicky.left();
        }
        if(GetKeyState(VK_RIGHT) & 0x8000)
        {
            updated = false;
            BlueRicky.right();
        }
        if(GetKeyState(VK_DOWN) & 0x8000)
        {
            updated = false;
            BlueRicky.down();
        }
        if(GetKeyState(VK_UP) & 0x8000)
        {
            updated = false;
            BlueRicky.up();
        }
        if(GetKeyState(VK_SPACE) & 0x8000)
        {
            updated = false;
            BlueRicky.rotate();
        }

        if(getMillis() > 500)
        {
            updated = false;
            resetMillis();
            BlueRicky.down();
        }

        if (!updated) 
        {
            graphics.ClearRect(1, 0, 10, 23);
            if (system("CLS")) system("clear");

            updated = true;
            BlueRicky.show(graphics);

            cout <<  graphics.DrawBuffer() << endl;

            Sleep(100);
        }
    }
    
}