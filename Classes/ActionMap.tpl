/**
 * @brief Template class for ActionMap Class
 * 
 * @tparam T 
 * @param key 
 * @param action 
 */

template <typename T>
void ActionMap<T>::map(const T &key, const Action &action)
{
    _map.emplace(key, action);
}

template <typename T>
ActionMap<T>::~ActionMap()
{
}

template <typename T>
const Action &ActionMap<T>::get(const T &key) const
{
    return _map.at(key);
}
