#pragma once
#include "rp_stats.h"
#include "entity.h"
#include "game_data.h"

/**
 * @brief Player's avatar who can act on the map and have RP statistic
 */
class Player : public RPStats, public Entity
{
private:
  const int CHAR_STEP{ 1 };
  bool mMoving{ false };
public:
  Player();
  void create();
  void moveWest();
  void moveEast();
  void moveNorth();
  void moveSouth();
  void setMovingState(bool move);
  bool isMoving() const;
  void update();
  void render(GameData::RenderMap& renderMap);
};