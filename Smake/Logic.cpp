#include "Header.h"
void SnakeGame::Logic()
{
    int prevX = bodyX[0];
    int prevY = bodyY[0];
    int prev2X, prev2Y;
    bodyX[0] = headX;
    bodyY[0] = headY;

    for (int i = 1; i < lenSnake; i++)
    {
        prev2X = bodyX[i];
        prev2Y = bodyY[i];
        bodyX[i] = prevX;
        bodyY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }

    switch (dir)
    {
    case LEFT:
        headX--;
        break;
    case RIGHT:
        headX++;
        break;
    case UP:
        headY--;
        break;
    case DOWN:
        headY++;
        break;
    default:
        break;
    }

    if (headX >= width) headX = 0; else if (headX < 0) headX = width - 1;
    if (headY >= height) headY = 0; else if (headY < 0) headY = height - 1;

    for (int i = 0; i < lenSnake; i++)
        if (bodyX[i] == headX && bodyY[i] == headY)
            gameOver = true;

    if (isHardMode) {
        for (int i = 0; i < numBlocks; i++) {
            if (headX == blockX[i] && headY == blockY[i]) {
                gameOver = true;
            }
        }
    }

    if (isHardMode && (headX == 0 || headX == width - 1 || headY == 0 || headY == height - 1))
        gameOver = true;

    if (headX == fruitX && headY == fruitY)
    {
        score += 10;
        if (score > highScore)
            highScore = score;
       
        do {
            fruitX = rand() % width;
            fruitY = rand() % height;

            // Ensure fruit doesn't overlap with any block
            bool overlap = false;
            for (int i = 0; i < numBlocks; i++) {
                if (fruitX == blockX[i] && fruitY == blockY[i]) {
                    overlap = true;
                    break;
                }
            }
            if (!overlap) break;

        } while (true);
        lenSnake++;
    }
}