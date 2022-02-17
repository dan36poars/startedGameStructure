#include "Player.h"
// Construct/Destruct
Player::Player() : ActionTarget<int>(Configuration::player_inputs) , isMoving(false), rotation(0)
{
    this->_shape.setTexture(Configuration::textures.get(Configuration::Textures::Player));
    this->_shape.setOrigin(49.5, 37.5);
    this->_shape.setPosition(sf::Vector2f(100.f, 100.f));

    bind(Configuration::PlayerInputs::Up, [this](const sf::Event &) {
        isMoving = true;
    });

    bind(Configuration::PlayerInputs::Left, [this](const sf::Event &) {
        rotation -= 1;
    });

    bind(Configuration::PlayerInputs::Right, [this](const sf::Event &) {
        rotation += 1;
    });
}

Player::~Player()
{
}

// Private Methods

// Public Methods

/**
 * @brief update logic for player
 * 
 * @param deltaTime 
 */
void Player::update(sf::Time deltaTime)
{
    float seconds = deltaTime.asSeconds();

    if (this->rotation != 0)
    {
        float angle = this->rotation * 180 * seconds;
        this->_shape.rotate(angle);
    }

    if (this->isMoving)
    {
        float angle = this->_shape.getRotation() / 180 * M_PI - M_PI / 2;
        this->_velocity += sf::Vector2f(cos(angle), sin(angle)) * 60.f * seconds;
    }

    this->_shape.move(this->_velocity * seconds);
}

void Player::draw(sf::RenderTarget &target, sf::RenderStates states) const
{
    target.draw(this->_shape, states);
}

/**
 * @brief process events in player class
 * on REAL-TIME 
 */
void Player::processEvents()
{
    this->isMoving = false;
    this->rotation = 0;
    ActionTarget<int>::processEvents();
}

/**
 * @brief setting the inputs to action static variable 
 * _playerInputs of Player class itself
 * 
 */
// void Player::setDefaultsInputs() 
// {
//     _playerInputs.map(PlayerInputs::Up, Action(sf::Keyboard::Up));
//     _playerInputs.map(PlayerInputs::Left, Action(sf::Keyboard::Left));
//     _playerInputs.map(PlayerInputs::Right, Action(sf::Keyboard::Right));
// }

/* initialized static variables */
//ActionMap<int> Player::_playerInputs;
