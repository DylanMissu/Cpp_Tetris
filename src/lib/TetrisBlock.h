#pragma once

#include "Graphics.h"

class TetrisBlock {
    public:
        TetrisBlock(const int *block, Graphics *graphics);
        void show();
        void setAbsolutePosition(int x, int y);
        void setRelativePosition(int x, int y);

    public:
        void left();
        void right();
        void down();
        void rotate();

    public:
        int getMaxX();
        int getMinX();
        int getMaxY();
        //int getMinY();

    private:
        int _block[16];
        int _y = 0;
        int _x = 0;
        Graphics *graphics;

    private:
        bool stopDown = false;
        bool stopLeft = false;
        bool stopRight = false;
};