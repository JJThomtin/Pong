#include <SDL3/SDL.h>

#include "Game.h"
int main(int argc, char* argv[])
{
    Game game;

    //if the game exist the program runs a game loop
    if (game.Init()) {
        game.GameLoop();
    }

    game.ShutDown();

    return 0;
}