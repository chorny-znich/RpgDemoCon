#include "menu_screen.h"
#include <iostream>
#include <conio.h>

void MenuScreen::showMainMenu()
{
  std::cout << "\n\n";
  std::cout << "\t\tRpgDemoConsole ver 0.1.0\n\n";
  std::cout << "\t1. Play\n" << "\t2. Create a hero\n" << "\t3. Exit\n\n";
  std::cout << "\t\tDeveloped by Vargar\n\t\t\t2025";
}

void MenuScreen::init()
{
}

void MenuScreen::inputHandler()
{
  if (!mRenderScreen) {
    size_t menuItem{ 0 };
    if (_kbhit()) {
      int menuItem = _getch();
      switch (menuItem) {
      case '1':
        system("cls");
        mRenderScreen = true;
        //ScreenManager::createScreen(GameData::Screens::EXPLORE_SCREEN);
        break;
      case '2':
        system("cls");
        mRenderScreen = true;
        //ScreenManager::createScreen(GameData::Screens::HERO_CREATION_SCREEN);
        break;
      case '3':
        exit(0);
        break;
      }
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