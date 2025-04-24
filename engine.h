#pragma once
#include <Windows.h>

/**
 * @brief The game cycle
 */
class Engine
{
private:
  HANDLE mConsoleHandle;

  bool mRunning{ true };
public:
  void init();
  void input();
  void update();
  void render();

  void run();
};