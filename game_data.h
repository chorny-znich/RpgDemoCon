#pragma once
#include "location.h"
#include <string>
#include <vector>
#include <map>

/**
 * @brief Game metadata
 */
namespace GameData
{
  using TextMap = std::vector<std::string>;
  using LocationMap = std::vector<Location>;
  using RenderMap = std::vector<std::string>;
  using Size = std::pair<size_t, size_t>;
  using Position = std::pair<size_t, size_t>;
  using Movement = std::pair<int, int>;

  const size_t NUMBER_OF_MAPS = 3;

  inline namespace path
  {
    const std::string Map = R"(data/maps/)";
    const std::string Entry = R"(data/entries.ini)";
    const std::string PlayerInfo = R"(data/player.ini)";
    const std::string ObjectInfo = R"(data/objects/)";
  }

  /**
   * @brief Directions on the map
   */
  enum class Direction {
    CURRENT,
    NORTH,
    EAST,
    SOUTH,
    WEST
  };

  enum class EnvironmentType
  {
    NONE,
    ENTRY,
    PLAYER,
    ENEMY,
    OBJECT,
    NPC
  };

  struct TileEnvironment
  {
    bool mPassability{false};
    EnvironmentType mEnvironmentType{ EnvironmentType::NONE };
  };
}