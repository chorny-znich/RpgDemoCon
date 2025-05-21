#pragma once

namespace dr 
{
  /**
   * @brief a static class with utilities for the DisRealityGF
   * version 1.0.0
  */
  class EngineUtility
  {
  public:
    EngineUtility() = delete;
    static size_t getRandomInRange(size_t min, size_t max);
  };
}