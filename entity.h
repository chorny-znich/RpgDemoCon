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
  /**
   * @brief Directionds on the map with related coords
   */
  std::map<GameData::Direction, Position> DirectionWithCoords
  {
    {GameData::Direction::CURRENT, {0, 0}},
    {GameData::Direction::NORTH, {0, -1}},
    {GameData::Direction::EAST, {1, 0}},
    {GameData::Direction::SOUTH, {0, 1}},
    {GameData::Direction::WEST, {-1, 0}}
  };

  bool mActive{ true };
protected:
  GameData::Position mPosition{ 0, 0 };
  GameData::Movement mMovement{ 0, 0 };
  char mImage;

  std::unordered_map<GameData::Direction, std::vector<GameData::TileEnvironment>> mEntityEnvironment
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
  GameData::TileEnvironment checkTile(GameData::Position pos, Map& map, MapManager& mapManager, ObjectManager& objects);
  std::vector<GameData::Position> getObjectInEnvironment() const;
  void setActiveStatus(bool status);
  bool isActive() const;
  GameData::Position getPosition() const;
  void setMovement(GameData::Movement movement);
  GameData::Movement getMovement() const;
};