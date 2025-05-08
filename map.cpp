#include "map.h"
#include "ini_parser.h"
#include <iostream>

/**
 * @brief Create the vector of chars representing game's map
 */
void Map::createRenderMap()
{
  mRenderMap.clear();
  for (size_t i{ 0 }; i < mMapSize.second; i++) {
    std::string renderLine{};
    for (size_t j{ 0 }; j < mMapSize.first; j++) {
      renderLine += getSymbol(mLocationMap[i * mMapSize.first + j]);
    }
    mRenderMap.push_back(renderLine);
  }
}

char Map::getSymbol(const Location& loc)
{
  char result{' '};
  if (loc.getObjectLayerId() == "none") {
    if (loc.getFloorLayerId() == "dirt") {
      result = ' ';
    }
  }
  else {
    if (loc.getObjectLayerId() == "wall") {
      result = '#';
    }
  }
  return result;
}

void Map::createMap(const std::string& filename)
{
  dr::IniDocument doc = dr::load(filename);
  dr::Section mapInfoSection = doc.getSection("map_info");
  mId = std::stoul(mapInfoSection.at("id"));
  dr::Section section = doc.getSection("map_size");
  mMapSize.first = std::stoul(section.at("width"));
  mMapSize.second = std::stoul(section.at("height"));
  
  for (size_t y = 0; y < mMapSize.second; y++) {
    for (size_t x = 0; x < mMapSize.first; x++) {
      dr::Section section = doc.getSection("loc_" + std::to_string(y) + "_" + std::to_string(x));
      Location loc;
      loc.setId(y * mMapSize.first + x);
      loc.setPosition({ static_cast<unsigned int>(x), static_cast<unsigned int>(y) });
      loc.setFloorLayerId(section.at("floor_layer"));
      loc.setObjectLayerId(section.at("objects_layer"));
      loc.setPassability(std::stoi(section.at("passable")));
      mLocationMap.push_back(std::move(loc));
    }
  }
}

GameData::LocationMap& Map::getMap()
{
  return mLocationMap;
}

GameData::RenderMap& Map::getRenderMap()
{
  return mRenderMap;
}

GameData::Size Map::getMapSize() const
{
  return mMapSize;
}

void Map::update()
{
  createRenderMap();
}

/**
 * @brief Create the vector of chars representing
 */
void Map::render()
{
  for (const auto& line : mRenderMap) {
    std::cout << line << '\n';
  }
}