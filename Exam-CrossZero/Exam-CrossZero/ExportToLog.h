#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "GameLog.h"
#include "CoordinateLastSave.h"
#include "ExportSave.h"

using namespace std;

///////////журналы//////////////
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