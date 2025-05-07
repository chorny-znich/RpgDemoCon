#include "player.h"

void Player::moveWest()
{
  mMovement = { -CHAR_STEP, 0 };
}

void Player::moveEast()
{
  mMovement = { CHAR_STEP, 0 };
}

void Player::moveNorth()
{
  mMovement = { 0 , -CHAR_STEP };
}

void Player::moveSouth()
{
  mMovement = { 0 , CHAR_STEP };
}

void Player::update(GameData::RenderMap& renderMap)
{
  renderMap[mPosition.second][mPosition.first] = SYMBOL;
}