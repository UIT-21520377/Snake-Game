#include <conio.h>
#include "Header.h"


void Snake::Keyboard()
{
    // Kiểm tra nếu có phím được nhấn.
    if (_kbhit()) {
        switch (_getch()) {
        case 'a': // Left arrow key
            if (dir != RIGHT)
                dir = LEFT;
            break;
        case 'd': // Right arrow key
            if (dir != LEFT)
                dir = RIGHT;
            break;
        case 'w': // Up arrow key
            if (dir != DOWN)
                dir = UP;
            break;
        case 's': // Down arrow key
            if (dir != UP)
                dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}
