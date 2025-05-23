#pragma once
#include "map.h"
#include "game_object.h"
#include <vector>
#include <memory>

/**
 * @brief Place game objects in free random places
 */
class RandomPlacement
{
private:
  Map& rmMap;
  std::vector<std::shared_ptr<GameObject>> rmObjects;
public:
  RandomPlacement(Map& map, std::vector<std::shared_ptr<GameObject>>& obj);
  RandomPlacement(const RandomPlacement&) = delete;
  RandomPlacement& operator=(const RandomPlacement&) = delete;
  std::vector<GameData::Position> place();
};

