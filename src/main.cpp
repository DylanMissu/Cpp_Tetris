#include <iostream>
#include "lib/Game.h"
#include "lib/User.h"
#include "lib/Timer.h"
#include "lib/Console.h"
#include "lib/Graphics.h"
#include "lib/UserInput.h"
#include "lib/TetrisBlock.h"

using namespace std;

int main()
{
    int numCleared = 0;

    Timer timer;
    User user;
    Console console;
    Timer gameTimer;
    Graphics graphics(12, 22);
    TetrisBlock tetrisBlock(&graphics);
    UserInput input(&tetrisBlock);

    Game game(12, 22, &tetrisBlock, &gameTimer, &console, &user, &input, &timer, &graphics);

    int endGame = false;

    while(!endGame) 
    {
        bool updated = input.checkUserInput();
        gameTimer.setState(!updated);
        game.gameStep();

        /*if (endGame)
        {
            console.clear();
            cout << "\e[1;31m" << "GAME OVER" << "\e[0m" << endl;
            cout << "Well done " << user.getUserName() << "!" << endl;
            cout << "You cleared " << numCleared << " rows!" << endl;
        }*/
    }
    
}