#include "Game.h"

Game::Game(const int width, const int height)  
            //:graphics(width, height), tetrisBlock(graphics), input(tetrisBlock)
{
    /*gameHasEnded = false;

    tetrisBlock.generateRandomBlock();
    tetrisBlock.setAbsolutePosition(graphics.getWidth()/2 - 2, 0);
    
    gameTimer.setState(false);

    int gameHasEnded = false;

    console.askUserName(user);*/
}

void Game::gameStep()
{
    //bool updated = input.checkUserInput(&tetrisBlock);
    //gameTimer.setState(!updated);

    /*if(timer.interval(500/(numCleared/16.0+1) + 100))
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
        std::cout << "rows cleared: " << numCleared << std::endl;
        std::cout << "delay: " << (double)(500/(numCleared/16.0+1) + 100) << std::endl;
    }

    if (gameHasEnded)
    {
        std::cout << "\e[1;31m" << "GAME OVER" << "\e[0m" << std::endl;
    }*/
}

void Game::endGame()
{
    gameHasEnded = true;
}

bool Game::gameEnded()
{
    return gameHasEnded;
}