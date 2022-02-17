#include "Classes/Game.h"

int main(int argc, const char *argv[])
{
    // Configuration initialize
    Configuration::initialize();
    /* initialize static members */
    // Player::setDefaultsInputs();
    
    Game game;
    game.run(60);
    return 0;
}
