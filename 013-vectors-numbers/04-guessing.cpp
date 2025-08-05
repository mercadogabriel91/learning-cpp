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

std::vector<std::vector<int>> subdivide_vector(std::vector<int> &original_vector)
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
    // std::cout << "First half: ";
    // for (int num : first_half)
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    // std::cout << "Second half: ";
    // for (int num : second_half)
    // {
    //     std::cout << num << " ";
    // }
    // std::cout << std::endl;

    return {first_half, second_half};
}

bool is_even(int num)
{
    return (num % 2 == 0);
}

void perfom_computation(bool &go_up, std::vector<int> &number_range, int &target_value)
{
    if (go_up)
    {
        // std::cout << "it's in the upper 50%" << '\n';
        std::vector<std::vector<int>> vector_parts = subdivide_vector(number_range);
        std::vector<int> upper_half = vector_parts[1];

        // save the new array and midpoint
        number_range = upper_half;
        upper_half[(upper_half.size() / 2)];
        if (is_even(upper_half.size()))
        {
            target_value = upper_half[(upper_half.size() / 2)];
        }
        else
        {
            target_value = upper_half[(upper_half.size() / 2) - 1];
        }
    }
    else
    {
        // std::cout << "it's in the lower 50%" << '\n';
        std::vector<std::vector<int>> vector_parts = subdivide_vector(number_range);
        std::vector<int> lower_half = vector_parts[0];

        // save the new array and midpoint
        number_range = lower_half;
        target_value = lower_half[(lower_half.size() / 2)];
    }
}

int main()
{
    std::vector<int> number_range;
    int MAX_QUESTIONS = 7;
    int target_value = 100;
    bool go_up = false;
    char read_val;

    for (int n = 1; n < 101; n++)
    {
        number_range.push_back(n);
    }

    std::cout << "This is a number guessing game (must be between 1 and 100). " << '\n';

    for (int i = 0; i < MAX_QUESTIONS; i++)
    {
        if (i == 0)
        {
            std::cout << "Is the number you're thinking about " << divide_number(target_value) << " or more? y/n " << '\n';
        }
        else
        {
            std::cout << "Is the number you're thinking about " << target_value << " or more? y/n " << '\n';
        }

        std::cin >> read_val;

        if (is_valid_input(read_val))
        {
            // does it go up or down?
            up_or_down(read_val, go_up);
            // make some math shit based on that
            perfom_computation(go_up, number_range, target_value);
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