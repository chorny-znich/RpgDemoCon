#include "map_converter.h"
#include "game_data.h"
#include <fstream>
#include <iostream>
#include <format>

/**
 * @brief Load the map from the txt file
 */
void MapConverter::loadMap(const std::string& filename)
{
  std::ifstream ifs(std::format("{}{}.txt", GameData::path::Map, filename));
  if (ifs) {
    std::string line;
    while (std::getline(ifs, line)) {
      mMapToConvert.push_back(std::move(line));
    }
  }
  else {
    std::cerr << std::format("can't open file: {}\n\n", filename);
  }
  mId = std::stoul(filename.substr(filename.find("_") + 1));
  mMapSize = {static_cast<unsigned int>(mMapToConvert[0].size()),
    static_cast<unsigned int>(mMapToConvert.size()) };
}

void MapConverter::saveMap()
{
  std::ofstream ofs(std::format("{}map_{}.ini", GameData::path::Map, mId));
  if (ofs) {
    ofs << "[map_info]\n";
    ofs << "id=" << mId << "\n";
    ofs << "[map_size]\n";
    ofs << "width=" << mMapSize.first << "\n";
    ofs << "height=" << mMapSize.second << "\n";
    for (size_t i{0}; i < mMapSize.second; i++) {
      for (size_t j{ 0 }; j < mMapSize.first; j++) {
        ofs << std::format("[loc_{}_{}]\n", i, j);
        if (mMapToConvert[i][j] == ' ') {
          ofs << "floor_layer=dirt\n";
          ofs << "objects_layer=none\n";
          ofs << "passable=1\n";
        }
        else if (mMapToConvert[i][j] == '#') {
          ofs << "floor_layer=dirt\n";
          ofs << "objects_layer=wall\n";
          ofs << "passable=0\n";
        }
        else if (mMapToConvert[i][j] == '/') {
          ofs << "floor_layer=dirt\n";
          ofs << "objects_layer=none\n";
          ofs << "passable=1\n";
        }
      }
    }
  }
  else {
    std::cout << "\nCan't create a file with player's information\n";
  }
}
