#pragma once
#include <string>
#include <vector>
#include <unordered_map>

const size_t START_STATS_POINTS = 24;	// Number of stats points to distrubute when creating a hero

const std::vector<std::string> PrimaryStatsList{
	"Strength", 
	"Stamina",
	"Dexterity",
	"Perception",
	"Intellect",
	"Charisma" 
};
/**
 * @brief Role-play statistics for all entities
 */
class RPStats
{
protected:
  std::string mName{};
	std::unordered_map<std::string, size_t> mPrimaryStats{
		{PrimaryStatsList[0], 1},
		{PrimaryStatsList[1], 1},
		{PrimaryStatsList[2], 1},
		{PrimaryStatsList[3], 1},
		{PrimaryStatsList[4], 1},
		{PrimaryStatsList[5], 1}
	};
public:
  void setName(const std::string& name);
  const std::string& getName() const;

	// Primary stats
	void increasePrimaryStat(const std::string& str);
	void decreasePrimaryStat(const std::string& str);
	size_t getPrimaryStatValue(const std::string& str);
	//void showPrimaryStats() const;
};