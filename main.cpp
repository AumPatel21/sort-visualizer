#include "visualizer.hpp"

int main(int argc, char *argv[])
{
    int array_size;
    std::cout << "\nWelcome to my Sorting Visualizer!\n";
    std::cout << "All sorting algorithms are associated with a letter on the keyboard:\n";
    std::cout << "Press \n B to run Bubble sort.\n S to run Selection Sort.\n I to run Insertion Sort.\n M to run Merge Sort (N/A).\n Q to run Quick Sort (N/A).\n";
    std::cout << "\nTo reset, press R.\n\n";

    std::cout << "Please enter the array size you want to visualize: ";
    std::cin >> array_size;

    if (array_size <= 0)
    {
        std::cerr << "Error! ARRAY_SIZE must be greater than 0." << std::endl;
    }

    Visualizer visualizer(array_size);
    visualizer.run();

    return 0;
}
