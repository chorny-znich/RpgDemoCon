#include "explore_screen.h"
#include "game_state.h"
#include "money.h"
#include <conio.h>

#include <iostream>
#include <format>

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
  mCurrentMap = mMapManager.getCurrentMap();
  if (mMapManager.isVisited()) {
    mObjectManager.changeObjects(mMapManager.getCurrentMapIndex());
  }
  else {
    // Create a map from the given index from the ini file 
    mObjectManager.createObjects(mMapManager.getCurrentMapIndex());
    mObjectManager.createRandomObjects(mMapManager.getCurrentMap());
  }
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
    mObjectManager.updateObjects(mMapManager.getPrevMapIndex());
    mMapManager.setVisited();
    changeMap();
  }
}

/**
 * @brief Pick a game object
 */
void ExploreScreen::pickItem()
{
  GameData::Position currentPlayerLocation = mPlayer.getPosition();
  std::shared_ptr<GameObject> pObject{ nullptr };
  if (pObject = mObjectManager.getObject(currentPlayerLocation)) {
    if (pObject->getType() == GameObjectType::MONEY) {
      auto pMoneyObject = std::static_pointer_cast<Money>(pObject);
      mPlayer.increaseMoney(pMoneyObject->getAmount());
      mConsoleUI.addToHud(UI_Part::LOCATION_INFO, std::format("You pick up ${}", pMoneyObject->getAmount()), 1);
      mObjectManager.deleteObject(currentPlayerLocation);
    }
  }
  else {
    std::cout << "money isn't here\n";
  }
}

void ExploreScreen::init()
{
  mMapManager.init();
  mObjectManager.init();
  mPlayer.create();
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
      case 'p':
        pickItem();
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
    mConsoleUI.addToHud(UI_Part::PLAYER_INFO, std::format("Name: {} ${}", mPlayer.getName(), mPlayer.getMoney()), 0);
    mGameplayState = GameplayState::PLAYER_TURN_SHOW;
  }
}

void ExploreScreen::render()
{
  if (mGameplayState == GameplayState::PLAYER_TURN_SHOW) {
    mConsoleUI.display(UI_Part::PLAYER_INFO);
    mMapManager.render(mCurrentMap.getRenderMap());
    mObjectManager.render(mCurrentMap.getRenderMap());
    mPlayer.render(mCurrentMap.getRenderMap());
    mCurrentMap.render();
    mGameplayState = GameplayState::PLAYER_INPUT;
  }
}