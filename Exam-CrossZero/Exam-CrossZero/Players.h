#pragma once

#include <iostream>
#include <string>

using namespace std;

//игроки
class Players
{
private:
	string player1;
	string player2;
public:
	Players() {}
	Players(string player1, string player2) 
	{
		this->player1 = player1;
		this->player2 = player2;
	}
	void SetPlayer(string player1, string player2)
	{
		this->player1 = player1;
		this->player2 = player2;
	}
	string GetPlayer1()
	{
		return player1;
	}
	string GetPlayer2()
	{
		return player2;
	}
};

//ввод имен игроков
Players ConsoleInputPlayers()
{
	string player1, player2;
	do {
		cout << "Введите имя первого игрока - "; cin >> player1;
		cout << "Введите имя второго игрока - "; cin >> player2;
		system("cls");
		if (player1 == player2) cout << "Одинаковые имена. Повторите ввод" << endl;
	} while (player1 == player2);
	Players players(player1, player2);
	return players;
}