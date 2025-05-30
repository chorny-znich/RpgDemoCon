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

void RPStats::setMoney(size_t money)
{
	mMoney = money;
}

void RPStats::increaseMoney(size_t money)
{
	mMoney += money;
}

void RPStats::decreaseMoney(size_t money)
{
	mMoney = (money > mMoney) ? 0 : mMoney - money;
}

size_t RPStats::getMoney() const
{
	return mMoney;
}

size_t& RPStats::getMoney()
{
	return mMoney;
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

const std::string RPStats::showSecondaryStats() const
{
	std::string result{};
	result.append("Secondary stats:\n");
	//std::cout << std::format("  Money - {}\n", getMoney());
	//std::cout << std::format("  Health - {}\n", getMaxHealth());
	for (const auto& stat : mSecondaryStats) {
		result.append(std::format("  {} - {}\n", stat.first, stat.second));
	}
	result.append("\n");

	return result;
}

const std::string RPStats::showSkills() const
{
	std::string result{};
	result.append("Skills:\n");
	for (const auto& [skill, value] : mSkills) {
		result.append(std::format("  {} -- {}\n", skill, value));
	}
	result.append("\n");

	return result;
}
