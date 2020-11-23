#include "TetrisBlock.h"
#include "resources/Shapes.h"

TetrisBlock::TetrisBlock(const int *block, Graphics *thisgraphics)
{
    graphics = thisgraphics;
    for (int i=0; i<16; i++) 
    {
        _block[i] = block[i];
    }
}

TetrisBlock::TetrisBlock(Graphics *thisgraphics)
{
    graphics = thisgraphics;
}

void TetrisBlock::generateRandomBlock()
{
    Shapes shapes;

    blockx = 0;
    blocky = 0;

    switch (std::rand() % 7)
    {
    case 0:
        for (int i=0; i<16; i++) 
        {
            _block[i] = shapes.blueRicky[i];
        }
        break;
    case 1:
        for (int i=0; i<16; i++) 
        {
            _block[i] = shapes.clevelandZ[i];
        }
        break;
    case 2:
        for (int i=0; i<16; i++) 
        {
            _block[i] = shapes.hero[i];
        }
        break;
    case 3:
        for (int i=0; i<16; i++) 
        {
            _block[i] = shapes.orangeRicky[i];
        }
        break;
    case 4:
        for (int i=0; i<16; i++) 
        {
            _block[i] = shapes.rhodeIsland[i];
        }
        break;
    case 5:
        for (int i=0; i<16; i++) 
        {
            _block[i] = shapes.smashBoy[i];
        }
        break;
    default:
        for (int i=0; i<16; i++) 
        {
            _block[i] = shapes.teewave[i];
        }
        break;
    }
}

void TetrisBlock::left() 
{
    if (!stopLeft)
    {
        blockx -= 1;
    }
}

void TetrisBlock::right() 
{
    if (!stopRight)
    {
        blockx += 1;
    }
}

void TetrisBlock::down() 
{
    if (!stopDown)
    {
        blocky += 1;
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
    blockx = x;
    blocky = y;
}

void TetrisBlock::setRelativePosition(int x, int y)
{
    blockx += x;
    blocky += y;
}

int TetrisBlock::getMaxX()
{
    int max = 0;
    for (int i=0; i<16; i++)
    {
        if (_block[i] != 0)
        {
            if (blockx + i%4 > max)
            {
                max = blockx + i%4;
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
            if (blockx + i%4 < min)
            {
                min = blockx + i%4;
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
            if (blocky + i/4 > max)
            {
                max = blocky + i/4;
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
            int blockX = (blockx + i%4);
            int blockY = (blocky + i/4);

            stopDown += graphics->hasBlockAt(blockX, blockY + 1);
            stopLeft += graphics->hasBlockAt(blockX - 1, blockY);
            stopRight += graphics->hasBlockAt(blockX + 1, blockY);

            graphics->drawPixel(blockX,  blockY, _block[i]);
        }
    }

    if (stopDown)
    {
        graphics->bake();
        generateRandomBlock();
        setAbsolutePosition(graphics->getWidth()/2 - 2, 0);
    }
}