#include "entity.h"
#include "map.h"
#include "map_manager.h"
#include "object_manager.h"

/**
 * @brief Set the start entitie's position on the map
 * @param Entitie's position
 */
void Entity::spawn(GameData::Position pos)
{
  mPosition = pos;
}

/**
 * @brief check locations in the entitie's field of view
 * @param map - reference to the current map 
 * @param objects - reference to the current map objects
 */
void Entity::checkEnvironment(Map& map, MapManager& mapManager, ObjectManager& objects)
{
  for (auto& [key, value] : mEntityEnvironment) {
    GameData::Position pos{ mPosition.first + DirectionWithCoords[key].first,
      mPosition.second + DirectionWithCoords[key].second };
    value.push_back(checkTile(pos, map, mapManager, objects));
  }

  mEntityEnvironment[GameData::Direction::CURRENT].push_back(checkTile(mPosition, map, mapManager, objects));
}

/**
 * @brief 
 * @param pos - tile's coordinates
 * @param map - reference to the current map
 * @param mapManager - reference to the current map objects
 * @param objects 
 * @return object with information about tile's environment
 */
GameData::TileEnvironment Entity::checkTile(GameData::Position pos, Map& map, MapManager& mapManager, ObjectManager& objects)
{
  GameData::TileEnvironment tileEnvironment;
  if (map.getCurrentLocation(pos).isPassable()) {
    tileEnvironment.mPassability = true;
  }
  if (mapManager.isEntry(pos)) {
    tileEnvironment.mEnvironmentType = GameData::EnvironmentType::ENTRY;
  }
  else if (objects.getObject(pos)) {
    tileEnvironment.mEnvironmentType = GameData::EnvironmentType::OBJECT;
  }
  return tileEnvironment;
}

/**
 * @brief Entities with the active status participate in game interactions (update every frame, rendering on the screen etc.)
 * @param status - true if the object is active, otherwise - false
 */
void Entity::setActiveStatus(bool status)
{
  mActive = status;
}

bool Entity::isActive() const
{
  return mActive;
}

GameData::Position Entity::getPosition() const
{
  return mPosition;
}

void Entity::setMovement(GameData::Movement movement)
{
  mMovement = movement;
}

GameData::Movement Entity::getMovement() const
{
  return mMovement;
}