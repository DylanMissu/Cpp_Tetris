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
    Console console;
    Timer gameTimer;
    User user;
    Graphics graphics(12, 22);
    TetrisBlock tetrisBlock(&graphics);
    UserInput input(&tetrisBlock);

    tetrisBlock.generateRandomBlock();
    tetrisBlock.setAbsolutePosition(graphics.getWidth()/2 - 2, 0);
    
    gameTimer.setState(false);

    console.askUserName(user);

    int endGame = false;

    while(!endGame) 
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

            endGame = tetrisBlock.show();

            console.drawToConsole(graphics);
            cout << "rows cleared: " << numCleared << endl;
            cout << "step delay: " << (double)(500/(numCleared/16.0+1) + 100) << endl;
        }

        if (endGame)
        {
            console.clear();
            cout << "\e[1;31m" << "GAME OVER" << "\e[0m" << endl;
            cout << "Well done " << user.getUserName() << "!" << endl;
            cout << "rows cleared: " << numCleared << endl;
        }
    }
    
}