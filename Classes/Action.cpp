#include "Action.h"

// Constructors/Destructors
Action::Action()
{
}

Action::~Action()
{
}

/**
 * @brief Construct a new Action:: Action object
 * this copy the constructor
 * 
 * @param other A instance Action class
 */
Action::Action(const Action &other) : _type(other._type)
{
    std::memcpy(&_event, &other._event, sizeof(sf::Event));
}

/**
 * @brief copy constructor
 * 
 * @param other 
 * @return Action& 
 */
Action &Action::operator=(const Action &other)
{
    std::memcpy(&_event, &other._event, sizeof(sf::Event));
    _type = other._type;
    return *this;
}

/**
 * @brief Construct a new Action:: Action object
 * managent input user for keyboard events
 * 
 * @param key 
 * @param type 
 */
Action::Action(const sf::Keyboard::Key &key, int type) : _type(type)
{
    _event.type = sf::Event::EventType::KeyPressed;
    _event.key.code = key;
}

/**
 * @brief Construct a new Action:: Action object
 * management input user for mouse event
 * 
 * @param button 
 * @param type 
 */
Action::Action(const sf::Mouse::Button &button, int type) : _type(type)
{
    _event.type = sf::Event::EventType::MouseButtonPressed;
    _event.mouseButton.button = button;
}

/**
 * @brief test if a event is in REAL-TIME
 * 
 * @return true 
 * @return false 
 */
bool Action::test() const
{
    bool res = false;
    if (_event.type == sf::Event::EventType::KeyPressed)
    {
        if (_type && Type::Pressed)
        {
            res = sf::Keyboard::isKeyPressed(_event.key.code);
        }
    }
    else
    {
        if (_type && Type::Pressed)
        {
            res = sf::Mouse::isButtonPressed(_event.mouseButton.button);
        }
    }
    return res;
}

/**
 * @brief compare event with other
 * 
 * @param event 
 * @return true 
 * @return false 
 */
bool Action::operator==(const sf::Event &event) const
{
    bool res = false;
    switch (event.type)
    {
    case sf::Event::EventType::KeyPressed:
    {
        if (_type && Type::Pressed and _event.type == sf::Event::EventType::KeyPressed)
        {
            res = event.key.code == _event.key.code;
        }
    }
    break;

    case sf::Event::EventType::KeyReleased:
    {
        if (_type && Type::Release and _event.type == sf::Event::EventType::KeyReleased)
        {
            res = event.key.code == _event.key.code;
        }
    }
    break;

    case sf::Event::EventType::MouseButtonPressed:
    {
        if (_type && Type::Release and _event.type == sf::Event::EventType::MouseButtonPressed)
        {
            res = event.mouseButton.button == _event.mouseButton.button;
        }
    }
    break;

    case sf::Event::EventType::MouseButtonReleased:
    {
        if (_type && Type::Release and _event.type == sf::Event::EventType::MouseButtonReleased)
        {
            res = event.mouseButton.button == _event.mouseButton.button;
        }
    }
    break;

    default:
        break;
    }
    return res;
}

/**
 * @brief comparison events with other
 * 
 * @param other 
 * @return true 
 * @return false 
 */
bool Action::operator==(const Action &other) const
{
    return _type == other._type and other == _event;
}
