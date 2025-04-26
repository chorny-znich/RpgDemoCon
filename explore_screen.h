#pragma once
#include "screen.h"

/**
 * @brief Core screen of the game
 */
class ExploreScreen : public Screen
{
public:
	void init() override;
	void handleInput() override;
	void update() override;
	void render() override;
};

