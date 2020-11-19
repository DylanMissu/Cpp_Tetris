#pragma once

#include "Graphics.h"

class TetrisBlock {
    public:
        TetrisBlock(int *block);
        void show(Graphics graphics, std::string colorCode);

    private:
        int block[16];
};