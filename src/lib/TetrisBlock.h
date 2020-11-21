#pragma once

#include "Graphics.h"

class TetrisBlock {
    public:
        TetrisBlock(const int *block);
        void show(Graphics graphics);
        void setAbsolutePosition(int x, int y);
        void setRelativePosition(int x, int y);

    public:
        void left();
        void right();
        void down();
        void up(); //temporary for testing
        void rotate();

    private:
        int _block[16];
        int _y = 0;
        int _x = 0;
};