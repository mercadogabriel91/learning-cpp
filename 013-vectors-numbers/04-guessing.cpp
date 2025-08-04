#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <numeric>

/**
 * 4. Write a program to play a numbers guessing game. The user thinks of a number between 1 and 100 and your program
 * asks questions to figure out what the number is (e.g.,
 * “Is the number you are thinking of less than 50?”). Your program
 * should be able to identify the number after asking no more than seven questions. Hint: Use the < and <= operators and the
 * if-else construct.
 */

int divide_number(int &value)
{
    return value / 2;
}

bool is_valid_input(char &input)
{
    return (input == 'y' || input == 'n');
}

void up_or_down(char &read_val, bool &go_up)
{
    if (read_val == 'y')
    {
        go_up = true;
    }
    else
    {
        go_up = false;
    }
}

void subdivide_vector(std::vector<int> &original_vector)
{

    // Calculate the split point (e.g., in the middle)
    size_t mid_point = original_vector.size() / 2;

    std::vector<int> first_half;
    std::vector<int> second_half;

    // Copy elements to the first half
    first_half.assign(original_vector.begin(), original_vector.begin() + (mid_point - 1));

    // Copy elements to the second half
    second_half.assign(original_vector.begin() + (mid_point - 1), original_vector.end());

    // Print the sub-vectors
    std::cout << "First half: ";
    for (int num : first_half)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Output: 1 2 3 4

    std::cout << "Second half: ";
    for (int num : second_half)
    {
        std::cout << num << " ";
    }
    std::cout << std::endl; // Output: 5 6 7 8
}

void perfom_computation(int &initial_number, int &lucky_number, bool &go_up, std::vector<int> &number_range)
{
    if (go_up)
    {
        subdivide_vector(number_range);
    }
    else
    {
        std::cout << "it's in the lower 50%" << '\n';
    }
}

int main()
{
    std::vector<int> number_range;
    int MAX_QUESTIONS = 7;
    int initial_value = 100;
    int lucky_number = 100;
    bool go_up = false;
    char read_val;

    for (int n = 1; n < 101; n++)
    {
        number_range.push_back(n);
    }

    std::cout << "This is a number guessing game (must be between 1 and 100). " << '\n';

    while (true)
    {
        std::cout << "Is the number you're thinking about " << divide_number(lucky_number) << " or more? y/n " << '\n';
        std::cin >> read_val;

        if (is_valid_input(read_val))
        {
            // does it go up or down?
            up_or_down(read_val, go_up);
            // make some math shit based on that
            perfom_computation(initial_value, lucky_number, go_up, number_range);
        }
        else
        {
            std::cout << "This ain't it chief" << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }

    return 0;
}