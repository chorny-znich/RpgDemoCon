#include "game_state.h"
#include <assert.h>

GameState::GameState()
{
  assert(mpInstance == nullptr);
  mpInstance.reset(this);
}

/**
 * @brief Add the game screen to stack
 * @param unique_ptr on game screen
*/
void GameState::addScreen(std::unique_ptr<Screen> pScreen)
{
  mpInstance->mScreens.push(std::move(pScreen));
}

/**
 * @brief Pop the game screen from stack
*/
void GameState::destroyScreen()
{
  mpInstance->mScreens.pop();
}

/**
 * @brief Destroy all game screens
*/
void GameState::destroyAllScreens()
{
  auto& screens = mpInstance->mScreens;
  while (!screens.empty()) {
    screens.pop();
  }
}

/**
 * @brief Get active game screen
 * @return reference on the  unique_ptr to the active game screen
*/
std::unique_ptr<Screen>& GameState::getCurrent()
{
  return mpInstance->mScreens.top();
}

/**
 * @brief Check if the there aren't any game screens in the stack
 * @return Are there any game screens in the stack
*/
bool GameState::isEmpty() const
{
  return mpInstance->mScreens.empty();
}
