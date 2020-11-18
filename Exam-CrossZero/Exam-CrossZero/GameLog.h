#pragma once
#include <iostream>
#include <string>

using namespace std;

//журнал игры
class GameLog
{
private:
	int count;
	string player;
	int coordinateXplayer;
	int coordinateYplayer;
	string result;
public:
	GameLog() {}
	GameLog(string result)
	{
		this->result = result;
	}
	GameLog(int count, string player, int coordinateXplayer, int coordinateYplayer, string result)
	{
		this->count = count;
		this->player = player;
		this->coordinateXplayer = coordinateXplayer;
		this->coordinateYplayer = coordinateYplayer;
		this->result = result;
	}
	int GetCount()
	{
		return count;
	}
	string GetPlayer()
	{
		return player;
	}
	int GetCoordinateXplayer()
	{
		return coordinateXplayer;
	}
	int GetCoordinateYplayer()
	{
		return coordinateYplayer;
	}
	string GetResult()
	{
		return result;
	}
};

//запись в журнал
GameLog InputGameLog(int count, string player, int coordinateXplayer, int coordinateYplayer, string result)
{
	GameLog gameLog(count, player, coordinateXplayer, coordinateYplayer, result);
	return gameLog;
}

//запись в журнал в случае ничьи-по¤вл¤етс¤ мусор
GameLog InputGameLog(string result)
{
	GameLog gameLog(result);
	return gameLog;
}

//вывод элемента журнала на экран
void PrintGameLog(GameLog gameLog)
{
	cout << "’од игры " << gameLog.GetCount() << " - " << gameLog.GetPlayer() << " выбрал координаты "
		<< gameLog.GetCoordinateXplayer() << " и " << gameLog.GetCoordinateYplayer() << " - " << gameLog.GetResult() << endl;
}

//вывод всего журнала на экран
void OutputLog(vector <GameLog> gameLog)
{
	cout << "∆урнал последней игры" << endl;
	for (auto element : gameLog)
	{
		PrintGameLog(element);
		cout << "_______________________________" << endl;
	}
}