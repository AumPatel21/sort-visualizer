#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Visualizer
{
public:
    Visualizer();
    void run();

private:
    sf::RenderWindow window;
    sf::RectangleShape rectangle;
    sf::Clock clock;
};

#endif // VISUALIZER_HPP