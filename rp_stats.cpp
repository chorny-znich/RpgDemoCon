#include "rp_stats.h"
#include <iostream>
#include <format>

void RPStats::setName(const std::string& name)
{
	mName = name;
}
const std::string& RPStats::getName() const
{
	return mName;
}

void RPStats::increasePrimaryStat(const std::string& str)
{
	mPrimaryStats[str] += 1;
}

void RPStats::decreasePrimaryStat(const std::string& str)
{
	mPrimaryStats[str] -= 1;
}

size_t RPStats::getPrimaryStatValue(const std::string& str)
{
	return mPrimaryStats[str];
}

void RPStats::setSecondaryStatValue(const std::string& str, size_t value)
{
	mSecondaryStats[str] = value;
}

size_t RPStats::getSecondaryStatValue(const std::string& str) const
{
	return mSecondaryStats.at(str);
}

void RPStats::showSecondaryStats() const
{
	std::cout << "Secondary stats:\n";
	//std::cout << std::format("  Money - {}\n", getMoney());
	//std::cout << std::format("  Health - {}\n", getMaxHealth());
	for (const auto& stat : mSecondaryStats) {
		std::cout << std::format("  {} - {}\n", stat.first, stat.second);
	}
	std::cout << "\n";
}