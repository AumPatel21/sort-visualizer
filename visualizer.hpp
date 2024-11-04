#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <chrono>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Visualizer
{
public:
    Visualizer();
    void run();
    void drawBar();
    void drawArray();
    void bubbleSort();
    void mergeSort();
    void quickSort();
    // void shuffleArray();

private:

    sf::RenderWindow window;
    sf::Clock clock;
    std::vector<int> arr;    
    std::vector<std::pair<int, sf::RectangleShape>> bars;

    static const int ARRAY_SIZE = 50;
    static const int BAR_WIDTH = 16;
};

#endif // VISUALIZER_HPP