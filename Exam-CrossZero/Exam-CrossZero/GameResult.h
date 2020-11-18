#pragma once
#include <iostream>
#include <string>
#include "Players.h"

using namespace std;

//определение победителя игрок-компьютер
inline void GameResult(int count)
{
    if (count == 1) {
        cout << "Выиграл Игрок!" << endl;
    }
    else if (count == 2) {
        cout << "Выиграл Компьютер!" << endl;
    }
    else if (count == 9) {
        cout << "Ничья" << endl;
    }
}

//определение победителя игрок-игрок (перегружена)
inline void GameResult(int count, Players players)
{
    if (count == 1) {
        cout << "Выиграл Игрок " << players.GetPlayer1() << endl;
    }
    else if (count == 2) {
        cout << "Выиграл Игрок " << players.GetPlayer2() << endl;
    }
    else if (count == 9) {
        cout << "Ничья" << endl;
    }
}


///////////////////////////

//определение победителя игрок-игрок (перегружена)
inline void GameResult(bool winX, bool winO, int count, Players players)
{
    if (winX) {
        cout << "Выиграл Игрок " << players.GetPlayer1() << endl;
    }
    else if (winO) {
        cout << "Выиграл Игрок " << players.GetPlayer2() << endl;
    }
    else if (count == 9) {
        cout << "Ничья" << endl;
    }
}