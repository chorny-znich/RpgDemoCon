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
  std::cout << std::format("Number of points to distribute is {}\n\n", mStatsPoints);
  std::cout << "Primary stats:\n";
  showPrimaryStats();
  std::cout << mPlayer.showSecondaryStats();
  std::cout << mPlayer.showSkills();
  std::cout << "\nNavigate between stats with 'w' and 's' keys.\nPress 'a' to decrease stat's value and 'd' to increase it.\n";
  std::cout << "Press 'Space' when you distribute all stats points.\n";
}

void CreatePlayerScreen::showPrimaryStats()
{
  for (size_t i = 0; i < PrimaryStatsList.size(); i++) {
    std::string result{};
    if (mMenuIndex == i) {
      result = "* " + PrimaryStatsList[i] + " - " + std::to_string(mPlayer.getPrimaryStatValue(PrimaryStatsList[i]));
    }
    else {
      result = "  " + PrimaryStatsList[i] + " - " + std::to_string(mPlayer.getPrimaryStatValue(PrimaryStatsList[i]));
    }
    std::cout << result << "\n";
  }
  std::cout << "\n\n";
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
    ofs << "Money=" << mPlayer.getMoney() << "\n\n";
    ofs << "[Primary stats]\n";
    for (const auto& stat : PrimaryStatsList) {
      ofs << stat << "=" << mPlayer.getPrimaryStatValue(stat) << "\n";
    }
    ofs << "\n[Secondary stats]\n";
    for (const auto& stat : SecondaryStatsList) {
      ofs << stat << "=" << mPlayer.getSecondaryStatValue(stat) << "\n";
    }
    ofs << "\n[Skills]\n";
    for (const auto& skill : SkillsList) {
      ofs << skill << "=" << mPlayer.getSkillValue(skill) << "\n";
    }
  }
  else {
    std::cout << "\nCan't create a file with player's information\n";
  }
}

void CreatePlayerScreen::calcStats()
{
  mPlayer.updateAttention();
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
    case 'w':
      if (mMenuIndex > 0) {
        mMenuIndex--;
      }
      break;
    case 's':
      if (mMenuIndex < PrimaryStatsList.size() - 1) {
        mMenuIndex++;
      }
      break;
    case 'd':
      if (mStatsPoints > 0 && mPlayer.getPrimaryStatValue(PrimaryStatsList[mMenuIndex]) < 10) {
        mPlayer.increasePrimaryStat(PrimaryStatsList[mMenuIndex]);
        mStatsPoints--;
        calcStats();
      }
      break;
    case 'a':
      if (mStatsPoints < START_STATS_POINTS && mPlayer.getPrimaryStatValue(PrimaryStatsList[mMenuIndex]) > 1) {
        mPlayer.decreasePrimaryStat(PrimaryStatsList[mMenuIndex]);
        mStatsPoints++;
        calcStats();
      }
      break;
    case 32:
      createPlayer();
      std::cout << "\nYou create a hero. Now you can start a new game.\n";
      system("cls");
      GameState::destroyScreen();
    }
    mRenderScreen = true;
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