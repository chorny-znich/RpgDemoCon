#pragma once
#include "screen.h"
#include <unordered_map>
#include <functional>

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
	void processUserInput(size_t option);
	void startGame();
	void createHero();
	void closeScreen();

public:
	void init() override;
	void handleInput() override;
	void update() override;
	void render() override;
};

