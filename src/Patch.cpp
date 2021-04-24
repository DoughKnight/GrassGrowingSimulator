#include<SFML/Graphics.hpp>
#include "Patch.h"
#include "Lawn.h"

Patch::Patch(Patch::Kind kind, int tally)
{
    this->kind = kind;
    this->tally = tally;

    if(kind == Patch::Kind::kentuckyBlue)
    {
        drawing.setSize(sf::Vector2f(2, 5));
        drawing.setFillColor(sf::Color(0, 200, 100));
        drawing.setOutlineThickness(1.0f);
        drawing.setOutlineColor(sf::Color(0, 100, 0));
    }
    else if(kind == Patch::Kind::crab)
    {
        drawing.setSize(sf::Vector2f(3, 3));
        drawing.setFillColor(sf::Color(50, 150, 100));
    }
    else if(kind == Patch::Kind::bamboo)
    {
        drawing.setSize(sf::Vector2f(1, 7));
        drawing.setFillColor(sf::Color(0, 255, 0));
        drawing.setOutlineThickness(1.0f);
        drawing.setOutlineColor(sf::Color(0, 100, 0));
    }
}

const sf::RectangleShape& Patch::getDraw()
{
    return drawing;
}

const int Patch::getTally()
{
    return tally;
}
void Patch::grow()
{
    if(tally < 500)
    {
        if(growClock.getElapsedTime().asMilliseconds() >= 1000)
        {
            tally++;
            growClock.restart();
        }
    }
}
