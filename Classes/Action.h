#ifndef __ACTION_H__
#define __ACTION_H__

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <cstring>

// #include "ActionTarget.h"

class Action
{
private:
    /* data */
    template<class> friend class ActionTarget;
    sf::Event _event;
    int _type;

public:
    // Constructor/Destructor
    Action();

    // Copy constructors
    Action(const Action &other);
    Action &operator=(const Action &other);

    ~Action();

    // flags
    enum Type
    {
        RealTime = 1,
        Pressed = 1 << 1,
        Release = 1 << 2
    };

    // management input by keyboard or mouse
    Action(const sf::Keyboard::Key &key, int type = Type::RealTime | Type::Pressed);
    Action(const sf::Mouse::Button &button, int type = Type::RealTime | Type::Pressed);

    // test if event is real-time
    bool test() const;

    // operator comparison one event with other
    bool operator==(const sf::Event &event) const;
    bool operator==(const Action &other) const;
};

#endif // __ACTION_H__