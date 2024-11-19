#include <conio.h>
#include "Header.h"


void Snake::Keyboard()
{
    // Kiểm tra nếu có phím được nhấn.
    if (_kbhit()) {
        // Đọc ký tự từ bàn phím mà không cần chờ (blocking).
        switch (_getch()) {
        case 'a': // Nhấn phím 'a' để di chuyển sang trái.
            if (dir != RIGHT)
                dir = LEFT;    // Đảm bảo không thể quay ngược 180 độ.
            break;
        case 'd': // Nhấn phím 'd' để di chuyển sang phải
            if (dir != LEFT)
                dir = RIGHT;    // Không cho phép quay ngược.
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
