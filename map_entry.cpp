#include "map_entry.h"

void MapEntry::setId(const std::string& id)
{
  mId = id;
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

void MapEntry::setVisibility(size_t visibility)
{
  mVisibility = visibility;
}
