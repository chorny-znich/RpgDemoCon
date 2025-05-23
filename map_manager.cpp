#include "map_manager.h"
#include "ini_parser.h"
#include "game_data.h"
#include "map_symbols.h"
#include <format>
#include <algorithm>
#include <iostream>


/**
 * @brief Load map entries from the ini file
 */
void MapManager::loadEntries()
{
  dr::IniDocument doc = dr::load(GameData::path::Entry);
  dr::Section generalInfo = doc.getSection("general");
  size_t numberOfEntries = std::stoul(generalInfo.at("number_of_entries"));
  for (size_t i{ 0 }; i < numberOfEntries; i++) {
    dr::Section section = doc.getSection(std::format("entry_{}", i));
    MapEntry newMapEntry;
    newMapEntry.setId(section.at("id"));
    newMapEntry.setMapId(std::stoul(section.at("map_id")));
    newMapEntry.setPosition({ std::stoul(section.at("position_x")), std::stoul(section.at("position_y")) });
    newMapEntry.setLinkedEntryId(section.at("linked_entry_id"));
    newMapEntry.setLinkedMapId(std::stoul(section.at("linked_map_id")));
    newMapEntry.setVisibility(std::stoul(section.at("visibility")));
    std::string entryDirection = section.at("direction");
    if (entryDirection == "up") {
      newMapEntry.setDirection(EntryDirection::UP);
    }
    else {
      newMapEntry.setDirection(EntryDirection::DOWN);
    }
    mEntries[newMapEntry.getMapId()].push_back(newMapEntry);
  }
}

void MapManager::init()
{
  for (size_t i{ 0 }; i < NUMBER_OF_MAPS; i++) {
    Map newMap;
    newMap.createMap(std::format("data/maps/map_{}.ini", i));
    mMaps.insert({ i, newMap });
  }
  loadEntries();
}

/**
 * @brief Draw a symbol for a ladder
 * @param map reference to the render map 
 */
void MapManager::render(GameData::RenderMap& map)
{
  for (const auto& entry : mEntries.at(mCurrentMapIndex)) {
    char symbol = (entry.getDirection() == EntryDirection::UP) ? MapSymbols::LADDER_UP : MapSymbols::LADDER_DOWN;
    map[entry.getPosition().second][entry.getPosition().first] = symbol;
  }
}

size_t MapManager::getCurrentMapIndex() const
{
    return mCurrentMapIndex;
}

/**
 * @brief Return the reference to map according the index of the current map
 * @return reference to map
 */
Map& MapManager::getCurrentMap()
{
  return mMaps.at(mCurrentMapIndex);
}

/**
 * @brief Find the entry at the player's location and teleport the player to the according map
 * @param Player location 
 */
bool MapManager::useEntry(GameData::Position pos)
{
  std::vector<MapEntry>& currentEntries = mEntries.at(mCurrentMapIndex);
  const auto iter = std::find_if(currentEntries.begin(), currentEntries.end(), [pos](const auto& value) {
    return pos == value.getPosition();
    });
  if (iter != currentEntries.end()) {
    std::string newEntryId = iter->getLinkedEntryId();
    size_t newMapId = iter->getLinkedMapId();
    //std::cout << std::format("entry id is {}\n", newEntryId);
    //std::cout << std::format("map id is {}\n", newMapId);

    std::vector<MapEntry>& newEntries = mEntries.at(newMapId);
    const auto newIter = std::find_if(newEntries.begin(), newEntries.end(), [newEntryId](const auto& value) {
      return newEntryId == value.getId();
      });
    if (newIter != newEntries.end()) {
      mCurrentMapIndex = newIter->getMapId();
      mPlayerSpawnPosition = newIter->getPosition();
      //std::cout << std::format("map index is {}\n", mCurrentMapIndex);
      //std::cout << std::format("player spawn at {},{}\n", mPlayerSpawnPosition.first, mPlayerSpawnPosition.second);
    }
    else {
      return false;
    }
  }
  else {
    return false;
  }
  return true;
}

GameData::Position MapManager::getPlayerSpawnPosition() const
{
  return mPlayerSpawnPosition;
}
