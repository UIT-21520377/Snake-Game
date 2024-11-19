#include <windows.h>

class Snake
{
private:
    bool isHardMode;// biến dùng để xác định mức độ trò chơi 
    const int numBlocks = 10; //Số lượng chướng ngại vật (blocks) trong chế độ khó.
    int blockX[10], blockY[10]; //Mảng chứa tọa độ X và Y của các chướng ngại vật.
    int headX, headY;  // Tọa độ hiện tại của đầu con rắn.
    int bodyX[100], bodyY[100];//Mảng lưu tọa độ các phần cơ thể rắn (thân rắn).
    int lenSnake; //Độ dài của rắn (số phần thân hiện tại).
    int dollarX, dollarY; //Tọa độ của đồ ăn ($) trên màn hình.
    int score, highScore; // điểm hiện tại người chơi , điểm cao nhất người chơi đạt được 
    enum eDirection { STOP = 0, LEFT, RIGHT, UP, DOWN }; //Liệt kê hướng di chuyển của rắn:
    eDirection dir;
    HANDLE hConsole;
    bool gameOver;
    const int width = 60; // chiều rông màn hình 
    const int height = 25; // chiều dài màn hình

public:
    Snake();
    void HideCursor();//Ẩn con trỏ chuột trong giao diện console để trò chơi không bị gián đoạn bởi con trỏ nhấp nháy.
    void ShowCursor();// Hiện lại con trỏ chuột trong giao diện console.
    void Rules();// Hiển thị luật chơi cho cả chế độ "Simple Mode" và "Hard Mode".
    void MainScreen(); //Hiển thị giao diện chính của trò chơi (menu).
    void Draw(); //Vẽ toàn bộ giao diện trò chơi trong console.
    void Keyboard(); // Xử lý các phím bấm từ người chơi.
    void Logic(); // Xử lý logic chính của trò chơi.
    void Start();// Khởi tạo và bắt đầu trò chơi.
    void Run(); // Vòng lặp chính của trò chơi.
    void Reset();// Đặt lại trò chơi về trạng thái ban đầu.
    void GenerateBlocks(); // Sinh ngẫu nhiên vị trí của các chướng ngại vật trên màn hình trong chế độ Hard Mode.
};
