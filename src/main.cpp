#include "lib/Game.h"

using namespace std;

int main()
{
    Game game(12, 22);

    while(!game.gameEnded()) 
    {
        game.gameStep();
    }
    
}