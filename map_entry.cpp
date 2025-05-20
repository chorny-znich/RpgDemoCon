#include "map_entry.h"

void MapEntry::setId(const std::string& id)
{
  mId = id;
}

std::string MapEntry::getId() const
{
  return mId;
}

void MapEntry::setMapId(size_t id)
{
  mMapId = id;
}

size_t MapEntry::getMapId() const
{
  return mMapId;
}

void MapEntry::setPosition(Position pos)
{
  mPosition = pos;
}

Position MapEntry::getPosition() const
{
  return mPosition;
}

void MapEntry::setLinkedEntryId(const std::string& id)
{
  mLinkedEntryId = id;
}

std::string MapEntry::getLinkedEntryId() const
{
    return mLinkedEntryId;
}

void MapEntry::setLinkedMapId(size_t id)
{
  mLinkedMapId = id;
}

size_t MapEntry::getLinkedMapId() const
{
  return mLinkedMapId;
}

void MapEntry::setVisibility(size_t visibility)
{
  mVisibility = visibility;
}

void MapEntry::setDirection(EntryDirection direction)
{
  mDirection = direction;
}

EntryDirection MapEntry::getDirection() const
{
  return mDirection;
}
