#pragma once
#include <iostream>

using namespace std;

//игровое поле в консоли
void PlayingField(char board[SIZE][SIZE], int size) 
{
    for (int i = 0; i < size; i++) {  //верхняя граница координат
        if (i == 0) cout << "| |";
        cout << "|" << i << "|";
    }
    int x, y;
    cout << endl;
    for (int x = 0; x < 3; x++) {
        cout << "|" << x << "|";//левая граница координат
        for (int y = 0; y < 3; y++) {
            cout << "|" << board[x][y] << "|";//содержимое игрового поля
        }
        cout << endl;
    }
}