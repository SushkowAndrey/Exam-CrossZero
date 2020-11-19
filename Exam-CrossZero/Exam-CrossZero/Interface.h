#pragma once
#include <iostream>
#include <string>

using namespace std;

class Interface
{
public:
    static void PrintWelcome()
    {
        cout << "=================================" << endl;
        cout << "===== Игра крестики-нолики ======" << endl;
        cout << "=================================" << endl;
        cout << endl;
    }
    static void PrintMenu()
    {
        cout << "+++++++++++++++++++++++++++++++++" << endl;
        cout << "++++++++++++++Меню+++++++++++++++" << endl;
        cout << "1. Начать игру с компьютером" << endl;
        cout << "2. Начать игру с игроком" << endl;
        cout << "3. Посмотреть прошлый журнал игры с компьютером" << endl;
        cout << "4. Посмотреть прошлый журнал игры со вторым игроком" << endl;
        cout << "5. Начать игру c компьютером с последнего хода" << endl;
        cout << "6. Начать игру c игроком с последнего хода" << endl;
        cout << "7. Посмотреть условия игры" << endl;
        cout << "8. Очистить журналы прошлых игр" << endl;
        cout << "0. Выход" << endl;
        cout << "+++++++++++++++++++++++++++++++++" << endl;
        cout << "+++++++++++++++++++++++++++++++++" << endl;
    }
    static void PrintGame()
    {
        cout << "Процесс игры" << endl;
        cout << "____________" << endl;
    }
    static void PrintСonditionOfGame()
    {
        cout << "Игру начинает Пользователь" << endl;
        cout << "Пользователь ходит крестиком" << endl;
        cout << "Компьютер ходит ноликом" << endl;
    }
    static void PrintError(string message1, string message2)
    {
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << "!!!!!!!!!! "<< message1 <<" !!!!!!!!!!" << endl;
        cout << "!!! " << message2 << " !!!" << endl;
        cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
        cout << endl;
    }
    static void PrintClear()
    {
        cout << endl;
        cout << "---------------------------------" << endl;
        cout << "-------- Журналы очищены --------" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
    }
    static void PrintExit()
    {
        cout << endl;
        cout << "---------------------------------" << endl;
        cout << "----------- Good byе! -----------" << endl;
        cout << "---------------------------------" << endl;
        cout << endl;
    }
};