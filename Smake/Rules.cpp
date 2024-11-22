#include "SnakeGame.h"
void Snake::Rules() {
    //system("cls");

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "SIMPLE MODE:" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << " - The snake moves at a slow speed.- con rắn di chuyển với tốc độ chậm " << endl;
    cout << " - No obstacles in the arena. -Không có chướng ngại vật trên đấu trường " << endl;
    cout << " - Boundaries are non-lethal (teleports to the opposite side) - không có vật cản trên trường đấu tranh" << endl;

    cout << endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "HARD MODE:" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << " - The snake moves much faster. -Con rắn di chuyển nhanh hơn nhiều " << endl;
    cout << " - Obstacles must be avoided.-Những trở ngại phải được tránh." << endl;
    cout << " - Colliding with boundaries or obstacles ends the game.-Va chạm với ranh giới hoặc chướng ngại vật kết thúc trò chơi " << endl;

    cout << endl;
}

