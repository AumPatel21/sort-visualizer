#include "visualizer.hpp"

Visualizer::Visualizer(int arrSize) : window(sf::VideoMode(800, 600), "Sort Visualizer"), ARRAY_SIZE(arrSize), isSorting(false)
{
    //  Set the window to close when the close button is clicked
    window.setFramerateLimit(60);

    BAR_WIDTH = (window.getSize().x / ARRAY_SIZE);
    SCREEN_HEIGHT = window.getSize().y;
    PIXELS = (SCREEN_HEIGHT / ARRAY_SIZE) - 10;

    randomArrayGenreator();
}

// FIXME: timer not working properly!
void Visualizer::run()
{
    sf::Clock timer;

    std::cout << "Unsorted: ";
    for (auto n : arr)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                window.close();
            }
            if (event.type == sf::Event::KeyPressed)
            {
                if (event.key.code == sf::Keyboard::B)
                {
                    // timer.restart();
                    displayTime(timer, "Bubble Sort\n");
                    bubbleSort();
                    std::cout << "Sorted: ";
                    for (auto n : arr)
                    {
                        std::cout << n << " ";
                    }
                    std::cout << std::endl;
                }
                if (event.key.code == sf::Keyboard::S)
                {
                    timer.restart();
                    // displayTime("Selection Sort\n");
                    selectionSort();
                    std::cout << "Sorted: ";
                    for (auto n : arr)
                    {
                        std::cout << n << " ";
                    }
                    std::cout << std::endl;
                }
                if (event.key.code == sf::Keyboard::I)
                {
                    timer.restart();
                    // displayTime("Insertion Sort\n");
                    insertionSort();
                    std::cout << "Sorted: ";
                    for (auto n : arr)
                    {
                        std::cout << n << " ";
                    }
                    std::cout << std::endl;
                }
                if (event.key.code == sf::Keyboard::R)
                {
                    timer.restart();
                    // displayTime("<Algorithm_Name>\n");
                    randomArrayGenreator();
                    std::cout << "Unsorted: ";
                    for (auto n : arr)
                    {
                        std::cout << n << " ";
                    }
                    std::cout << std::endl;
                    std::cout << std::endl;
                }
                else if (event.key.code == sf::Keyboard::Escape)
                {
                    window.close();
                }
            }
        }

        // displayTime(timer, "");

        // displayTime("<Algorithm_Name>\n");
        window.clear();
        drawArray();
        // window.draw(text);
        window.display();
    }
}

void Visualizer::drawArray()
{
    window.clear(sf::Color::Black);

    for (auto &pole : bars)
    {
        window.draw(pole.second);
    }
    window.draw(text);
    window.display();
}

void Visualizer::drawBar()
{
    bars.clear();
    for (int index = 0; index < ARRAY_SIZE; index++)
    {
        sf::RectangleShape rectangle(sf::Vector2f(BAR_WIDTH - GAP, arr[index] * PIXELS));
        rectangle.setOutlineThickness(0.5);
        rectangle.setOutlineColor(sf::Color::White);
        rectangle.setFillColor(ORANGE);
        rectangle.setPosition(index * BAR_WIDTH, window.getSize().y - arr[index] * PIXELS);

        // Push the rectangle into our hash map
        bars[index] = rectangle;

        window.draw(rectangle);
    }
}

void Visualizer::bubbleSort()
{
    bool swapped;
    for (int i = 0; i < ARRAY_SIZE - 1; i++)
    {
        swapped = false;
        for (int current = 0; current < ARRAY_SIZE - i - 1; current++)
        {
            // Optional: Highlight the bars being swapped
            bars[current].setFillColor(LIGHTBLUE);
            bars[current + 1].setFillColor(LIGHTBLUE);

            // displayTime("Bubble Sort \n");
            // draw the array
            drawArray();

            // add a little delay to show the visual process
            sf::sleep(sf::milliseconds(sleepTime));

            if (arr[current] > arr[current + 1])
            {
                // swap the values in the vector containing numbers only
                std::swap(arr[current], arr[current + 1]);
                swapped = true;

                // Update the rectangles' heights and positions in bars
                bars[current].setSize(sf::Vector2f(BAR_WIDTH, arr[current] * PIXELS));
                bars[current + 1].setSize(sf::Vector2f(BAR_WIDTH, arr[current + 1] * PIXELS));

                // Update positions of the bars
                bars[current].setPosition((current * BAR_WIDTH) - GAP, window.getSize().y - arr[current] * PIXELS);
                bars[current + 1].setPosition(((current + 1) * BAR_WIDTH) - GAP, window.getSize().y - arr[current + 1] * PIXELS);
            }
            // Reset colors after comparison
            bars[current].setFillColor(ORANGE);
            bars[current + 1].setFillColor(ORANGE);

            // Reapply outline properties to ensure visibility
            bars[current].setOutlineThickness(1.0);
            bars[current].setOutlineColor(sf::Color::White);
            bars[current + 1].setOutlineThickness(1.0);
            bars[current + 1].setOutlineColor(sf::Color::White);

            // Draw the array with updated positions and colors
            drawArray();
            sf::sleep(sf::milliseconds(sleepTime)); // Additional delay for swap visualization
        }
        if (!swapped)
        {
            break;
        }
    }
    greenSwoop();
}

