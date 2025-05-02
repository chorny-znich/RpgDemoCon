#pragma once
#include "location.h"
#include <string>
#include <vector>

/**
 * @brief Game metadata
 */
namespace GameData
{
  using TextMap = std::vector<std::string>;
  using LocationMap = std::vector<Location>;
  using Size = std::pair<size_t, size_t>;
}