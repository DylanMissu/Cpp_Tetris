#pragma once

#include "Graphics.h"

class TetrisBlock {
    public:
        TetrisBlock(int *block);
        void show(Graphics graphics);
        void setAbsolutePosition(int x, int y);
        void setRelativePosition(int x, int y);

    public:
        void left();
        void right();
        void down();
        void up();

    private:
        int _block[16];
        int _y = 0;
        int _x = 0;
};