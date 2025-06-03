#pragma once
#include "game_object.h"
#include "map.h"
#include "game_data.h"
#include <vector>
#include <unordered_map>
#include <memory>

/**
 * @brief Manage game's objects
 */
class ObjectManager
{
private:
  std::vector<std::shared_ptr<GameObject>> mObjects;
  std::vector<std::shared_ptr<GameObject>> mRandomObjects;
  std::unordered_map<size_t, std::string> mObjectList;
public:
  void init();
  void render(GameData::RenderMap& map);
  void createObjects(size_t currentMapIndex);
  void createRandomObjects(Map& map);
  std::shared_ptr<GameObject> getObject(GameData::Position);
  void deleteObject(GameData::Position pos);
};