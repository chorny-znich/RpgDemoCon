#include "map.h"
#include "ini_parser.h"

Map::Map(size_t id) :
  mId{id}
{
}

void Map::createMap(const std::string& filename)
{
  dr::IniDocument doc = dr::load(filename);
  /*ini::Section mapInfoSection = doc.getSection("map_info");
  mId = std::stoul(mapInfoSection.at("id"));
  ini::Section section = doc.getSection("map_size");
  mMapSize.x = std::stoul(section.at("width"));
  mMapSize.y = std::stoul(section.at("height"));

  for (size_t y = 0; y < mMapSize.y; y++) {
    for (size_t x = 0; x < mMapSize.x; x++) {
      ini::Section section = doc.getSection("loc_" + std::to_string(y) + "_" + std::to_string(x));
      Location loc;
      loc.setId(y * mMapSize.x + x);
      loc.setPosition({ static_cast<unsigned int>(x), static_cast<unsigned int>(y) });
      loc.setFloorLayerId(section.at("floor_layer"));
      loc.setObjectLayerId(section.at("objects_layer"));
      loc.setPassability(std::stoi(section.at("passable")));
      mLocationMap.push_back(std::move(loc));
    }
  }*/
}

void Map::render()
{
}
