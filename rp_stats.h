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
const std::vector<std::string> SecondaryStatsList{
	"Attack",
	"Ranged attack",
	"Defence",
	"Attention",
	"Reaction", 
	"Energy"
};
const std::vector<std::string> SkillsList{
		"Search",
		"Athletic",
		"Dodge",
		"Deft hands"
};
/**
 * @brief Role-play statistics for all entities
 */
class RPStats
{
protected:
  std::string mName{};
	std::size_t mMoney{ 0 };

	std::unordered_map<std::string, size_t> mPrimaryStats{
		{PrimaryStatsList[0], 1},
		{PrimaryStatsList[1], 1},
		{PrimaryStatsList[2], 1},
		{PrimaryStatsList[3], 1},
		{PrimaryStatsList[4], 1},
		{PrimaryStatsList[5], 1}
	};
	std::unordered_map<std::string, size_t> mSecondaryStats{
		{SecondaryStatsList[0], 1},
		{SecondaryStatsList[1], 1},
		{SecondaryStatsList[2], 1},
		{SecondaryStatsList[3], 1},
		{SecondaryStatsList[4], 1},
		{SecondaryStatsList[5], 1}
	};
	std::unordered_map<std::string, size_t> mSkills{
		{SkillsList[0], 0},
		{SkillsList[1], 0},
		{SkillsList[2], 0},
		{SkillsList[3], 0}
	};

public:
  void setName(const std::string& name);
  const std::string& getName() const;
	void setMoney(size_t money);
	void increaseMoney(size_t money);
	void decreaseMoney(size_t money);
	size_t getMoney() const;
	size_t& getMoney();

	// Primary stats
	void increasePrimaryStat(const std::string& str);
	void decreasePrimaryStat(const std::string& str);
	size_t getPrimaryStatValue(const std::string& str);
	//void showPrimaryStats() const;
	// Secondary stats
	void setSecondaryStatValue(const std::string& str, size_t value);
	size_t getSecondaryStatValue(const std::string& str) const;
	const std::string showSecondaryStats() const;
	bool checkSecondaryStat(const std::string& name, int value) const;
	// skills
	const std::string showSkills() const;
};