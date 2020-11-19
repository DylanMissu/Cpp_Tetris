#include "TetrisBlock.h"

int _block[16] = {};
int _x = 0;
int _y = 0;


TetrisBlock::TetrisBlock(int block[16]) {
    for (int i=0; i<16; i++) 
    {
        _block[i] = block[i];
    }
}

void TetrisBlock::show(Graphics graphics, std::string colorCode) 
{
    for (int i=0; i<16; i++) 
    {
        if(_block[i] != 0)
        {
            graphics.DrawPixel(_x + i%4, _y + i/4, colorCode);
        }
    }
}