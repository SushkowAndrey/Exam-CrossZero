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

//процесс игры игрока и компьютера
int TheProcessOfPlayingWithTheComputer (char board[SIZE][SIZE], vector <GameLog> gameLog, vector <CoordinateAutoLastSave> сoordinateAutoLastSave, int count)
{
    Interface::PrintGame();
    PlayingField(board, SIZE);
    //переменные определения победы
    bool winX = false, winO = false;
    //очистка последнего автосохранения
    ToClearTheAutoContents("AutoSaveGame.csv");
    do {
        //переменные координат игрока и компьютера, для возврата из функции в журнал записи, передаются по ссылке функцию
        int CoordinateX1 = 0, CoordinateY1 = 0, CoordinateX2 = 0, CoordinateY2 = 0;
        //ход крестика-игрок
        MoveCounter(count, "Крестика");
        TheProgressOfThePlayer(board, 'X', CoordinateX1, CoordinateY1, count);
        system("cls");
        Interface::PrintGame();
        PlayingField(board, SIZE);
        //сохранение журнала игры
        gameLog.push_back(InputGameLog(count, "Игрок", CoordinateX1, CoordinateY1, "Следующий_ход"));
        ExportToLog(gameLog, gameLog.size());
        count++;
        if (CheckingTheSolidСourse(board, 'X'))
        {
            winX = true;
            //сохранение журнала игры
            gameLog.push_back(InputGameLog(count, "Игрок", CoordinateX1, CoordinateY1, "Победа_игрока"));
            ExportToLog(gameLog, gameLog.size());
            break;
        }
        else if (count > 9) {
            gameLog.push_back(InputGameLog("Ничья"));
            ExportToLog(gameLog, gameLog.size());
            break;
        }
        //автосохранение
        сoordinateAutoLastSave.push_back(InputCoordinate(to_string(CoordinateX1), to_string(CoordinateY1)));
        ExportToLogAutoSave(сoordinateAutoLastSave, сoordinateAutoLastSave.size());
        //ход нолика - компьютер
        MoveCounter(count, "Нолика");
        TheProgressOfTheZero(board, CoordinateX2, CoordinateY2, count);
        system("cls");
        Interface::PrintGame();
        PlayingField(board, SIZE);
        //сохранение журнала игры
        gameLog.push_back(InputGameLog(count, "Компьютер", CoordinateX2, CoordinateY2, "Следующий_ход"));
        ExportToLog(gameLog, gameLog.size());
        if (CheckingTheSolidСourse(board, 'O'))
        {
            winO = true;

            //сохранение журнала игры
            gameLog.push_back(InputGameLog(count, "Компьютер", CoordinateX2, CoordinateY2, "Победа_компьютера"));
            ExportToLog(gameLog, gameLog.size());
            break;
        }
        else if (count > 9) {
            gameLog.push_back(InputGameLog("Ничья"));
            ExportToLog(gameLog, gameLog.size());
            break;
        }
        //автосохранение
        сoordinateAutoLastSave.push_back(InputCoordinate(to_string(CoordinateX2), to_string(CoordinateY2)));
        ExportToLogAutoSave(сoordinateAutoLastSave, сoordinateAutoLastSave.size());
        count++;
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