#include "engine.h"
#include "screen_manager.h"
#include "menu_screen.h"
#include <iostream>
#include <format>

void Engine::init()
{
  // setup console window
  HWND hWindowConsole = GetConsoleWindow();
  COORD bufferSize{ 1200, 800 };
  SetConsoleScreenBufferSize(hWindowConsole, bufferSize);
  MoveWindow(hWindowConsole, 400, 100, bufferSize.X, bufferSize.Y, TRUE);
  // get console handle
  mConsoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
  // hide console cursor
  CONSOLE_CURSOR_INFO cursorInfo;
  cursorInfo.dwSize = 1;
  cursorInfo.bVisible = false;
  SetConsoleCursorInfo(mConsoleHandle, &cursorInfo);
}

void Engine::input()
{
  if (!mGameState.isEmpty()) {
    mGameState.getCurrent()->handleInput();
  }
}

void Engine::update()
{
  if (!mGameState.isEmpty()) {
    mGameState.getCurrent()->update();
  }
}

void Engine::render()
{
  if (!mGameState.isEmpty()) {
    COORD cursorCoord;
    cursorCoord.X = 0;
    cursorCoord.Y = 0;
    SetConsoleCursorPosition(mConsoleHandle, cursorCoord);

    mGameState.getCurrent()->render();
  }
}

void Engine::run()
{
  init();
  ScreenManager::createScreen<MenuScreen>("MAIN_MENU");

  while (mRunning && !mGameState.isEmpty()) {
    input();
    update();
    render();
  }

  system("cls");
  std::cout << std::format("\t\tThe game is over\n");
}
