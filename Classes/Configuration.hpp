/**
 * @file Configuration.hpp
 * @author Daniel Corrêa
 * @brief management container class to all
 * Managers and configurations game.
 * this class does not can be instantiated.
 * use it with a static class.
 * @version 0.1
 * @date 2022-02-17
 *
 * @copyright Copyright (c) 2022
 *
 */
#ifndef __CONFIGURATION_H__
#define __CONFIGURATION_H__

#include <SFML/Graphics.hpp>

#include "ResourceManager.hpp"
#include "ActionMap.h"

class Configuration
{
private:
  /* data */
  static void initTextures();
  static void initPlayerInputs();

public:
  Configuration(const Configuration &) = delete;
  Configuration &operator=(const Configuration &) = delete;
  Configuration() = delete;

  // Textures
  enum Textures : int
  {
    Player
  };

  static ResourceManager<sf::Texture, int> textures;

  enum PlayerInputs : int
  {
    Up,
    Left,
    Right
  };

  static ActionMap<int> player_inputs;

  static void initialize();
};

#endif // __CONFIGURATION_H__