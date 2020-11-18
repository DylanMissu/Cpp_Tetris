#include "Graphics.h"

std::string red = "\e[0;31m";
std::string RED = "\e[1;31m";
std::string blue = "\e[0;34m";
std::string BLUE = "\e[1;34m";
std::string cyan = "\e[0;36m";
std::string CYAN = "\e[1;36m";
std::string green = "\e[0;32m";
std::string GREEN = "\e[1;32m";
std::string yellow = "\e[0;33m";
std::string YELLOW = "\e[1;33m";

std::string *buffer;

int gameWidth;
int gameHeight;

Graphics::Graphics(const int width, const int height) {
    buffer = new std::string[width * height * 2];
    gameWidth = width*2;
    gameHeight = height;
}

void Graphics::DrawGameBorder(int width, int height) 
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            if (j == 0 || j == width - 1 || i == height - 1)
            {
                buffer[j*gameWidth + i] = "\xDB\xDB";
            }
            else
            {
                buffer[j*gameWidth + i] = "  ";
            }
        }
    }
}

void Graphics::DrawPixel(int x, int y, std::string colorCode)
{
    buffer[x*gameWidth + y] = colorCode.append("\xDB\xDB").append("\e[0m");
}

std::string Graphics::DrawBuffer() 
{
    std::string output = "";
    for (int i = 0; i < gameHeight; i++)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            output += buffer[j*gameWidth + i];
        }
        output += "\n\r";
    }

    //delete[]buffer;
    return output;
}