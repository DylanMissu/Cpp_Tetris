#include "lib/Game.h"

using namespace std;

int main()
{
    // feel free to adjust these values to make a silly tetris game
    Game game(12, 22); // (width, height) this includes the walls

    while(!game.gameEnded()) 
    {
        game.gameStep();
    }
    
}