// Игра "Крестики-Нолики". Предусмотреть возможность журналирования ходов и возможности сохранения состояния игры.

#include <iostream>
#include <ctime>
#include <vector>
#include "Interface.h"
#include "CheckingTheSymbol.h"
#include "TheProcessOfPlayingWithTheComputer.h"
#include "TheProcessOfPlayingWithTheTwoPlayers.h"
#include "GameLog.h"
#include "CoordinateLastSave.h"
#include "GameResult.h"
#include "AutoFillTheField.h"

using namespace std;

int main()
{
    setlocale(0, "ru");
    srand(time(0));

    //журнал записи игры c компьютером и игроком
    vector <GameLog> gameLogWithTheComputer;
    vector <GameLog> gameLogWithWithTheTwoPlayers;
    //журнал автосохранения при игре с компьютером
    vector <CoordinateAutoLastSave> сoordinateAutoLastSave;
    //вектор с последними сохраненными данными
    vector <CoordinateAutoLastSave> autolastSave;
    //журнал автосохранения при игре со вторым игроком
    vector <CoordinateAutoLastSave> сoordinateAutoLastSaveTwoPlayers;
    //вектор с последними сохраненными данными
    vector <CoordinateAutoLastSave> autolastSaveTwoPlayers;
    //игроки
    Players players;

    Interface::PrintWelcome();
    string symbol;
    int number;
    do {
        //размер и массив для игрового поля
        const int SIZE = 3;
        char board[SIZE][SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
        //счетчик хода
        int count = 1;
        Interface::PrintMenu();
        cout << "Введите пункт меню - ";
        cin >> symbol;
        number = CheckingTheSymbol(symbol);
        system("cls");
        switch (number)
        {
        case 1://начать игру с компьютером
            GameResult(TheProcessOfPlayingWithTheComputer(board, gameLogWithTheComputer, сoordinateAutoLastSave, count));
            break;
        case 2://игра с напарником
        {
            players = ConsoleInputPlayers();
            GameResult(TheProcessOfPlayingWithTheTwoPlayers(board, gameLogWithWithTheTwoPlayers, сoordinateAutoLastSaveTwoPlayers, players, count), players);
        }
            break;
        case 3: //журнал игры с компьютером
            gameLogWithTheComputer = ImportLog("GameLogComputer.csv");
            OutputLog(gameLogWithTheComputer);
            break;
        case 4://журнал игры со вторым игроком
            gameLogWithWithTheTwoPlayers = ImportLog("GameLogTwoPlayer.csv");
            OutputLog(gameLogWithWithTheTwoPlayers);
            break;
        case 5: //начать с последней незаконченной игры с компьютером
            autolastSave = ImportLastSave("AutoSaveGame.csv");
            //проверка наличия последних сохранения
            autolastSave.size() == 0 ? Interface::PrintError("Внимание", "Прошлая игра завершена"):
                GameResult(TheProcessOfPlayingWithTheComputer(board, gameLogWithTheComputer, сoordinateAutoLastSave, AutoFillTheField(board, autolastSave)));
            break;
        case 6://начать с последней незаконченной игры с игроком
        {
            autolastSaveTwoPlayers = ImportLastSave("AutoSaveGamePlayers.csv");
            //проверка наличия последних сохранения
            autolastSaveTwoPlayers.size() == 0 ? Interface::PrintError("Внимание", "Прошлая игра завершена") :
                GameResult(TheProcessOfPlayingWithTheTwoPlayers(board, gameLogWithTheComputer, сoordinateAutoLastSave, players, 
                    AutoFillTheField(board, autolastSaveTwoPlayers, players)), players);
        }
            break;
        case 7:
            Interface::PrintСonditionOfGame();
            break;
        case 8://очистить журналы
            ToClearTheAutoContents("GameLogComputer.csv");
            ToClearTheAutoContents("GameLogTwoPlayer.csv");
            Interface::PrintClear();
            break;
        case 0:
            Interface::PrintExit();
            break;
        default:
            Interface::PrintError("ERROR", "Некорректный выбор меню");
            break;
        }
    } while (number != 0);
    system("pause");
}