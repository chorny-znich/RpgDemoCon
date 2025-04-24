#pragma once
#include "screen.h"
#include "game_state.h"
#include <unordered_map>
#include <string>
#include <memory>

/**
 * @brief Create a game screen and add it to the screens' stack
 * version 1.1.0
 */
class ScreenManager
{
private:
  std::unordered_map <std::string, std::unique_ptr<Screen>> mScreens;
public:
  ScreenManager() = delete;
  template <typename ScreenPointer>
  static void createScreen(std::string screenId)
  {
    std::unique_ptr<ScreenPointer> pScreen = std::make_unique<ScreenPointer>();
    pScreen->init();
    GameState::addScreen(std::move(pScreen));
  }
};