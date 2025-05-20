#include "menu_screen.h"
#include "explore_screen.h"
#include "create_player_screen.h"
#include "screen_manager.h"
#include "game_state.h"
#include <string>
#include <iostream>
#include <conio.h>

void MenuScreen::showMainMenu()
{
  std::cout << "\n\n";
  std::cout << "\t\tRpgDemoConsole ver 0.2.0\n\n";
  std::cout << "\t1. Play\n" << "\t2. Create a hero\n" << "\t3. Convert map\n" << "\t4. Exit\n\n";
  std::cout << "\t\tDeveloped by Vargar\n\t\t\t2025";
}

void MenuScreen::processUserInput(size_t option)
{
  switch (option) {
  case '1':
    startGame();
    break;
  case '2':
    createHero();
    break;
  case '3':
    convertMap();
    break;
  case '4':
    closeScreen();
    break;
  }
}

void MenuScreen::startGame()
{
  system("cls");
  mRenderScreen = true;
  ScreenManager::createScreen<ExploreScreen>("EXPLORE_SCREEN");
}

void MenuScreen::createHero()
{
  system("cls");
  mRenderScreen = true;
  ScreenManager::createScreen<CreatePlayerScreen>("CREATE_HERO_SCREEN");
}

void MenuScreen::closeScreen()
{
  GameState::destroyScreen();
}

/**
 * @brief Convert a map from txt file into the ini format
 */
void MenuScreen::convertMap()
{
  system("cls");
  std::string filename{};
  std::cout << "Enter filename: ";
  std::cin >> filename;
 
  mConverter.loadMap(filename);
  mConverter.saveMap();
  std::cout << "The map converted, type any key to continue\n";
  std::cin >> filename;
  system("cls");
  mRenderScreen = true;
}

void MenuScreen::init()
{
}

void MenuScreen::handleInput()
{
  if (!mRenderScreen) {
    if (_kbhit()) {
      int userOption = _getch();
      processUserInput(userOption);
    }
    mRenderScreen = true;
  }
}

void MenuScreen::update()
{
}

void MenuScreen::render()
{
  if (mRenderScreen) {
    showMainMenu();
    mRenderScreen = false;
  }
}