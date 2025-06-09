#pragma once
#include "map.h"
#include "map_entry.h"
#include <vector>
#include <set>
#include <unordered_map>

using Entries = std::unordered_map <size_t, std::vector<MapEntry>>;
/**
 * @brief Manage game's maps
 * Load all maps from ini files. Save them to the database.
 */
class MapManager
{
private:
  const size_t NUMBER_OF_MAPS = 3;
  size_t mPrevMapIndex{ 0 };
  size_t mCurrentMapIndex{ 0 };
  GameData::Position mPlayerSpawnPosition{ 1, 1 };
  std::unordered_map<size_t, Map> mMaps;
  Entries mEntries;
  std::set<size_t> mVisitedMaps;

  void loadEntries();
public:
  void init();
  void render(GameData::RenderMap& map);
  size_t getPrevMapIndex() const;
  size_t getCurrentMapIndex() const;
  Map& getCurrentMap();
  bool useEntry(GameData::Position pos);
  GameData::Position getPlayerSpawnPosition() const;

  void setVisited();
  bool isVisited() const;
};