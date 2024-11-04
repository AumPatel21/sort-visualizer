#include "visualizer.hpp"

Visualizer::Visualizer() : window(sf::VideoMode(800, 600), "Sort Visualizer")
{
    //  Set the window to close when the close button is clicked
    window.setFramerateLimit(60);

    //  Fill the vector with numbers from 1-100
    for (int i = 1; i <= ARRAY_SIZE; i++)
    {
        arr.push_back(i);
    }
    std::srand(std::time(nullptr));
    //  randomize the numbers   
    std::random_shuffle(arr.begin(), arr.end());
    drawBar();
}

void Visualizer::run()
{
    //  print the shuffled numbers
    // DEBUGGING STUFF START
    for (auto n : arr)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    std::cout << "Array size: " << arr.size() << std::endl;
    // DEBUGGING STUFF END

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed) {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed) {
                if (event.key.code == sf::Keyboard::Space) 
                {
                    bubbleSort();
                    for (auto n : arr) {
                        std::cout << n << " ";
                    }
                    std::cout << std::endl;
                } 
                else if (event.key.code == sf::Keyboard::Escape) {
                    window.close();
                }
            }
        }
        drawArray();
    }
}

void Visualizer::drawArray() {
    window.clear(sf::Color::Black);
    for (auto bar : bars)
    {
        // drawBar(i);
        window.draw(bar.second);
    }
    window.display();
}

void Visualizer::drawBar()
{
    bars.clear();
    for (size_t index = 0; index < ARRAY_SIZE; index++) {
        sf::RectangleShape rectangle(sf::Vector2f(BAR_WIDTH, arr[index] * 10));
        rectangle.setOutlineThickness(0.5);
        rectangle.setOutlineColor(sf::Color::White);
        rectangle.setFillColor(sf::Color::Red);
        rectangle.setPosition(index * BAR_WIDTH, window.getSize().y - arr[index] * 10);
        
        // push the rectangle into vector of bars
        bars.push_back(std::make_pair(arr[index], rectangle));
        
        window.draw(rectangle);
    }
}

void Visualizer::bubbleSort() {
    bool swapped;
    for (int i = 0; i < ARRAY_SIZE - 1; i++) {
        swapped = false;
        for (int current = 0; current < ARRAY_SIZE - i - 1; current++) {
            if (arr[current] > arr[current + 1]) {
                // swappimg the vector with numbers only
                std::swap(arr[current], arr[current+1]);
                swapped = true;
                // swapping the bars vecrot tha contains the pair or number and its corresponding bar
                std::swap(bars[current], bars[current + 1]);

                // highlight the bigger bar
                // bars[current + 1].second.setFillColor(sf::Color::Blue);

                // update the positions of the swapped bars in the vector
                bars[current].second.setPosition(current * BAR_WIDTH, window.getSize().y - arr[current] * 10);
                bars[current + 1].second.setPosition((current + 1)* BAR_WIDTH, window.getSize().y - arr[current + 1] * 10);

                drawArray();
                sf::sleep(sf::milliseconds(50));
            }
        }
        // If no swaps were made, the array is already sorted
        if (!swapped) {
            break;
        }
    }

    // for (auto n : arr) {
    //     std::cout << n << " ";
    // }
}

void Visualizer::mergeSort() {}

void Visualizer::quickSort(){}

