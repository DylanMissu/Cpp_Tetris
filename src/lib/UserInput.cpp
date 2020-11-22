#include "UserInput.h"
#include "Windows.h"

UserInput::UserInput(){
}

bool UserInput::checkUserInput(TetrisBlock *block) {
    bool updated = false;
    if(GetKeyState(VK_LEFT) & 0x8000)
    {
        updated = true;
        block->left();
    }
    if(GetKeyState(VK_RIGHT) & 0x8000)
    {
        updated = true;
        block->right();
    }
    if(GetKeyState(VK_DOWN) & 0x8000)
    {
        updated = true;
        block->down();
    }
    if(GetKeyState(VK_UP) & 0x8000)
    {
        updated = true;
        block->up();
    }
    if(GetKeyState(VK_SPACE) & 0x8000)
    {
        updated = true;
        block->rotate();
    }
    return updated;
}