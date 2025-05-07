#include "explore_screen.h"
#include "game_state.h"
#include <conio.h>

/**
 * @brief Change game's map after starting the game or switch between maps during the game  
 */
void ExploreScreen::changeMap()
{
  // Load a new current map 
  mCurrentMap = mMapManager.getCurrentMap();
}

void ExploreScreen::init()
{
  mMapManager.init();
  changeMap();
}

void ExploreScreen::handleInput()
{
  if (mGameplayState == GameplayState::PLAYER_INPUT) {
    if (_kbhit()) {
      int cmd = _getch();
      switch (cmd) {
      case 'q':
        GameState::destroyScreen();
        system("cls");
        break;
      }
    }

    mGameplayState = GameplayState::PLAYER_TURN;
  }
}

void ExploreScreen::update()
{
  if (mGameplayState == GameplayState::PLAYER_TURN) {
    mCurrentMap.update();
    mPlayer.update(mCurrentMap.getRenderMap());
    mGameplayState = GameplayState::PLAYER_TURN_SHOW;
  }
}

void ExploreScreen::render()
{
  if (mGameplayState == GameplayState::PLAYER_TURN_SHOW) {
    mCurrentMap.render();
    mGameplayState = GameplayState::PLAYER_INPUT;
  }
}
