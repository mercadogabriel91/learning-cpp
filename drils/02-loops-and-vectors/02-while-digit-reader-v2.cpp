#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

/*
 * 1. Write a program that consists of a while-loop that (each time around the loop)
 * reads in two ints and then prints them.
 * Exit the program when a terminating '|' is entered.
 *  ---
 * 2. Change the program to write out the smaller value is: followed by the smaller of the numbers and the larger value
 *  is: followed by the larger value.
 */

int main()
{
    bool is_reading = true;
    int a, b;

    while (is_reading)
    {
        std::cout << "Please enter two digits" << '\n';

        if (std::cin.peek() == '|')
        {
            is_reading = false;
            std::cout << "Exiting program." << '\n';
            return 0;
        }
        else if (!(std::cin >> a >> b))
        {
            std::cout << "thats some bs" << '\n';
            std::cin.clear(); // Clear the error state
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
        else
        {
            std::vector<int> numbers = {a, b};
            std::sort(numbers.begin(), numbers.end());

            std::cout << "The smaller value is: " << numbers[0]
                      << " and the larger value is: " << numbers[1] << '\n';

            // Add this line to consume the remaining newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}