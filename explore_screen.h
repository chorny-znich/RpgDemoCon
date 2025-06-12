#pragma once
#include "screen.h"
#include "map_manager.h"
#include "object_manager.h"
#include "map.h"
#include "player.h"
#include "console_ui.h"

#include <vector>

/**
 * @brief Core screen of the game
 */
class ExploreScreen : public Screen
{
private:
	enum class GameplayState
	{
		PLAYER_INPUT,
		PLAYER_TURN,
		PLAYER_TURN_SHOW
	};
private:
	MapManager mMapManager;
	ObjectManager mObjectManager;
	Map mCurrentMap;
	Player mPlayer;
	GameplayState mGameplayState{ GameplayState::PLAYER_TURN };
	ConsoleUI mConsoleUI;

	bool detectCollision(GameData::Position pos, GameData::Movement move);
	void checkVisibility(std::vector<GameData::Position> pos);

	void changeMap();

	void useLadder();
	void pickItem();
public:
	void init() override;
	void handleInput() override;
	void update() override;
	void render() override;
};

