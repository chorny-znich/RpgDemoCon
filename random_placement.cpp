#include "random_placement.h"
#include <set>
#include <random>

RandomPlacement::RandomPlacement(Map& map, std::vector<std::shared_ptr<GameObject>>& obj) :
  rmMap{ map },
  rmObjects{ obj }
{
}

/**
 * @brief Find places where objects with random coordinates can be placing
 * @return vector of random coordinates where objects can be placing
 */
std::vector<GameData::Position> RandomPlacement::place()
{
  std::vector<GameData::Position> result;
  std::set<GameData::Position> tempResult;
  GameData::LocationMap& map = rmMap.getMap();

  for (const auto& item : map) {
    if (item.isPassable()) {
      tempResult.insert(item.getPosition());
      //result.push_back(item.getPosition());
    }
  }
  // remove from available positions objects that placed directly
  for (const auto& item : rmObjects) {
    GameData::Position pos = item->getPosition();
    if (tempResult.find(item->getPosition()) != tempResult.end()) {
      tempResult.erase(pos);
    }
  }
  // copy objects from a set to a vector
  for (const auto& item : tempResult) {
    result.push_back(item);
  }
  // shuffle available coordinates in the container
  std::random_device rd;
  std::mt19937_64 gen(rd());
  std::shuffle(result.begin(), result.end(), gen); 
  return result;
}