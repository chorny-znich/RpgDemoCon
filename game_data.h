#pragma once
#include "location.h"
#include <string>
#include <vector>

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

  inline namespace path
  {
    const std::string Map = R"(data/maps/)";
    const std::string Entry = R"(data/entries.ini)";
    const std::string PlayerInfo = R"(data/player.ini)";
  }
}