#pragma once
#include "rp_stats.h"
#include "game_data.h"

/**
 * @brief Player's avatar who can act on the map and have RP statistic
 */
class Player : public RPStats
{
private:
  const int CHAR_STEP{ 1 };
  Position mPosition{ 1, 1 };
  GameData::Movement mMovement{ 0, 0 };
  bool mMoving{ false };
  const char SYMBOL = '@';
public:
  void spawn(GameData::Position pos);
  void moveWest();
  void moveEast();
  void moveNorth();
  void moveSouth();
  void setMovement(GameData::Movement movement);
  GameData::Movement getMovement() const;
  void setMovingState(bool move);
  bool isMoving() const;
  GameData::Position getPosition() const;
  void update();
  void render(GameData::RenderMap& renderMap);
};