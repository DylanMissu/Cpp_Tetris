#include "Console.h"
#include <iostream>

void Console::drawToConsole(Graphics graphics)
{
    const int width = graphics.getWidth();
    const int height = graphics.getHeight();
    const int *buffer = graphics.getBuffer();
    const int *bakedBuffer = graphics.getBakedBuffer();

    std::string output = "";
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (buffer[j + width*i] != 0)
            {
                output += colors[buffer[j + width*i]] + "\xDB\xDB" + colors[0];
            }
            else if (bakedBuffer[j + width*i] != 0)
            {
                output += colors[bakedBuffer[j + width*i]] + "\xDB\xDB" + colors[0];
            }
            else
            {
                 output += "  ";
            }
        }
        output += "\n\r";
    }
    if (system("CLS")) system("clear");
    std::cout << output.c_str() << std::endl;
}