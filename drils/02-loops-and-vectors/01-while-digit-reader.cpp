#include <iostream>
#include <vector>

/*
 * 1. Write a program that consists of a while-loop that (each time around the loop)
 * reads in two ints and then prints them.
 * Exit the program when a terminating '|' is entered.
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
            std::cout << "That looks ok" << '\n';
        }
    }

    return 0;
}