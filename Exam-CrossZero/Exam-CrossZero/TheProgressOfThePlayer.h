#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CheckingTheSymbol.h"
#include "CoordinateLastSave.h"

using namespace std;

const int SIZE = 3;

//ввод координат игроком
void TheProgressOfThePlayer(char board[SIZE][SIZE], char sign, int & xToNum, int &yToNum, int &count) {
    string x, y;
    do {
        do {
            cout << "Укажите первую координату (строка) "; cin >> x;
            xToNum = CheckingTheSymbol(x);
        } while (xToNum < 0 || xToNum > 2);
        do {
            cout << "Укажите вторую координату (столбец) "; cin >> y;
            yToNum = CheckingTheSymbol(y);
        } while (yToNum < 0 || yToNum > 2);
    } while (board[xToNum][yToNum] == 'X' || board[xToNum][yToNum] == 'O');
    board[xToNum][yToNum] = sign;
}