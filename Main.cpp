#include <iostream>
#include <string>
#include <sstream>

#include <map>
#include <set>

#include <SFML/Graphics.hpp>

#include "include/Patch.h"
#include "include/Lawn.h"

void console(std::string input)
{
    if(input == "/?")
    {
        std::cout << "The \"/?\" command (this) will display helpful information about the game" << std::endl;
        std::cout << "Lorem Ipsum" << std::endl;
    }
}

int main()
{
    sf::Font font;
    font.loadFromFile("res/HARNGTON.ttf");
    sf::RenderWindow window(sf::VideoMode(640, 480), "Grass Growing Simulator");
    Lawn lawn(25, 5, 5);

    std::cout << "I welcome thee to the Grass Growing Simulator" << std::endl;
    std::cout << "Press TAB to access the console" << std::endl;
    std::cout << "Enter \"/?\" for help" << std::endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if(event.type == sf::Event::Closed) window.close();
	        if(event.type == sf::Event::KeyPressed)
	        {
	        	switch(event.key.code)
	        	{
	          		case sf::Keyboard::Escape : window.close();
	           		break;
	           		case sf::Keyboard::Tab :
                    {
                        //std::string input;
                        //std::cin.getline() >> input;
                        //console(input);
                        break;
                    }
                    break;
	           		//case sf::Keyboard::E : lawn.push_back(new Patch(lawn.size()*4, 2, 20+lawn.size(), 0));
	           		default : break;
	           	}
	        }

        }

        window.clear(sf::Color(50, 150, 250));
        lawn.update();

        //draw loops
        sf::RectangleShape test;
        std::map<int, std::map<int, Patch*>> field = lawn.getField();
        for(unsigned int i = 0; i < field.size(); i++)
        {
            for(unsigned int j = 0; j < field[0].size(); j++)
            {
                test = field[i][j]->getDraw();
                test.setPosition((i+8) * lawn.getScale(), (j+8) * lawn.getScale());
                test.setSize(sf::Vector2f(test.getSize().x, -1*test.getSize().y));
                sf::Text tallyText;
                std::stringstream ss;
                ss << field[i][j]->getTally();
                tallyText.setFont(font);
                tallyText.setString(ss.str());
                tallyText.setCharacterSize(10);
                tallyText.setColor(sf::Color::Black);
                tallyText.setPosition((i+8) * lawn.getScale(), (j+8) * lawn.getScale());

                window.draw(test); window.draw(tallyText);
                //needs to draw all tests then all tallies. Reimplement the returning data structure of Lawn
                //do not make new RectangleShapes
            }
        }

        window.display();
    }

    return 0;
}
