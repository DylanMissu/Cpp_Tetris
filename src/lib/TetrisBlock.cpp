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
    for (int i=0; i<16; i++) 
    {
        if(_block[i] != 0)
        {
            graphics->DrawPixel(_x + i%4,  _y + i/4, _block[i]);

            stopDown = graphics->hasBlockAt((_x + i%4), getMaxY() + 1);
            stopLeft = graphics->hasBlockAt(getMinX() - 1, (_y + i/4));
            stopRight = graphics->hasBlockAt(getMaxX() + 1, (_y + i/4));
        }
    }
}