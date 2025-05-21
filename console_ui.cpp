#include "console_ui.h"
#include <iostream>

/**
 * @brief Line to divide parts of the user interface's elements
 * @param ch 
 * @param width 
 */
void ConsoleUI::showDivider(char ch, size_t width)
{
  std::cout << std::string(width, ch) << "\n";
}

/**
 * @brief Add a text to the appropriate container
 * @param part - an elemement of the UI_Part
 * @param str - a string to display
 * @param line - a line of the string's container (between 1 and 3)
 */
void ConsoleUI::addToHud(UI_Part part, std::string str, size_t line)
{
  switch (part) {
  case UI_Part::PLAYER_INFO:
    mPlayerInfo.at(line) = std::move(str);
    break;
  case UI_Part::LOCATION_INFO:
    //mLocationInfo.at(line) = std::move(str);
    break;
  case UI_Part::GAME_LOG:
    //mGameLog.at(line) = std::move(str);
    break;
  }
}

/**
 * @brief Display a part of the UI
 * @param type - an elemement of the UI_Part
 */
void ConsoleUI::display(UI_Part type)
{
  std::array<std::string, 3> arrayToPrint;
  switch (type) {
  case UI_Part::PLAYER_INFO:
    arrayToPrint = mPlayerInfo;
    break;
  case UI_Part::LOCATION_INFO:
    //arrayToPrint = mLocationInfo;
    break;
  case UI_Part::GAME_LOG:
    //arrayToPrint = mGameLog;
    break;
  }

  showDivider('=', 25);
  for (const auto& str : arrayToPrint) {
    std::cout << str << '\n';
  }
  showDivider('=', 25);
}
