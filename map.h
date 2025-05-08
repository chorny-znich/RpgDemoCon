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
  GameData::RenderMap mRenderMap;
  GameData::Size mMapSize;

  void createRenderMap();
  char getSymbol(const Location& loc);
public:
  void createMap(const std::string& filename);
  GameData::LocationMap& getMap();
  GameData::RenderMap& getRenderMap();
  GameData::Size getMapSize() const;
  void update();
  void render();
};