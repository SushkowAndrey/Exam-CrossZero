#pragma once
#include <iostream>
#include <string>
#include "Players.h"

using namespace std;

//счетчик ходов и тип хода в консоли
inline void MoveCounter(int count, string motion)
{
    cout << "Ход " << motion << endl;
    cout << "Ход " << count << endl;
    cout << "____________" << endl;
}

//счетчик ходов и тип хода в консоли (перегружена)
inline void MoveCounter(int count, string motion, Players players)
{
    if (motion == "Крестика") {
        cout << "Ход " << motion << " - игрок " << players.GetPlayer1() << endl;
        cout << "Ход " << count << endl;
        cout << "____________" << endl;
    }
    else {
        cout << "Ход " << motion << " - игрок " << players.GetPlayer2() << endl;
        cout << "Ход " << count << endl;
        cout << "____________" << endl;
    }
}