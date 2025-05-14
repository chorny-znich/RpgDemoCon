#pragma once
#include "game_data.h"
#include <string>
#include <vector>

using TxtMap = std::vector<std::string>;

/**
 * @brief Convert a map from txt file into the ini format
 */
class MapConverter
{
private:
  size_t mId{ 0 };
  GameData::Size mMapSize{0, 0};
  TxtMap mMapToConvert;
public:
  void loadMap(const std::string& filename);
  void saveMap();
};