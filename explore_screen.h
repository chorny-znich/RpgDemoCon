#pragma once
#include "screen.h"
#include "map_manager.h"
#include "map.h"
#include "player.h"

/**
 * @brief Core screen of the game
 */
class ExploreScreen : public Screen
{
private:
	MapManager mMapManager;
	Map mCurrentMap;
	Player mPlayer;

	void changeMap();
public:
	void init() override;
	void handleInput() override;
	void update() override;
	void render() override;
};

