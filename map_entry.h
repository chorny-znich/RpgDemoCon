#pragma once
#include "game_data.h"
#include <string>

enum class EntryDirection
{
  NONE,
  UP,
  DOWN
};

/**
 * @brief Location on the map that teloprt player
 */
class MapEntry
{
private:
  std::string mId;
  size_t mMapId;
  GameData::Position mPosition;
  std::string mLinkedEntryId;
  size_t mLinkedMapId;
  size_t mVisibility;
  EntryDirection mDirection{ EntryDirection::NONE };
public:
  void setId(const std::string& id);
  std::string getId() const;
  void setMapId(size_t id);
  size_t getMapId() const;
  void setPosition(Position pos);
  GameData::Position getPosition() const;
  void setLinkedEntryId(const std::string& id);
  std::string getLinkedEntryId() const;
  void setLinkedMapId(size_t id);
  size_t getLinkedMapId() const;
  void setVisibility(size_t visibility);
  void setDirection(EntryDirection direction);
  EntryDirection getDirection() const;
};