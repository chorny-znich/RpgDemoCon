#include "player.h"
#include "map_symbols.h"
#include "ini_parser.h"

Player::Player()
{
  mImage = MapSymbols::PLAYER;
}

/**
 * @brief Load player's attributes from the file
 */
void Player::create()
{
  dr::IniDocument doc = dr::load(GameData::path::PlayerInfo);
  dr::Section section = doc.getSection("Player");
  setName(section.at("Name"));
  // Set primary stats
  section = doc.getSection("Primary stats");
  for (auto& stat : mPrimaryStats) {
    stat.second = std::stoul(section.at(stat.first));
  }
  // Set secondary stats
  section = doc.getSection("Secondary stats");
  for (auto& stat : mSecondaryStats) {
    stat.second = std::stoul(section.at(stat.first));
  }
  // set skills
  section = doc.getSection("Skills");
  for (auto& skill : mSkills) {
    skill.second = std::stoul(section.at(skill.first));
  }
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

void Player::setMovingState(bool move)
{
  mMoving = move;
}

bool Player::isMoving() const
{
  return mMoving;
}

void Player::update()
{
  // move the player
  mPosition.first += mMovement.first;
  mPosition.second += mMovement.second;
  mMovement = { 0, 0 };
  mMoving = false;
}

void Player::render(GameData::RenderMap& renderMap)
{
  renderMap[mPosition.second][mPosition.first] = mImage;
}