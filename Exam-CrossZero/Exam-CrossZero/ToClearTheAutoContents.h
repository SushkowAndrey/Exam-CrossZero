#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

//очистка автосохранения, если игра закончена
void ToClearTheAutoContents(string logPath)
{
	ofstream FileLog;
	string informations;
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