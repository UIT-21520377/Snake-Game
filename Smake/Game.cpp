#include <conio.h>
#include <windows.h>
#include "iostream"
#include "stdio.h"
#include "Header.h"
// Hàm Start: Xử lý logic bắt đầu trò chơi.
void Snake::Start() {
    MainScreen();                // Hiển thị màn hình chính (menu chọn chế độ).
    char startKey = _getch();    // Đợi người dùng nhấn phím.
    if (startKey == '1') {       // Nếu người dùng chọn chế độ "Simple Mode".
        isHardMode = false;      // Đặt chế độ đơn giản (không có chướng ngại vật, tốc độ chậm).
        gameOver = false;        // Trò chơi chưa kết thúc.
        Reset();                 // Thiết lập lại trạng thái ban đầu của trò chơi.
    }
    else if (startKey == '2') {  // Nếu người dùng chọn chế độ "Hard Mode".
        isHardMode = true;       // Đặt chế độ khó (có chướng ngại vật, tốc độ nhanh).
        GenerateBlocks();        // Sinh các chướng ngại vật.
        gameOver = false;        // Trò chơi chưa kết thúc.
        Reset();                 // Thiết lập lại trạng thái ban đầu của trò chơi.
    }
    else {                       // Nếu người dùng nhấn phím khác.
        gameOver = true;         // Kết thúc trò chơi ngay lập tức.
    }
}


/*
* void SnakeGame::ResetGame()
{
    score = 0;
    x = width / 2;
    y = height / 2;
    nTail = 0;
    fruitX = rand() % width;
    fruitY = rand() % height;
}
*/
// Hàm Reset: Đặt lại các thông số của trò chơi về trạng thái ban đầu.
void Snake::Reset() {
    score = 0;                    // Đặt điểm số về 0.
    headX = width / 2;            // Đặt vị trí đầu rắn vào giữa màn hình (theo chiều ngang).
    headY = height / 2;           // Đặt vị trí đầu rắn vào giữa màn hình (theo chiều dọc).
    lenSnake = 0;                 // Đặt chiều dài ban đầu của rắn về 0.

    do {
        dollarX = rand() % width;   // Sinh vị trí ngẫu nhiên cho "đồng tiền" theo chiều ngang.
        dollarY = rand() % height;  // Sinh vị trí ngẫu nhiên cho "đồng tiền" theo chiều dọc.

        // Ensure fruit doesn't overlap with any block
        bool overlap = false;
        for (int i = 0; i < numBlocks; i++) {
            if (dollarX == blockX[i] && dollarY == blockY[i]) {
                overlap = true;
                break;
            }
        }
        if (!overlap) break;

    } while (true);
}
// Hàm Run: Vòng lặp chính của trò chơi.
void Snake::Run()
{
    while (true)               // Vòng lặp chính (trò chơi chạy liên tục cho đến khi người dùng thoát).
    {
        Start();               // Bắt đầu trò chơi (hiển thị menu và chọn chế độ).
        while (!gameOver)      // Chạy trò chơi khi chưa kết thúc.
        {
            Draw();            // Vẽ giao diện trò chơi.
            Keyboard();        // Xử lý thao tác phím bấm của người dùng.
            Logic();           // Cập nhật logic trò chơi (di chuyển rắn, kiểm tra va chạm,...).
            Sleep(isHardMode ? 25 : 100);        // Điều chỉnh tốc độ dựa trên chế độ (nhanh hoặc chậm).
        }
        Draw();                 // Hiển thị khung cuối cùng khi trò chơi kết thúc.
        _getch();               // Đợi người dùng nhấn phím trước khi tiếp tục.
    }
    ShowCursor();               // Hiển thị lại con trỏ chuột (nếu trước đó đã ẩn).
}
