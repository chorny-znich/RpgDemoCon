#include "player.h"

/**
 * @brief Set the start player's position on the map
 * @param Player's position
 */
void Player::spawn(GameData::Position pos)
{
  mPosition = pos;
}

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

void Player::setMovement(GameData::Movement movement)
{
  mMovement = movement;
}

GameData::Movement Player::getMovement() const
{
  return mMovement;
}

void Player::setMovingState(bool move)
{
  mMoving = move;
}

bool Player::isMoving() const
{
  return mMoving;
}

GameData::Position Player::getPosition() const
{
  return mPosition;
}

void Player::update()
{
  // move the player
  mPosition.first += mMovement.first;
  mPosition.second += mMovement.second;
  mMovement = { 0, 0 };
  mMoving = false;
  // draw a player on the map
}

void Player::render(GameData::RenderMap& renderMap)
{
  renderMap[mPosition.second][mPosition.first] = SYMBOL;
}