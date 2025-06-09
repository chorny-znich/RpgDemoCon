#pragma once
#include "game_data.h"
#include <vector>
#include <unordered_map>
#include <memory>

class Map;
class MapManager;
class ObjectManager;

/**
 * @brief A base class for all entities
*/
class Entity
{
private:
  bool mActive{ true };
protected:
  GameData::Position mPosition{ 0, 0 };
  GameData::Movement mMovement{ 0, 0 };
  char mImage;

  std::unordered_map<GameData::Direction, std::vector<GameData::EntityEnvironment>> mEntityEnvironment
  {
    {GameData::Direction::CURRENT, {}},
    {GameData::Direction::NORTH, {}},
    {GameData::Direction::EAST, {}},
    {GameData::Direction::SOUTH, {}},
    {GameData::Direction::WEST, {}}
  };
public:
  void spawn(GameData::Position pos);
  void checkEnvironment(Map& map, MapManager& mapManager, ObjectManager& objects);
  void setActiveStatus(bool status);
  bool isActive() const;
  GameData::Position getPosition() const;
  void setMovement(GameData::Movement movement);
  GameData::Movement getMovement() const;
};