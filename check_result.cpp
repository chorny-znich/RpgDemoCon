#include "check_result.h"

void CheckResult::setResult(bool result)
{
  mResult = result;
}

bool CheckResult::getResult() const
{
  return mResult;
}

void CheckResult::createLog(const std::string log)
{
  mLogResult = std::move(log);
}

const std::string CheckResult::showLog() const
{
  return mLogResult;
}
