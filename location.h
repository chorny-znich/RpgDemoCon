#pragma once
#include <string>
#include <utility>

/**
 * @brief A map unit, usually a tile
 * version 1.1.0
*/

using Position = std::pair<size_t, size_t>;

class Location
{
private:
  size_t mId;
  Position mPosition;
  std::string mFloorLayerId;
  std::string mObjectLayerId;
  bool mPassable{ true };
public:
  void setId(size_t id);
  size_t getId() const;
  void setPosition(Position pos);
  Position getPosition() const;
  void setFloorLayerId(const std::string& id);
  const std::string& getFloorLayerId() const;
  void setObjectLayerId(const std::string& id);
  const std::string& getObjectLayerId() const;
  void setPassability(bool value);
  bool isPassable() const;
};