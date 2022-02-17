/**
 * @file ResourceManager.hpp
 * @author Daniel Corrêa
 * @brief Resource Manager on our engine.
 * Load and Realese the Resources. Avoid any more duplicate.
 * @version 0.1
 * @date 2022-02-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __RESOURCEMANAGER_H__
#define __RESOURCEMANAGER_H__

#include <memory> // unique_ptr
#include <unordered_map>

#include <stdexcept> // runtime_error
#include <utility>   // forward

#include <SFML/Audio.hpp>

template <typename RESOURCE, typename IDENTIFIER = int>
class ResourceManager
{
private:
  /* data */
  std::unordered_map<IDENTIFIER, std::unique_ptr<RESOURCE>> _map;

public:
  ResourceManager(const ResourceManager &) = delete;
  ResourceManager &operator=(const ResourceManager &) = delete;
  ResourceManager() = default;

  template <typename... Args>
  void load(const IDENTIFIER &id, Args &&...args);

  RESOURCE &get(const IDENTIFIER &id) const;
};

// especialization class to sf::Music
template <typename IDENTIFIER>
class ResourceManager<sf::Music, IDENTIFIER>
{
private:
  /* data */
  std::unordered_map<IDENTIFIER, std::unique_ptr<sf::Music>> _map;

public:
  ResourceManager(const ResourceManager &) = delete;
  ResourceManager &operator=(const ResourceManager &) = delete;
  ResourceManager() = default;

  template <typename... Args>
  void load(const IDENTIFIER &id, Args &&...args);

  sf::Music &get(const IDENTIFIER &id) const;
};

#include "ResourceManager.tpl"

#endif // __RESOURCEMANAGER_H__