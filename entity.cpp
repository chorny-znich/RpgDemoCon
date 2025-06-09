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
  GameData::EntityEnvironment entityEnvironment;
  if (map.getCurrentLocation(mPosition).isPassable()) {
    entityEnvironment.mPassability = true;
  }
  if (mapManager.isEntry(mPosition)) {
    entityEnvironment.mEnvironmentType = GameData::EnvironmentType::ENTRY;
  }
  else if (objects.getObject(mPosition)) {
    entityEnvironment.mEnvironmentType = GameData::EnvironmentType::OBJECT;
  }
  mEntityEnvironment[GameData::Direction::CURRENT].push_back(std::move(entityEnvironment));
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