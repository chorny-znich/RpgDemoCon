#pragma once
#include "map.h"
#include "map_entry.h"
#include <vector>
#include <unordered_map>

using Entries = std::unordered_map <size_t, std::vector<MapEntry>>;
/**
 * @brief Manage game's maps
 * Load all maps from ini files. Save them to the database.
 */
class MapManager
{
private:
  const size_t NUMBER_OF_MAPS = 1;
  size_t mCurrentMapIndex{ 0 };
  std::unordered_map<size_t, Map> mMaps;
  Entries mEntries;

  void loadEntries();
public:
  void init();
  Map& getCurrentMap();
};

