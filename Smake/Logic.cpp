#include "Header.h"
void Snake::Logic()
{
    for (int i = lenSnake - 1; i >= 1; i--) {
        bodyX[i] = bodyX[i - 1]; 
        bodyY[i] = bodyY[i - 1];
    }
    bodyX[0] = headX; bodyY[0] = headY; 

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

    if (headX == dollarX && headY == dollarY)
    {
        score += 10;
        if (score > highScore)
            highScore = score;
       
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
        lenSnake++;
    }
}