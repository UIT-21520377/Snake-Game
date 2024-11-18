#include "Header.h"

void Snake::HideCursor()
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 100;
    info.bVisible = FALSE;
    SetConsoleCursorInfo(hConsole, &info);
}

void Snake::ShowCursor()
{
    CONSOLE_CURSOR_INFO info;
    info.dwSize = 10;
    info.bVisible = TRUE;
    SetConsoleCursorInfo(hConsole, &info);
}