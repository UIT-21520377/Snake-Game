void Snake::Rules() {
    system("cls");

    SetConsoleTextAttribute(hConsole, FOREGROUND_GREEN | FOREGROUND_INTENSITY);
    cout << "SIMPLE MODE:" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << " - The snake moves at a slow speed." << endl;
    cout << " - No obstacles in the arena." << endl;
    cout << " - Boundaries are non-lethal (teleports to the opposite side)." << endl;

    cout << endl;

    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_INTENSITY);
    cout << "HARD MODE:" << endl;
    SetConsoleTextAttribute(hConsole, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_INTENSITY);
    cout << " - The snake moves much faster." << endl;
    cout << " - Obstacles must be avoided." << endl;
    cout << " - Colliding with boundaries or obstacles ends the game." << endl;

    cout << endl;
}

