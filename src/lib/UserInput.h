#pragma once
#include "TetrisBlock.h"

class UserInput
{
    public:
        UserInput();
        bool checkUserInput(TetrisBlock *block);

    private:
        bool leftPressed = false;
        bool rightPressed = false;
        bool upPressed = false;
        bool downPressed = false;
        bool spacePressed = false;
};