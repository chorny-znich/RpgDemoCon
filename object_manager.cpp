#include "object_manager.h"
#include "money.h"
#include "random_placement.h"
#include "ini_parser.h"
#include "game_data.h"
#include <string>
#include <format>
#include <iostream>
#include <algorithm>

void ObjectManager::init()
{
  for (size_t i{ 0 }; i < GameData::NUMBER_OF_MAPS; i++) {
    mObjectList.insert({ i, std::format("{}objects_{}.ini", GameData::ObjectInfo, i) });
  }
}

void ObjectManager::render(GameData::RenderMap& map)
{
  for (const auto& obj : mObjects) {
    map[obj->getPosition().second][obj->getPosition().first] = obj->getImage();
  }
}

/**
 * @brief Create objects from the ini file for the current map
 * @param currentMapIndex - index of the current map 
 */
void ObjectManager::createObjects(size_t currentMapIndex)
{
  mObjects.clear();
  mRandomObjects.clear();
  std::unordered_map<std::string, size_t> objects;
  dr::IniDocument doc = dr::load(mObjectList.at(currentMapIndex));
  dr::Section section = doc.getSection("general");
  objects.insert({ "money", std::stoul(section.at("Money_amount")) });

  // Create money objects
  for (size_t i{ 1 }; i <= objects.at("money"); i++) {
    bool randomPosition = false;
    std::shared_ptr<Money> pMoney = std::make_shared<Money>();
    std::string sectionName = "money_" + std::to_string(i);
    dr::Section section = doc.getSection(sectionName);
    if (section.at("Position_x") != "random" && section.at("Position_y") != "random") {
      pMoney->setPosition({ std::stoi(section.at("Position_x")), std::stoi(section.at("Position_y")) });
    }
    else {
      randomPosition = true;
    }
    pMoney->setVisibility(std::stoul(section.at("Visibility")));
    mObjects.push_back(std::move(pMoney));
    // Push object with the random placement
    if (randomPosition) {
      mRandomObjects.push_back(mObjects.back());
    }
  }
}

/**
 * @brief Create objects with random positions on the map 
 * @param map - reference to the current map
 */
void ObjectManager::createRandomObjects(Map& map)
{
  RandomPlacement rp(map, mObjects);
  std::vector<GameData::Position> positions = rp.place();
  auto iter = positions.begin();
  // Place objects with the random placement
  for (auto& item : mRandomObjects) {
    item->setPosition({ iter->first, iter->second });
    iter++;
  }
}

/**
 * @brief Save the set of objects fir the current map to the object's database
 */
void ObjectManager::updateObjects(size_t currentMapIndex)
{
  mObjectsDatabase[currentMapIndex] = mObjects;
}

/**
 * @brief Change the list of objects for the current map
 * @param index  - index of the current map
 */
void ObjectManager::changeObjects(size_t index)
{
  mObjects = mObjectsDatabase.at(index);
}

/**
 * @brief find the object at the current position
 * @param  position on the map
 * @return shared_ptr to objects or nullptr if there is no object in this location 
 */
std::shared_ptr<GameObject> ObjectManager::getObject(GameData::Position pos)
{
  auto iter = std::find_if(mObjects.begin(), mObjects.end(), [pos](const auto& obj) {
    return obj->getPosition() == pos;
    });
  if (iter != mObjects.end()) {
    return *iter;
  }
  else {
    return nullptr;
  }
}

/**
 * @brief Delete the object at the current position
 * @param pos - position on the map 
 */
void ObjectManager::deleteObject(GameData::Position pos)
{
  auto iter = std::find_if(mObjects.begin(), mObjects.end(), [pos](const auto& obj) {
    return pos == obj->getPosition();
    });
  mObjects.erase(iter);
}
