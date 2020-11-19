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