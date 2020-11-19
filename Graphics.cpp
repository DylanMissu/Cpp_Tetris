#include "Graphics.h"

std::string *buffer;

int gameWidth;
int gameHeight;

Graphics::Graphics(const int width, const int height) {
    buffer = new std::string[width * height * 2];
    gameWidth = width*2;
    gameHeight = height;
}

int Graphics::getWidth() {
    return gameWidth;
}

int Graphics::getHeight() {
    return gameHeight;
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
    buffer[x*gameWidth + y] = colorCode + "\xDB\xDB" + "\e[0m";
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