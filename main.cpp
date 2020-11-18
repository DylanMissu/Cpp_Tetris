#include <iostream>
#include <thread>
#include <chrono>
#include "Graphics.h"

using namespace std;

int main()
{
    Graphics graphics(12, 24);
    graphics.DrawGameBorder(12, 24);

    graphics.DrawPixel(5,5, "\e[0;32m");
    graphics.DrawPixel(5,6, "\e[0;32m");
    graphics.DrawPixel(5,7, "\e[0;32m");
    graphics.DrawPixel(6,7, "\e[0;32m");

    string buffer = graphics.DrawBuffer();
    cout <<  buffer << endl;
}