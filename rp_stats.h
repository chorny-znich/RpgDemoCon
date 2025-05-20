#pragma once
#include <string>

/**
 * @brief Role-play statistics for all entities
 */
class RPStats
{
protected:
  std::string mName{};
public:
  void setName(const std::string& name);
  const std::string& getName() const;
};