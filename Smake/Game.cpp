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
        gameOver = true;
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
void Snake::Reset() {
    score = 0;
    headX = width / 2;
    headY = height / 2;
    lenSnake = 0;

    do {
        dollarX = rand() % width;
        dollarY = rand() % height;

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

void Snake::Run()
{
    while (true)
    {
        Start();
        while (!gameOver)
        {
            Draw();
            Keyboard();
            Logic();
            Sleep(isHardMode ? 25 : 100);
        }
        Draw(); 
        _getch();
    }
    ShowCursor();
}
