#pragma once
#include <string>
#include <array>

/**
 * @brief Parts of the user interface
 */
enum class UI_Part {
  PLAYER_INFO,
  LOCATION_INFO,
  GAME_LOG
};

/**
 * @brief Component of the user interface
 */
class ConsoleUI
{
private:
  std::array<std::string, 3> mPlayerInfo;

public:
  void showDivider(char ch, size_t width);
  void addToHud(UI_Part part, std::string str, size_t line);
  void display(UI_Part type);
};

