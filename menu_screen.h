#pragma once
#include "screen.h"

/**
 * @brief Start screen that contains the main menu
 * Available options:
 * Start new game
 * Create a new hero
 * Exit
 */
class MenuScreen : public Screen
{
private:
	bool mRenderScreen{ true };
	void showMainMenu();

public:
	void init() override;
	void handleInput() override;
	void update() override;
	void render() override;
};

