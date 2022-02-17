#ifndef __ACTIONTARGET_H__
#define __ACTIONTARGET_H__

#include <SFML/Window.hpp>
#include <functional>
#include <list>
#include <utility>
#include "ActionMap.h"

template <typename T = int>
class ActionTarget
{

public:
    /* data */
    // define the type function

    using FuncType = std::function<void(const sf::Event &)>;

    // Constructor/Destructor

    ActionTarget(const ActionTarget<T> &) = delete;
    ActionTarget<T> &operator=(const ActionTarget<T> &) = delete;

    ActionTarget(const ActionMap<T> &map);

    ~ActionTarget();

    // verify internal events to non-real-time and real-time

    bool processEvent(const sf::Event &event) const; // non-real-time
    void processEvents() const;                       // real-time

    // bind events to a function and other remove any existing event

    void bind(const T &action, const FuncType &callback);
    void unbind(const T &action);

private:
    /* data */
    std::list<std::pair<T, FuncType>> _eventsRealTime;
    std::list<std::pair<T, FuncType>> _eventsPoll;

    const ActionMap<T> &_actionMap;
};

#include "ActionTarget.tpl"

#endif // __ACTIONTARGET_H__