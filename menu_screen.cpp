#include "menu_screen.h"
#include "explore_screen.h"
#include "screen_manager.h"
#include "game_state.h"
#include <iostream>
#include <conio.h>

void MenuScreen::showMainMenu()
{
  std::cout << "\n\n";
  std::cout << "\t\tRpgDemoConsole ver 0.1.0\n\n";
  std::cout << "\t1. Play\n" << "\t2. Create a hero\n" << "\t3. Exit\n\n";
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
  //ScreenManager::createScreen(GameData::Screens::HERO_CREATION_SCREEN);
}

void MenuScreen::closeScreen()
{
  GameState::destroyScreen();
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