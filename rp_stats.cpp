#include "rp_stats.h"

void RPStats::setName(const std::string& name)
{
	mName = name;
}
const std::string& RPStats::getName() const
{
	return mName;
}