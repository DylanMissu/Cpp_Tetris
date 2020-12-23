#include "UserInput.h"

UserInput::UserInput(TetrisBlock *tetrisBlock)
{
    block = tetrisBlock;
}

//http://www.cplusplus.com/forum/windows/182965/
bool UserInput::checkUserInput() {
    bool updated = false;

    if(GetAsyncKeyState(VK_LEFT) != 0)
        leftPressed = true ;
    else if (leftPressed)
    {
        leftPressed = false;
        updated = true;
        block->left();
    }

    if(GetAsyncKeyState(VK_RIGHT) != 0)
        rightPressed = true;
    else if (rightPressed)
    {
        rightPressed = false;
        updated = true;
        block->right();
    }

    if(GetAsyncKeyState(VK_DOWN) != 0)
        downPressed = true;
    else if (downPressed)
    {
        downPressed = false;
        updated = true;
        block->down();
    }

    if(GetAsyncKeyState(VK_SPACE) != 0)
        spacePressed = true;
    else if (spacePressed)
    {
        spacePressed = false;
        updated = true;
        block->rotate();
    }

    return updated;
}