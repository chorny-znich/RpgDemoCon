#include "engine.h"
#include <iostream>

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
  std::cout << "input()\n";
}

void Engine::update()
{
  std::cout << "update()\n";
}

void Engine::render()
{
  COORD cursorCoord;
  cursorCoord.X = 0;
  cursorCoord.Y = 0;
  SetConsoleCursorPosition(mConsoleHandle, cursorCoord);

  std::cout << "render()\n";
}

void Engine::run()
{
  init();

  while (mRunning) {
    input();
    update();
    render();
  }
}
