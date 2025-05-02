#pragma once
#include "screen.h"
#include "map_manager.h"

/**
 * @brief Core screen of the game
 */
class ExploreScreen : public Screen
{
private:
	MapManager mMapManager;
public:
	void init() override;
	void handleInput() override;
	void update() override;
	void render() override;
};

