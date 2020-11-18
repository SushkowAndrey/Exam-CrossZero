#pragma once
#include <iostream>

using namespace std;

//ввод координат компьютером
void TheProgressOfTheZero(char board[SIZE][SIZE], int &x, int &y, int &count) {
    do {
        do {
            x = rand() % 3;
        } while (x < 0 || x > 2);
        do {
            y = rand() % 3;
        } while (y < 0 || y > 2);
    } while (board[x][y] == 'X' || board[x][y] == 'O');
    board[x][y] = 'O';
    //count++;
}