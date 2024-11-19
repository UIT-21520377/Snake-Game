void Snake::Run() {
    MainScreen();
    char choice = _getch();

    isHardMode = choice == '2';

    while (!gameOver) {
        Draw();
        Keyboard();
        Logic();
        Sleep(isHardMode ? 50 : 100);
    }

    cout << "Game Over! Score: " << score << endl;
}
