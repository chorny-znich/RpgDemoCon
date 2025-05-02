#pragma once
#include "location.h"
#include "game_data.h"
#include <utility>


/**
 * @brief Game map contains group of locations
 */
class Map
{
private:
  size_t mId;
  GameData::LocationMap mLocationMap;
  GameData::Size mMapSize;
public:
  Map(size_t id);
  void createMap(const std::string& filename);
  void render();
};