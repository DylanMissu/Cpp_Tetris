#include "Game.h"

Game::Game(const int width, const int height, TetrisBlock *block, Timer *gTimer, Console *con, User *usr, UserInput *uInput, Timer *tim, Graphics *graph)
{
    tetrisBlock = block;
    gameTimer = gTimer;
    userInput = uInput;
    graphics = graph;
    console = con;
    timer = tim;
    user = usr;

    gameHasEnded = false;

    tetrisBlock->generateRandomBlock();
    
    gameTimer->setState(false);

    int gameHasEnded = false;

    console->askUserName(user);
}

void Game::gameStep()
{
    //bool updated = input->checkUserInput();
    //gameTimer->setState(!updated);

    if(timer->interval(500/(numCleared/16.0+1) + 100))
    {
        gameTimer->setState(false);
        tetrisBlock->down();
        numCleared += graphics->removeFullLines();
    }

    if (!gameTimer->getState()) 
    {
        gameTimer->setState(true);
        graphics->clearAll();

        gameHasEnded = tetrisBlock->show();

        console->drawToConsole(graphics);
        std::cout << "Rows cleared: " << numCleared << std::endl;
        std::cout << "User: " << user->getUserName() << std::endl;
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