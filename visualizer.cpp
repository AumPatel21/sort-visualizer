#include "visualizer.hpp"

Visualizer::Visualizer() : window(sf::VideoMode(800, 600), "SFML Visualizer"), rectangle(sf::Vector2f(100, 100))
{
    rectangle.setFillColor(sf::Color::Red);
    rectangle.setPosition(100, 100);
}

void Visualizer::run()
{
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        window.draw(rectangle);
        window.display();

        sf::Time elapsed = clock.getElapsedTime();
        if (elapsed.asMilliseconds() > 1000)
        {
            clock.restart();
            rectangle.move(10, 0);
        }
    }
}
