#ifndef VISUALIZER_HPP
#define VISUALIZER_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <sstream>
#include <iomanip>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/System.hpp>

class Visualizer
{
public:
    Visualizer(int arrSize);
    void run();
    void drawBar();
    void drawArray();
    void bubbleSort();
    void selectionSort();
    void insertionSort();
    void mergeSort(std::vector<int>);
    void quickSort();

private:
    void greenSwoop();
    void randomArrayGenreator();
    void displayTime(sf::Clock timer, std::string algoName);

    sf::RenderWindow window;
    // sf::Clock clock;
    sf::Text text;
    sf::Font font;
    std::vector<int> arr;
    std::unordered_map<int, sf::RectangleShape> bars;

    int ARRAY_SIZE = 10;
    int BAR_WIDTH;
    int SCREEN_HEIGHT;
    int PIXELS;
    const int GAP = 1; // just to keep some gap between the bars
    const int sleepTime = 100;
    bool isSorting;

    // custom colors
    sf::Color LIGHTBLUE = sf::Color(26, 117, 159);
    sf::Color ORANGE = sf::Color(241, 143, 1);
    sf::Color GREEN = sf::Color(112, 224, 0);
    sf::Color RED = sf::Color(140, 28, 19);
};

#endif // VISUALIZER_HPP