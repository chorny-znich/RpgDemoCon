#pragma once
#include "game_object.h"

/**
 * @brief Represent the amount of money that player can spend to buy goods or get when sell items
 */
class Money : public GameObject
{
private:
  size_t const MIN_AMOUNT = 1;
  size_t const MAX_AMOUNT = 10;
  size_t mAmount{ 0 };

  void setAmount();

public:
  Money();
  size_t getAmount() const;
};