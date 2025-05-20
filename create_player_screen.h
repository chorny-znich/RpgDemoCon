#pragma once
#include "screen.h"
#include "player.h"

/**
 * @brief Screen where the player can setup his avatar
 *        Name the character
 *        Distribute points on main attributes
 *        Distribute points on skills
 */
class CreatePlayerScreen : public Screen
{
private:
  Player mPlayer;
  bool mRenderScreen{ true };

  void setPlayerName();
  void showScreen();
  void createPlayer();
public:
  void init() override;
  void handleInput() override;
  void update() override;
  void render() override;
};