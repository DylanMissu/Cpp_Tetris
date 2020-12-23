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
            int pixelInt = combineIntOR(buffer[j + width*i], bakedBuffer[j + width*i]);

            if (pixelInt != 0)
            {
                output += colors[pixelInt] + pixelChar + colors[0];
            }
            else
            {
                output += paddingChar;
            }
        }
        output += "\n\r";
    }

    clear();
    std::cout << output.c_str() << std::endl;
}

void Console::clear()
{
    if (system("CLS")) system("clear");
}

void Console::askUserName(User user)
{
    std::string username;
    clear();
    std::cout << "Welcome!" << std::endl;
    std::cout << "What is your username?" << std::endl;
    std::cin >> username;

    user.setUserName(username);
}

int Console::combineIntOR(int a, int b)
{
    if (a != 0)
    {
        return a;
    }
    else if (b != 0)
    {
        return b;
    }
    else
    {
        return 0;
    }
}