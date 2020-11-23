#include "Graphics.h"

Graphics::Graphics(const int width, const int height) 
{
    buffer = new int[width * height];
    gameWidth = width;
    gameHeight = height;
}

const int Graphics::getWidth() 
{
    return gameWidth;
}

const int Graphics::getHeight() 
{
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
                buffer[j + gameWidth*i] = 1;
            }
            else
            {
                buffer[j + gameWidth*i] = 0;
            }
        }
    }
}

bool Graphics::hasBlockAt(int x, int y)
{
    return (bool)(buffer[x + gameWidth*y] != 0);
}

void Graphics::DrawPixel(int x, int y, int colorCode)
{
    buffer[x + gameWidth*y] = colorCode;
}

void Graphics::ClearRect(int x, int y, int width, int height) 
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            buffer[(y + i)*gameWidth + (x + j)] = 0;
        }
    }
}

int *Graphics::getBuffer() 
{
    return buffer;
}