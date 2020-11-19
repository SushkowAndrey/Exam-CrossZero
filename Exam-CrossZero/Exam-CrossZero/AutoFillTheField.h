#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "CoordinateLastSave.h"
#include "Players.h"

using namespace std;

//ввод координат в игровое поле из вектора последней незаконченной игры с компьютером
int AutoFillTheField(char board[SIZE][SIZE], vector <CoordinateAutoLastSave> autolastSave)
{
    int count = 1;
    for (int i = 0; i < autolastSave.size(); i++)
    {
        if (i % 2 == 0) {
            board[stoi(autolastSave[i].x)][stoi(autolastSave[i].y)] = 'X';
        }
        else if (i % 2 != 0) {
            board[stoi(autolastSave[i].x)][stoi(autolastSave[i].y)] = 'O';
        }
        count++;
    }
    //возврат количества ходов прошлой игры
    return count;
}

//ввод координат в игровое поле из вектора последней незаконченной игры с игроком (перегружена)
int AutoFillTheField(char board[SIZE][SIZE], vector <CoordinateAutoLastSave> autolastSave, Players &players)
{
    int count = 0;
    for (int i = 0; i < autolastSave.size(); i++)
    {
        if (i == 0) {
            players.SetPlayer(autolastSave[i].x, autolastSave[i].y);
        }
        else if (i % 2 != 0) {
            board[stoi(autolastSave[i].x)][stoi(autolastSave[i].y)] = 'X';
        }
        else if (i % 2 == 0) {
            board[stoi(autolastSave[i].x)][stoi(autolastSave[i].y)] = 'O';
        }
        count++;
    }
    //возврат количества ходов прошлой игры
    return count;
}