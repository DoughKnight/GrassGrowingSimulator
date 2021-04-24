#include <unordered_set>

#include <map>
#include <set>

#include <SFML/Graphics.hpp>
#include <SFML/System/Clock.hpp>

#include "Patch.h"
#include "Lawn.h"

Lawn::Lawn(int scale, int w, int h)
{
    this->scale = scale;
    for(int i = 0; i < w; i++)
    {
        for(int j = 0; j < h; j++) field[i][j] = new Patch(Patch::Kind::bamboo, 1);
    }
}

Lawn::~Lawn()
{
    //dtor
}

const int Lawn::getScale()
{
    return scale;
}

const std::map<int, std::map<int, Patch*>> Lawn::getField()
{
    return field;
}

void Lawn::update()
{
    for(unsigned int i = 0; i < field.size(); i++)
    {
        for(unsigned int j = 0; j < field[0].size(); j++) field[i][j]->grow();
    }
}
