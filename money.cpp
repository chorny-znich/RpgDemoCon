#include "money.h"
#include "map_symbols.h"
#include "engine_utility.h"

Money::Money() :
  GameObject{ GameObjectType::MONEY, GameObjectSubType::NONE }
{
  setImage(MapSymbols::MONEY);
  setAmount();
}

void Money::setAmount()
{
  mAmount = dr::EngineUtility::getRandomInRange(MIN_AMOUNT, MAX_AMOUNT);
}

size_t Money::getAmount() const
{
  return mAmount;
}