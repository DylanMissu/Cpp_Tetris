#include "Graphics.h"

Graphics::Graphics(const int width, const int height) {
    buffer = new std::string[width * height];
    gameWidth = width;
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
                buffer[j + gameWidth*i] = "\xDB\xDB";
            }
            else
            {
                buffer[j + gameWidth*i] = "  ";
            }
        }
    }
}

void Graphics::DrawPixel(int x, int y, int colorCode)
{
    buffer[x + gameWidth*y] = colors[colorCode] + "\xDB\xDB" + colors[0];
}

void Graphics::ClearRect(int x, int y, int width, int height) {
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[(y + i)*gameWidth + (x + j)] = "  ";
        }
    }
}

std::string Graphics::DrawBuffer() 
{
    std::string output = "";
    for (int i = 0; i < gameHeight; i++)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            output += buffer[j + gameWidth*i];
        }
        output += "\n\r";
    }

    //delete[]buffer;
    return output;
}