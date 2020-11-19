#pragma once

#include <fstream>
#include <string>
#include <vector>
#include "CoordinateLastSave.h"
#include "GameLog.h"

using namespace std;

//извлекаемые данные - координаты последней игры с компьютером дл¤ продолжени¤
vector <CoordinateAutoLastSave> ImportLastSave(string logPath) {
	ifstream FileAutoLog;
	string temp, X, Y;
	vector <CoordinateAutoLastSave> NewTemp;
	int position;
	try
	{
		FileAutoLog.open(logPath, ios::in);
		while (!FileAutoLog.eof())
		{
			FileAutoLog >> temp;
			for (int i = 0; i < temp.size(); i++)
			{
				position = temp.find(";");
				X = temp.substr(0, position);
				temp = temp.substr(position + 1);
				position = temp.find(";");
				Y = temp.substr(0, position);
				temp = temp.substr(position + 1);
				NewTemp.push_back(InputCoordinate(X, Y));
			}
		}
		FileAutoLog.close();
	}
	catch (...)
	{
		cout << "Файл не открыт" << endl;
	}
	return NewTemp;
}

//извлекаемые данные - координаты последней игры со вторым игроком дл¤ продолжени¤ (перегружена)
vector <CoordinateAutoLastSave> ImportLastSave(string logPath, string players) {
	ifstream FileAutoLog;
	string temp, X, Y, player1, player2;
	vector <CoordinateAutoLastSave> NewTemp;
	int position;
	try
	{
		FileAutoLog.open(logPath, ios::in);
		while (!FileAutoLog.eof())
		{
			FileAutoLog >> temp;
			//запись имен игроков
			position = temp.find(";");
			player1 = temp.substr(0, position);
			temp = temp.substr(position + 1);
			position = temp.find(";");
			player2 = temp.substr(0, position);
			temp = temp.substr(position + 1);
			NewTemp.push_back(InputCoordinate(player1, player2));
			//запись координат
			for (int i = 0; i < temp.size(); i++)
			{
				position = temp.find(";");
				X = temp.substr(0, position);
				temp = temp.substr(position + 1);
				position = temp.find(";");
				Y = temp.substr(0, position);
				temp = temp.substr(position + 1);
				NewTemp.push_back(InputCoordinate(X, Y));
			}
		}
		FileAutoLog.close();
	}
	catch (...)
	{
		cout << "Файл не открыт" << endl;
	}
	return NewTemp;
}

//импорт журнала
vector <GameLog> ImportLog(string logPath)
{
	ifstream FileLog;
	string temp, player, motion;
	int count, x, y;

	vector <GameLog> NewTemp;
	int position;
	try
	{
		FileLog.open(logPath, ios::in);
		while (!FileLog.eof())
		{
			FileLog >> temp;
			for (int i = 0; i < temp.size(); i++)
			{
				//считывание номера хода
				position = temp.find(";");
				count = stoi(temp.substr(0, position));
				temp = temp.substr(position + 1);
				//считывание игрока
				position = temp.find(";");
				player = temp.substr(0, position);
				temp = temp.substr(position + 1);
				//считывание хода координат
				position = temp.find(";");
				x = stoi(temp.substr(0, position));
				temp = temp.substr(position + 1);
				position = temp.find(";");
				y = stoi(temp.substr(0, position));
				temp = temp.substr(position + 1);
				//считывани¤ движени¤ игры
				position = temp.find(";");
				motion = temp.substr(0, position);
				temp = temp.substr(position + 1);
				NewTemp.push_back(InputGameLog(count, player, x, y, motion));	
			}
		}
		FileLog.close();
	}
	catch (...)
	{
		cout << "Файл не открыт" << endl;
	}
	return NewTemp;
}