#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>

/*
 *   1. Write a program that consists of a while-loop that (each time around the loop)
 * reads in two ints and then prints them.
 * Exit the program when a terminating '|' is entered.
 *  ------
 *   2. Change the program to write out the smaller value is: followed by the smaller of the numbers and the larger value
 *  is: followed by the larger value.
 * ------
 *   3. Augment the program so that it writes the line the numbers are equal (only) if they are equal.
 * ------
 *   4. Change the program so that it uses doubles instead of ints.
 * ------
 *   5. Change the program so that it writes out the numbers are almost equal after writing out which is the larger and the
 * smaller if the two numbers differ by less than 1.0/100.
 */

bool almost_equal(const std::vector<double> &numbers)
{
    return (numbers[1] - numbers[0]) < (1.0 / 100);
}

void compute_numbers(const std::vector<double> &numbers)
{
    if (numbers[0] == numbers[1])
    {
        std::cout << "the numbers are equal" << '\n';
    }
    else
    {
        if (almost_equal(numbers))
        {
            std::cout << "The numbers are almost equal" << '\n';
        }
        else
        {
            std::cout << "The smaller value is: " << numbers[0]
                      << " and the larger value is: " << numbers[1] << '\n';
        }
    }
}

int main()
{
    bool is_reading = true;
    double a, b;

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
            std::vector<double> numbers = {a, b};
            std::sort(numbers.begin(), numbers.end());

            // Delegate the computation to a separate function
            compute_numbers(numbers);

            // Add this line to consume the remaining newline
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}