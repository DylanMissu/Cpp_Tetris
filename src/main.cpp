#include <iostream>
#include "lib/Graphics.h"
#include "lib/TetrisBlock.h"
#include <Windows.h>

using namespace std;

const string white = "\e[0m";
const string red = "\e[0;31m";
const string blue = "\e[0;34m";
const string cyan = "\e[0;36m";
const string green = "\e[0;32m";
const string yellow = "\e[0;33m";

int main()
{
    Graphics graphics(12, 24);
    graphics.DrawGameBorder(12, 24);

    int L[16] = {
        0, 1, 0, 0,
        0, 1, 0, 0,
        0, 1, 1, 0,
        0, 0, 0, 0
    };

    int S[16] = {
        1, 1, 0, 0,
        0, 1, 1, 0,
        0, 0, 0, 0,
        0, 0, 0, 0
    };

    TetrisBlock blockL(L);

    
    while (true)
    {
        if (system("CLS")) system("clear");
        blockL.show(graphics, red);
        blockL.down();
        string buffer = graphics.DrawBuffer();
        graphics.ClearRect(1, 0, 10, 23);
        cout <<  buffer << endl;
        Sleep(500);
    }
    
    //Sleep(2000);
    //if (system("CLS")) system("clear");
    
}