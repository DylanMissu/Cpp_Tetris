#include "Game.h"

Game::Game()
{
    gameHasEnded = false;
}

void Game::endGame()
{
    gameHasEnded = true;
}

bool Game::gameEnded()
{
    return gameHasEnded;
}