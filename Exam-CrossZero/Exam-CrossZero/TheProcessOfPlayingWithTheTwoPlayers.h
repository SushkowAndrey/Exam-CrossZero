#pragma once

#include <iostream>
#include <vector>
#include "Interface.h"
#include "TheProgressOfThePlayer.h"
#include "TheProgressOfTheZero.h"
#include "PlayingField.h"
#include "GameLog.h"
#include "ExportSave.h"
#include "ImportLastSave.h"
#include "AutoFillTheField.h"
#include "CheckingTheSolidСourse.h"
#include "ToClearTheAutoContents.h"
#include "MoveCounter.h"

using namespace std;

//игра с напарником
int TheProcessOfPlayingWithTheTwoPlayers(char board[SIZE][SIZE], vector <GameLog> gameLog, vector <CoordinateAutoLastSave> сoordinateAutoLastSave, Players players, int count)
{
    //переменные определения победы
    bool winX = false, winO = false;
    //переменные координат, для возврата из функции в журнал записи, передаются по ссылке функцию
    int CoordinateX1 = 0, CoordinateY1 = 0, CoordinateX2 = 0, CoordinateY2 = 0;
    Interface::PrintGame();
    //автосохранение имен
    сoordinateAutoLastSave.push_back(InputCoordinate(players.GetPlayer1(), players.GetPlayer2()));
    ExportToLogAutoSave(сoordinateAutoLastSave, сoordinateAutoLastSave.size(),"Игроки");
    PlayingField(board, SIZE);
    do {
        MoveCounter(count, "Крестика", players);
        TheProgressOfThePlayer(board, 'X', CoordinateX1, CoordinateY1, count);
        system("cls");
        Interface::PrintGame();
        PlayingField(board, SIZE);
        //сохранение журнала игры
        gameLog.push_back(InputGameLog(count, players.GetPlayer1(), CoordinateX1, CoordinateY1, "Следующий_ход"));
        ExportToLog(gameLog, gameLog.size(), "Игроки");
        count++;
        if (CheckingTheSolidСourse(board, 'X'))
        {
            winX = true;
            gameLog.push_back(InputGameLog(count, players.GetPlayer1(), CoordinateX1, CoordinateY1, "Победа_игрока " + players.GetPlayer1()));
            ExportToLog(gameLog, gameLog.size(), "Игроки");
            break;
        }
        else if (count > 9) {
            gameLog.push_back(InputGameLog("Ничья"));
            ExportToLog(gameLog, gameLog.size(), "Игроки");
            break;
        }
        //автосохранение
        сoordinateAutoLastSave.push_back(InputCoordinate(to_string(CoordinateX1), to_string(CoordinateY1)));
        ExportToLogAutoSave(сoordinateAutoLastSave, сoordinateAutoLastSave.size(), "Игроки");
        MoveCounter(count, "Нолика", players);
        TheProgressOfThePlayer(board, 'O', CoordinateX2, CoordinateY2, count);
        system("cls");
        Interface::PrintGame();
        PlayingField(board, SIZE);
        gameLog.push_back(InputGameLog(count, players.GetPlayer2(), CoordinateX2, CoordinateY2, "Следующий_ход"));
        ExportToLog(gameLog, gameLog.size(), "Игроки");
        count++;
        if (CheckingTheSolidСourse(board, 'O'))
        {
            winO = true;
            gameLog.push_back(InputGameLog(count, players.GetPlayer2(), CoordinateX1, CoordinateY1, "Победа_игрока " + players.GetPlayer2()));
            ExportToLog(gameLog, gameLog.size(), "Игроки");
            break;
        }
        else if (count > 9) {
            gameLog.push_back(InputGameLog("Ничья"));
            ExportToLog(gameLog, gameLog.size(), "Игроки");
            break;
        }
        //автосохранение
        сoordinateAutoLastSave.push_back(InputCoordinate(to_string(CoordinateX2), to_string(CoordinateY2)));
        ExportToLogAutoSave(сoordinateAutoLastSave, сoordinateAutoLastSave.size(), "Игроки");
    } while (!winX || !winO || count > 9);
    if (winX) {
        return 1;
    }
    else if (winO) {
        return 2;
    }
    else if (count > 9) {
        return 9;
    }
}