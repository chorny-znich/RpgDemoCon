#include "explore_screen.h"

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
}

void ExploreScreen::handleInput()
{
}

void ExploreScreen::update()
{
}

void ExploreScreen::render()
{
}
