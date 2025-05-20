#include "create_player_screen.h"
#include "game_state.h"
#include <format>
#include <iostream>
#include <fstream>
#include <conio.h>

void CreatePlayerScreen::setPlayerName()
{
  std::string name;
  std::cout << "What's your character's name? ";
  std::cin >> name;
  mPlayer.setName(std::move(name));
}

void CreatePlayerScreen::showScreen()
{
  std::cout << "Create your hero. Choose your name and distribute points for attributes.\n\n";
  std::cout << std::format("Name: {}\n", mPlayer.getName());
  //std::cout << std::format("Number of points to distribute is {}\n\n", mStatsPoints);
  //std::cout << "Primary stats:\n";
  //showPrimaryStats();
  //mPlayer.showSecondaryStats();
  //mPlayer.showSkills();
  //std::cout << "\nNavigate between stats with 'w' and 's' keys.\nPress 'a' to decrease stat's value and 'd' to increase it.\n";
  std::cout << "Press 'Space' when you distribute all stats points.\n";
}

/**
 * @brief Save the information about the player in the file
 */
void CreatePlayerScreen::createPlayer()
{
  std::ofstream ofs(GameData::PlayerInfo);
  if (ofs) {
    ofs << "[Player]\n";
    ofs << "Name=" << mPlayer.getName() << "\n";
  }
  else {
    std::cout << "\nCan't create a file with player's information\n";
  }
}

void CreatePlayerScreen::init()
{
  setPlayerName();
}

void CreatePlayerScreen::handleInput()
{
  if (_kbhit()) {
    char action = _getch();
    switch (action) {
    case 32:
      createPlayer();
      std::cout << "\nYou create a hero. Now you can start a new game.\n";
      system("cls");
      GameState::destroyScreen();
    }
  }
}

void CreatePlayerScreen::update()
{
}

void CreatePlayerScreen::render()
{
  if (mRenderScreen) {
    system("cls");
    showScreen();
    mRenderScreen = false;
  }
}