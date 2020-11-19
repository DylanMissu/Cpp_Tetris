#include <iostream>       // std::cout, std::endl
#include <thread>         // std::this_thread::sleep_for
#include <chrono>         // std::chrono::seconds
#include "Graphics.h"
#include "TetrisBlock.h"

using namespace std;

// white = "\e[0m";
// red = "\e[0;31m";
// blue = "\e[0;34m";
// cyan = "\e[0;36m";
// green = "\e[0;32m";
// yellow = "\e[0;33m";

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

    TetrisBlock blockL(L);
    blockL.right();
    blockL.show(graphics, "\e[0;31m");
    

    string buffer = graphics.DrawBuffer();

    cout <<  buffer << endl;
}