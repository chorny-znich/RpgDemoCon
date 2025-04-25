#pragma once
#include "screen.h"
#include <stack>
#include <memory>

/**
 * @brief Game state management
 * version 1.1.0
*/
class GameState
{
private:
  std::stack<std::unique_ptr<Screen>> mScreens;

  inline static GameState* mpInstance{};
public:
  GameState();
  GameState(const GameState&) = delete;
  GameState& operator= (const GameState&) = delete;

  static void addScreen(std::unique_ptr<Screen> pScreen);
  static void destroyScreen();
  static void destroyAllScreens();

  std::unique_ptr<Screen>& getCurrent();
  bool isEmpty() const;
};