#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "GameLog.h"
#include "CoordinateLastSave.h"

using namespace std;

//запись информации в файл
void ExportSave(string logPath, string informations)
{
	ofstream FileLog;
	FileLog.open(logPath);
	try
	{
		FileLog << informations << endl;
	}
	catch (...)
	{
		cout << "Ошибка записи в файл" << endl;
	}
	FileLog.close();
}

//автосохранение координат игры для игры с компьютером
void ExportToLogAutoSave(vector <CoordinateAutoLastSave> coordinateAutoLastSave, int size)
{
	string temp;
	for (int i = 0; i < size; i++)
	{
		temp += coordinateAutoLastSave[i].x + ";";
		temp += coordinateAutoLastSave[i].y + ";\n";
	}
	ExportSave("AutoSaveGame.csv", temp);
}

//автосохранение координат игры для двух игроков (перегружена)
void ExportToLogAutoSave(vector <CoordinateAutoLastSave> coordinateAutoLastSave, int size, string players)
{
	string temp;
	for (int i = 0; i < size; i++)
	{
		temp += coordinateAutoLastSave[i].x + ";";
		temp += coordinateAutoLastSave[i].y + ";\n";
	}
	ExportSave("AutoSaveGamePlayers.csv", temp);
}

//журнал игры-экспорт в файл для игры с компьютером
void ExportToLog(vector <GameLog> gameLog, int size)
{
	string temp;
	for (int i = 0; i < size; i++)
	{
		temp += to_string(gameLog[i].GetCount()) + ";";
		temp += gameLog[i].GetPlayer() + ";";
		temp += to_string(gameLog[i].GetCoordinateXplayer()) + ";";
		temp += to_string(gameLog[i].GetCoordinateYplayer()) + ";";
		temp += gameLog[i].GetResult() + ";\n";
	}
	ExportSave("GameLogComputer.csv", temp);
}

//журнал игры-экспорт в файл для двух игроков (перегружена)
void ExportToLog(vector <GameLog> gameLog, int size, string players)
{
	string temp;
	for (int i = 0; i < size; i++)
	{
		temp += to_string(gameLog[i].GetCount()) + ";";
		temp += gameLog[i].GetPlayer() + ";";
		temp += to_string(gameLog[i].GetCoordinateXplayer()) + ";";
		temp += to_string(gameLog[i].GetCoordinateYplayer()) + ";";
		temp += gameLog[i].GetResult() + ";\n";
	}
	ExportSave("GameLogTwoPlayer.csv", temp);
}