#include "Game.h"

Game::Game(const int width, const int height)
            :graphics(width, height), 
            tetrisBlock(&graphics), 
            input(&tetrisBlock)
{

    tetrisBlock.generateRandomBlock();
    
    gameTimer.setState(false);

    console.askUserName(user);
}

void Game::gameStep()
{
    bool updated = input.checkUserInput();
    gameTimer.setState(!updated);

    if(timer.interval(500/(numCleared/16.0+1) + 100))
    {
        gameTimer.setState(false);
        tetrisBlock.down();
        numCleared += graphics.removeFullLines();
    }

    if (!gameTimer.getState()) 
    {
        gameTimer.setState(true);
        graphics.clearAll();

        gameHasEnded = tetrisBlock.show();

        console.drawToConsole(graphics);
        std::cout << "Rows cleared: " << numCleared << std::endl;
        std::cout << "User: " << user.getUserName() << std::endl;
    }

    if (gameHasEnded)
    {
        console.clear();
        std::cout << "\e[1;31m" << "GAME OVER" << "\e[0m" << std::endl;
        std::cout << "Well done " << user.getUserName() << "!" << std::endl;
        std::cout << "You cleared " << numCleared << " rows!" << std::endl;
    }
}

void Game::endGame()
{
    gameHasEnded = true;
}

bool Game::gameEnded()
{
    return gameHasEnded;
}