#pragma once
#include <iostream>
#include <string>
#include "Players.h"

using namespace std;

//счетчик ходов и тип хода в консоли
inline void MoveCounter(int count, string motion)
{
    cout << "’од " << motion << endl;
    cout << "’од " << count << endl;
    cout << "____________" << endl;
}

//счетчик ходов и тип хода в консоли (перегружена)
inline void MoveCounter(int count, string motion, Players players)
{
    if (motion == " рестика") {
        cout << "’од " << motion << " - игрок " << players.GetPlayer1() << endl;
        cout << "’од " << count << endl;
        cout << "____________" << endl;
    }
    else {
        cout << "’од " << motion << " - игрок " << players.GetPlayer2() << endl;
        cout << "’од " << count << endl;
        cout << "____________" << endl;
    }
}