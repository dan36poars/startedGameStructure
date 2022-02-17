#ifndef __GAME_H__
#define __GAME_H__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>

#include "Player.h"

class Game
{
private:
    /* data */
    sf::RenderWindow *window;
    const std::string nameGame = "Game 1";

    Player *player;

    // private
    void initWindow();

    void poolEvent();
    void proccessEvents();
    void update(sf::Time deltaTime);
    void render();

public:
    // Construct/Destruct
    Game();
    Game(const Game &) = delete;
    Game &operator=(const Game &) = delete;
    ~Game();

    // functions


    // running
    void run(int minimum_frame_per_seconds);
};

#endif // __GAME_H__