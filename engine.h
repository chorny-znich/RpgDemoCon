#pragma once
#include "game_state.h"
#include <Windows.h>

/**
 * @brief The game cycle
 */
class Engine
{
private:
  HANDLE mConsoleHandle;
  GameState mGameState;

  bool mRunning{ true };
public:
  void init();
  void input();
  void update();
  void render();

  void run();
};