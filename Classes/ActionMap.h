#ifndef __ACTIONMAP_H__
#define __ACTIONMAP_H__

#include <unordered_map>
#include "Action.h"

template <typename T = int>
class ActionMap
{
private:
    /* data */
    std::unordered_map<T, Action> _map;

public:
    ActionMap(const ActionMap<T> &) = delete;
    ActionMap<T> &operator=(const ActionMap<T> &) = delete;

    ActionMap() = default;

    ~ActionMap();

    void map(const T &key, const Action &action);
    const Action &get(const T &) const;
};

#include "ActionMap.tpl"

#endif // __ACTIONMAP_H__