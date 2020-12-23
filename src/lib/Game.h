#pragma once

#include <iostream>

#include "User.h"
#include "Timer.h"
#include "Console.h"
#include "Graphics.h"
#include "UserInput.h"
#include "TetrisBlock.h"

class Game
{
    public:
        Game(const int width, const int height, TetrisBlock *block, Timer *gTimer, Console *con, User *usr, UserInput *uInput, Timer *tim, Graphics *graph);
        void endGame();
        bool gameEnded();
        void gameStep();

    private:
        User *user;
        UserInput *input;
        Console *console;
        Timer *gameTimer;
        Graphics *graphics;
        UserInput *userInput;
        Timer *timer;
        TetrisBlock *tetrisBlock;
        bool gameHasEnded = false;
        int numCleared = 0;

};