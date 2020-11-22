#include "TetrisBlock.h"

TetrisBlock::TetrisBlock(const int *block) 
{
    for (int i=0; i<16; i++) 
    {
        _block[i] = block[i];
    }
}

void TetrisBlock::left() 
{
    _x -= 1;
}

void TetrisBlock::right() 
{
    _x += 1;
}

void TetrisBlock::down() 
{
    _y += 1;
}

//temporary for testing
void TetrisBlock::up() 
{
    _y -= 1;
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

void TetrisBlock::show(Graphics graphics) 
{
    for (int i=0; i<16; i++) 
    {
        if(_block[i] != 0)
        {
            graphics.DrawPixel(_x + i%4,  _y + i/4, _block[i]);
        }
    }
}