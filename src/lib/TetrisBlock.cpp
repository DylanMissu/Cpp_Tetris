#include "TetrisBlock.h"

TetrisBlock::TetrisBlock(const int *block, Graphics *thisgraphics)
{
    graphics = thisgraphics;
    for (int i=0; i<16; i++) 
    {
        _block[i] = block[i];
    }
}

void TetrisBlock::left() 
{
    if (!stopLeft)
    {
        _x -= 1;
    }
}

void TetrisBlock::right() 
{
    if (!stopRight)
    {
        _x += 1;
    }
}

void TetrisBlock::down() 
{
    if (!stopDown)
    {
        _y += 1;
    }
}

void TetrisBlock::rotate()
{
    int rotatedBlock[16] = {};

    for (int i=0; i<4; i++)
    {
        for (int j=0; j<4; j++)
        {
            //https://stackoverflow.com/questions/20149783/rotating-a-2d-converted-1d-array-90-degrees-clockwise
            rotatedBlock[(j) + 4*(i)] = _block[(i) + 4*(4 - 1 - j)];
        }
    }

    for (int i=0; i<16; i++){
        _block[i] = rotatedBlock[i];
    }
}

void TetrisBlock::setAbsolutePosition(int x, int y)
{
    _x = x;
    _y = y;
}

void TetrisBlock::setRelativePosition(int x, int y)
{
    _x += x;
    _y += y;
}

int TetrisBlock::getMaxX()
{
    int max = 0;
    for (int i=0; i<16; i++)
    {
        if (_block[i] != 0)
        {
            if (_x + i%4 > max)
            {
                max = _x + i%4;
            }
        }
    }

    return max;
}

int TetrisBlock::getMinX()
{
    int min = 16;
    for (int i=0; i<16; i++)
    {
        if (_block[i] != 0)
        {
            if (_x + i%4 < min)
            {
                min = _x + i%4;
            }
        }
    }

    return min;
}

int TetrisBlock::getMaxY()
{
    int max = 0;
    for (int i=0; i<16; i++)
    {
        if (_block[i] != 0)
        {
            if (_y + i/4 > max)
            {
                max = _y + i/4;
            }
        }
    }

    return max;
}

void TetrisBlock::show() 
{
    stopDown = false;
    stopLeft = false;
    stopRight = false;
    for (int i=0; i<16; i++) 
    {
        if(_block[i] != 0)
        {
            int blockX = (_x + i%4);
            int blockY = (_y + i/4);
            stopDown += graphics->hasBlockAt(blockX, blockY + 1);
            stopLeft += graphics->hasBlockAt(blockX - 1, blockY);
            stopRight += graphics->hasBlockAt(blockX + 1, blockY);

            graphics->DrawPixel(blockX,  blockY, _block[i]);
        }
    }
}