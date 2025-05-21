#include "player.h"
#include "ini_parser.h"

/**
 * @brief Load player's attributes from the file
 */
void Player::create()
{
  dr::IniDocument doc = dr::load(GameData::path::PlayerInfo);
  dr::Section section = doc.getSection("Player");
  setName(section.at("Name"));
}

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