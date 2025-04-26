#include "location.h"

void Location::setId(size_t id)
{
  mId = id;
}

size_t Location::getId() const
{
  return mId;
}

void Location::setPosition(Position pos)
{
  mPosition = pos;
}

Position Location::getPosition() const
{
  return mPosition;
}

void Location::setFloorLayerId(const std::string& id)
{
  mFloorLayerId = id;
}

const std::string& Location::getFloorLayerId() const
{
  return mFloorLayerId;
}

void Location::setObjectLayerId(const std::string& id)
{
  mObjectLayerId = id;
}

const std::string& Location::getObjectLayerId() const
{
  return mObjectLayerId;
}

void Location::setPassability(bool value)
{
  mPassable = value;
}

bool Location::isPassable() const
{
  return mPassable;
}