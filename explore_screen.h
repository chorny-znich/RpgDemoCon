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
	enum class GameplayState
	{
		PLAYER_INPUT,
		PLAYER_TURN,
		PLAYER_TURN_SHOW
	};
private:
	MapManager mMapManager;
	Map mCurrentMap;
	Player mPlayer;
	GameplayState mGameplayState{ GameplayState::PLAYER_TURN };

	bool detectCollision(GameData::Position pos, GameData::Movement move);

	void changeMap();
public:
	void init() override;
	void handleInput() override;
	void update() override;
	void render() override;
};

