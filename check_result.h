#pragma once
#include <string>

/**
 * @brief Result of the check of the player's stats
 */
class CheckResult
{
private:
  bool mResult;
  std::string mLogResult;
public:
  void setResult(bool result);
  bool getResult() const;
  void createLog(const std::string log);
  const std::string showLog() const;
};

