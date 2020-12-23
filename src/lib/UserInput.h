#pragma once
#include "TetrisBlock.h"
#include "Windows.h"

class UserInput
{
    public:
        UserInput(TetrisBlock *tetrisBlock);
        bool checkUserInput();

    private:
        TetrisBlock *block;
        bool leftPressed = false;
        bool rightPressed = false;
        bool upPressed = false;
        bool downPressed = false;
        bool spacePressed = false;
};