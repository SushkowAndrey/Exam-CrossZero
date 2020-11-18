#pragma once
#include <iostream>

using namespace std;

//проверка сплошной черты для определения победителя
bool CheckingTheSolidСourse(char board[SIZE][SIZE], char sign)
{
    if ((board[0][0] == sign && board[0][1] == sign && board[0][2] == sign)
        || (board[1][0] == sign && board[1][1] == sign && board[1][2] == sign)
        || (board[2][0] == sign && board[2][1] == sign && board[2][2] == sign)
        || (board[0][0] == sign && board[1][0] == sign && board[2][0] == sign)
        || (board[0][1] == sign && board[1][1] == sign && board[2][1] == sign)
        || (board[0][2] == sign && board[1][2] == sign && board[2][2] == sign)
        || (board[0][0] == sign && board[1][1] == sign && board[2][2] == sign)
        || (board[0][2] == sign && board[1][1] == sign && board[2][0] == sign))
        return true;
    else return false;
}