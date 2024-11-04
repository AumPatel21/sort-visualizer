#include "visualizer.hpp"

int main()
{
    Visualizer visualizer;
    visualizer.run();

    // // make an 8x8 rectangle
    // sf::RectangleShape rectangle(sf::Vector2f(8, 8));
    // // give it a border of 1 pixel
    // rectangle.setOutlineThickness(1);
    // // make the border color white
    // rectangle.setOutlineColor(sf::Color::White);
    // // make the rectangle red
    // rectangle.setFillColor(sf::Color::Red);
    // rectangle.setPosition(100, 100);

    // // create a window
    // sf::RenderWindow window(sf::VideoMode(800, 600), "Sort Visualizer");

    // // run the program as long as the window is open
    // while (window.isOpen())
    // {
    //     // check all the window's events that were triggered since the last iteration of the loop
    //     sf::Event event;
    //     while (window.pollEvent(event))
    //     {
    //         // "close requested" event: we close the window
    //         if (event.type == sf::Event::Closed)
    //             window.close();
    //     }

    //     // clear the window with black color
    //     window.clear(sf::Color::Black);

    //     // draw everything here...
    //     // window.draw(...);
    //     window.draw(rectangle);

    //     // end the current frame
    //     window.display();
    // }

    return 0;
}
