#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Network.hpp>
#include <SFML/Audio.hpp>

#include <iostream>
#include <string>
#include <math.h>

#include "ActionTarget.h"
#include "Configuration.hpp"

using namespace std;

class Player : public sf::Drawable, public ActionTarget<int>
{
private:
    /* data */
    sf::Sprite _shape;
    sf::Vector2f _velocity;

    int rotation;
    bool isMoving;

    // FUNCTIONS

    //static ActionMap<int> _playerInputs;

public:
    // Variables

    // Construct/Destruct
    Player(const Player &) = delete;
    Player &operator=(const Player &) = delete;
    Player();
    ~Player();

    // FUNCTIONS

    // to perfectly forward parameters
    template <typename... Args>
    void setPosition(Args &&...args)
    {
        this->_shape.setPosition(std::forward<Args>(args)...);
    }

    void update(sf::Time deltaTime);
    virtual void draw(sf::RenderTarget &target, sf::RenderStates states = sf::RenderStates::Default) const override;

    void processEvents();

    enum PlayerInputs
    {
        Up,
        Left,
        Right
    };

    static void setDefaultsInputs();
};

#endif // __PLAYER_H__