void Visualizer::selectionSort()
{
    int minIndex;
    for (int i = 0; i < ARRAY_SIZE - 1; i++)
    {
        // displayTime("Selection Sort\n");
        // Assume that the first index is the minimum value
        minIndex = i;

        // Highlight the bars being compared and swapped
        bars[i].setFillColor(LIGHTBLUE);
        drawArray();
        sf::sleep(sf::milliseconds(sleepTime));

        for (int j = i + 1; j < ARRAY_SIZE; j++)
        {
            // Highlight the bars being compared and swapped
            bars[j].setFillColor(RED);
            drawArray();
            sf::sleep(sf::milliseconds(sleepTime));

            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }

            bars[j].setFillColor(ORANGE);
        }
        // swap the current index with the newly found minimum index
        std::swap(arr[i], arr[minIndex]);

        bars[i].setSize(sf::Vector2f(BAR_WIDTH, arr[i] * PIXELS));
        bars[minIndex].setSize(sf::Vector2f(BAR_WIDTH, arr[minIndex] * PIXELS));

        bars[i].setPosition(((i * BAR_WIDTH) - GAP), window.getSize().y - arr[i] * PIXELS);
        bars[minIndex].setPosition(((minIndex * BAR_WIDTH) - GAP), window.getSize().y - arr[minIndex] * PIXELS);

        // Reset colors after comparison
        bars[i].setFillColor(ORANGE);
        bars[minIndex].setFillColor(ORANGE);

        // Reapply outline properties to ensure visibility
        bars[i].setOutlineThickness(1.0);
        bars[i].setOutlineColor(sf::Color::White);
        bars[minIndex].setOutlineThickness(1.0);
        bars[minIndex].setOutlineColor(sf::Color::White);

        // Draw the array with updated positions and colors
        drawArray();
        sf::sleep(sf::milliseconds(sleepTime)); // Additional delay for swap visualization
    }
    greenSwoop();
}

void Visualizer::insertionSort()
{
    for (int i = 1; i < ARRAY_SIZE; i++)
    {
        // displayTime("Insertion Sort\n");

        int key = arr[i];
        int j = i - 1;

        // Highlight the key element being inserted
        bars[i].setFillColor(sf::Color::Yellow);
        drawArray();
        sf::sleep(sf::milliseconds(sleepTime + 100));

        while (j >= 0 && arr[j] > key)
        {
            bars[j].setFillColor(LIGHTBLUE);
            drawArray();
            sf::sleep(sf::milliseconds(sleepTime + 100));

            arr[j + 1] = arr[j];

            bars[j + 1].setSize(sf::Vector2f(BAR_WIDTH, arr[j + 1] * PIXELS));
            bars[j + 1].setPosition(((j + 1) * BAR_WIDTH) - GAP, window.getSize().y - arr[j + 1] * PIXELS);

            j--;
        }
        arr[j + 1] = key;

        // Update the position of the key element in the visualizer
        bars[j + 1].setSize(sf::Vector2f(BAR_WIDTH, key * PIXELS));
        bars[j + 1].setPosition(((j + 1) * BAR_WIDTH) - GAP, window.getSize().y - key * PIXELS);

        for (int k = 0; k < i; k++)
        {
            bars[k].setFillColor(ORANGE);
            // Reapply outline properties to ensure visibility
            bars[k].setOutlineThickness(1.0);
            bars[k].setOutlineColor(sf::Color::White);
            // bars[current + 1].setOutlineThickness(1.0);
            // bars[current + 1].setOutlineColor(sf::Color::White);
        }
        drawArray();
        sf::sleep(sf::milliseconds(sleepTime + 100));
    }
    greenSwoop();
}

void Visualizer::mergeSort(std::vector<int>)
{
    if (arr.size() == 0 || arr.size() == 1)
    {
        return;
    }
}

void Visualizer::quickSort() {}

// just for satisfaction
void Visualizer::greenSwoop()
{
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        bars[i].setFillColor(GREEN);
        bars[i + 1].setFillColor(GREEN);
        bars[i + 2].setFillColor(GREEN);
        drawArray();
        sf::sleep(sf::milliseconds(20));

        bars[i].setFillColor(ORANGE);
        // bars[i + 1].setFillColor(ORANGE);
        // bars[i + 2].setFillColor(ORANGE);
        drawArray();
        sf::sleep(sf::milliseconds(20));
    }
}

void Visualizer::randomArrayGenreator()
{
    // remove the old numbers
    arr.clear();
    //  Fill the vector with numbers from 1 to ARRAY_SIZE
    for (int i = 1; i <= ARRAY_SIZE; i++)
    {
        arr.push_back(i);
    }
    // Make sure the shuffle is random every time
    std::srand(std::time(nullptr));
    //  randomize the numbers
    std::random_shuffle(arr.begin(), arr.end());
    drawBar();
}

void Visualizer::displayTime(sf::Clock clock, std::string algoName)
{
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << "Error! Font not found." << std::endl;
        exit(1);
    }
    text.setFont(font);
    text.setCharacterSize(30);
    text.setFillColor(sf::Color::White);
    text.setPosition(10, 10);
    text.setString("Time: ");

    // Update elapsed time
    sf::Time elapsed = clock.getElapsedTime();
    std::ostringstream oss;
    oss << std::fixed << std::setprecision(3);
    oss << "Time: " << elapsed.asSeconds() << "s";
    text.setString(algoName + oss.str());
}