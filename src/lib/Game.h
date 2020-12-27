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
        Game(const int width, const int height);
        void endGame();
        bool gameEnded();
        void gameStep();

    private:
        User user;
        Timer timer;
        Console console;
        Timer gameTimer;
        Graphics graphics;
        UserInput input;
        TetrisBlock tetrisBlock;

    private:
        bool gameHasEnded = false;
        int numCleared = 0;

    private:
        void update();
        void gameOver();
        void checkInput();

};