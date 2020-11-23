#pragma once

class Game
{
    public:
        Game();
        void endGame();
        bool gameEnded();

    private:
        bool gameHasEnded = false;
};