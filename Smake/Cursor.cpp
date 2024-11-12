#include "SnakeGame.h"

void SnakeGame::HideCursor()
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &info);
}

void SnakeGame::ShowCursor()
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 10;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &info);
}