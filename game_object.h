#pragma once
#include "game_object_type.h"
#include "game_data.h"
#include <string>

/**
 * @brief Base class for the all objects in the game
 */
class GameObject
{
private:
  size_t mId;
  std::string mName;
  GameData::Position mPosition;
  char mImage;
  size_t mPrice;
  bool mVisible;
  size_t mVisibility;
  size_t mAmount;
protected:
  GameObjectType mType;
  GameObjectSubType mSubType;
public:
  GameObject(GameObjectType type, GameObjectSubType subType);
  void setId(size_t id);
  size_t getId() const;
  void setType(GameObjectType type);
  GameObjectType getType() const;
  void setSubType(GameObjectSubType subType);
  GameObjectSubType getSubType() const;
  void setName(const std::string& name);
  std::string getName() const;
  void setPosition(GameData::Position pos);
  GameData::Position getPosition() const;
  void setImage(char symbol);
  char getImage() const;
  void setPrice(size_t value);
  size_t getPrice() const;
  void setVisibleStatus(bool value);
  bool isVisible() const;
  void setVisibility(size_t value);
  size_t getVisibility() const;
  void setAmount(size_t value);
  size_t getAmount() const;
};

