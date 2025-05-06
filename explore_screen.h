#pragma once
#include "screen.h"
#include "map_manager.h"
#include "map.h"

/**
 * @brief Core screen of the game
 */
class ExploreScreen : public Screen
{
private:
	MapManager mMapManager;
	Map mCurrentMap;

	void changeMap();
public:
	void init() override;
	void handleInput() override;
	void update() override;
	void render() override;
};

