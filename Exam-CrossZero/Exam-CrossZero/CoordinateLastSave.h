#pragma once
#include <iostream>
#include <string>

using namespace std;

//класс для записи последних данных прерванной игры
class CoordinateAutoLastSave
{
public:
    string x;
    string y;
    CoordinateAutoLastSave() {}
    CoordinateAutoLastSave(string x, string y)
    {
        this->x = x;
        this->y = y;
    }
    string GetX()
    {
        return x;
    }
    string GetY()
    {
        return y;
    }
};

//функция присвоения координат в конструктор класса
CoordinateAutoLastSave InputCoordinate(string x, string y)
{
    CoordinateAutoLastSave coordinateAutoLastSave(x, y);
    return coordinateAutoLastSave;
}