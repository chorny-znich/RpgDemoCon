#pragma once
#include "game_data.h"

/**
 * @brief Player's avatar who can act on the map and have RP statistic
 */
class Player
{
private:
  const int CHAR_STEP{ 1 };
  Position mPosition{ 1, 1 };
  GameData::Movement mMovement{ 0, 0 };
  const char SYMBOL = '@';
public:
  void moveWest();
  void moveEast();
  void moveNorth();
  void moveSouth();

  void update(GameData::RenderMap& renderMap);
};