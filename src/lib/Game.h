#pragma once

class Game
{
    public:
        Game(const int width, const int height);
        void endGame();
        bool gameEnded();
        void gameStep();

    private:
        bool gameHasEnded = false;
        int numCleared = 0;

};