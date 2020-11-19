#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "GameLog.h"
#include "CoordinateLastSave.h"
#include "ExportSave.h"

using namespace std;

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