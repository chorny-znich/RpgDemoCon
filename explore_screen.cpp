#include "explore_screen.h"
#include "game_state.h"
#include <conio.h>

bool ExploreScreen::detectCollision(GameData::Position pos, GameData::Movement move)
{
  GameData::LocationMap& map = mCurrentMap.getMap();
  GameData::Position newPosition{ pos.first + move.first, pos.second + move.second };
  if (!map.at(newPosition.second * mCurrentMap.getMapSize().first + newPosition.first).isPassable()) {
    return true;
  }
  return false;
}

/**
 * @brief Change game's map after starting the game or switch between maps during the game  
 */
void ExploreScreen::changeMap()
{
  // Load a new current map 
  mCurrentMap = mMapManager.getCurrentMap();
  mPlayer.spawn(mMapManager.getPlayerSpawnPosition());
  mGameplayState = GameplayState::PLAYER_TURN;
  system("cls");
}

/**
 * @brief Teleport to the next or previous map
 */
void ExploreScreen::useLadder()
{
  GameData::Position currentPlayerLocation = mPlayer.getPosition();
  if (mMapManager.useEntry(currentPlayerLocation)) {
    changeMap();
  }
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
      case 'a':
        mPlayer.moveWest();
        mPlayer.setMovingState(true);
        break;
      case 'd':
        mPlayer.moveEast();
        mPlayer.setMovingState(true);
        break;
      case 'w':
        mPlayer.moveNorth();
        mPlayer.setMovingState(true);
        break;
      case 's':
        mPlayer.moveSouth();
        mPlayer.setMovingState(true);
        break;
      case 'l':
        useLadder();
        break;
      }
    }
    mGameplayState = GameplayState::PLAYER_TURN;
  }
}

void ExploreScreen::update()
{
  if (mGameplayState == GameplayState::PLAYER_TURN) {
    // move the player
    if (mPlayer.isMoving()) {
      if (detectCollision(mPlayer.getPosition(), mPlayer.getMovement())) {
        mPlayer.setMovement({ 0, 0 });
        mPlayer.setMovingState(false);
      }
    }

    mCurrentMap.update();
    mPlayer.update();
    mGameplayState = GameplayState::PLAYER_TURN_SHOW;
  }
}

void ExploreScreen::render()
{
  if (mGameplayState == GameplayState::PLAYER_TURN_SHOW) {
    mMapManager.render(mCurrentMap.getRenderMap());
    mPlayer.render(mCurrentMap.getRenderMap());
    mCurrentMap.render();
    mGameplayState = GameplayState::PLAYER_INPUT;
  }
}