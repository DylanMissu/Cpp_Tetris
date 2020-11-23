#include "Graphics.h"

Graphics::Graphics(const int width, const int height) 
{
    buffer = new int[width * height];
    tempBuffer = new int[width * height];
    bakedBuffer = new int[width * height];
    gameWidth = width;
    gameHeight = height;
    drawGameBorder();
}

const int Graphics::getWidth() 
{
    return gameWidth;
}

const int Graphics::getHeight() 
{
    return gameHeight;
}

void Graphics::drawGameBorder() 
{
    for (int i = 0; i < gameHeight; i++)
    {
        for (int j = 0; j < gameWidth; j++)
        {
            if (j == 0 || j == gameWidth - 1 || i == gameHeight - 1)
            {
                buffer[j + gameWidth*i] = 1;
                bakedBuffer[j + gameWidth*i] = 1;
            }
            else
            {
                buffer[j + gameWidth*i] = 0;
                bakedBuffer[j + gameWidth*i] = 0;
            }
        }
    }
}

bool Graphics::hasBlockAt(int x, int y)
{
    return (bakedBuffer[x + gameWidth*y] != 0);
}

bool Graphics::hasFullLineAt(int y)
{
    int blockCount = 0;
    for (int i=0; i<gameWidth; i++)
    {
        int block = bakedBuffer[i + gameWidth*y];
        if (block != 0 && block != 1)
        {
            blockCount += 1;
        }
    }

    return (blockCount >= gameWidth-2);
}

int Graphics::removeFullLines()
{
    int numCleared = 0;
    for (int i=0; i<gameHeight; i++)
    {
        if (hasFullLineAt(i))
        {
            numCleared += 1;
            for (int j = 0; j < gameWidth * gameHeight; j++)
            {
                buffer[j] = bakedBuffer[j];
            }

            for (int j = 0; j < gameWidth * gameHeight; j++)
            {
                int x = j%gameWidth;
                int y = j/gameWidth;

                if (y <= i)
                {
                    bakedBuffer[x + gameWidth*(y + 1)] = buffer[j];
                }
                else
                {
                    bakedBuffer[x + gameWidth*y] = buffer[j];
                }
            }
        }
    }
    clearAll();
    return numCleared;
}

void Graphics::drawPixel(int x, int y, int colorCode)
{
    buffer[x + gameWidth*y] = colorCode;
}

void Graphics::clearAll() 
{
    for (int i = 0; i < gameWidth * gameHeight; i++)
    {
        buffer[i] = 0;
    }
}

void Graphics::bake()
{
    for (int i=0; i<gameHeight*gameWidth; i++)
    {
        if (buffer[i] != 0)
        {
            bakedBuffer[i] = buffer[i];
        }
    }
}

int *Graphics::getBuffer() 
{
    return buffer;
}

int *Graphics::getBakedBuffer()
{
    return bakedBuffer;
}