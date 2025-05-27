#include "rp_stats.h"

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
