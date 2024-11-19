#include "Header.h"

void Snake::HideCursor()
{
    CONSOLE_CURSOR_INFO info; // Tạo cấu trúc lưu thông tin về con trỏ chuột.
    info.dwSize = 100;  // Đặt kích thước con trỏ chuột (chỉ có ý nghĩa khi hiển thị).
    info.bVisible = FALSE; // Thiết lập trạng thái ẩn con trỏ chuột.
    SetConsoleCursorInfo(hConsole, &info); // Áp dụng thiết lập con trỏ cho console hiện tại.
}

void Snake::ShowCursor()
{
    CONSOLE_CURSOR_INFO info; // Tạo cấu trúc lưu thông tin về con trỏ chuột.
    info.dwSize = 10; // Đặt kích thước con trỏ chuột nhỏ hơn (chỉ để hiển thị gọn).
    info.bVisible = TRUE; // Thiết lập trạng thái hiển thị con trỏ chuột.
    SetConsoleCursorInfo(hConsole, &info); // Áp dụng thiết lập con trỏ cho console hiện tại.
}
