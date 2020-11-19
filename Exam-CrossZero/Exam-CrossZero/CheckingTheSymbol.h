#pragma once
#include <iostream>
#include <string>
#include "Players.h"
#include "GameLog.h"

using namespace std;

//проверка корректности пользовательского ввода
inline int CheckingTheSymbol(string enterSymbol)
{
    if (enterSymbol.size() != 1) return -1; //значения -1 в меню нет, поэтому для отработки цикла switch/case возвращаем дл¤ примера число -1
    else {
        int number = 0;
        number = enterSymbol[0];
        if (number > 47 && number < 58) return number - '0';
        else return -1;
    }
}