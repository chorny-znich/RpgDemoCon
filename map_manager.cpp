#include "map_manager.h"
#include <format>

void MapManager::init()
{
  for (size_t i{ 0 }; i < NUMBER_OF_MAPS; i++) {
    Map newMap;
    newMap.createMap(std::format("data/maps/map_{}.ini", i));
    mMaps.insert({ i, newMap });
  }
}