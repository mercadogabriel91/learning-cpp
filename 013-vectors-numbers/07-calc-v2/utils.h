#ifndef UTILS_H
#define UTILS_H

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // For std::all_of
#include <cctype>    // For std::isdigit

/*
 * 6. Make a vector holding the ten string values "zero" "one"..."nine"
 * Use that in a program that converts a digit to
 * its corresponding spelled-out value; e.g., the input 7 gives the output seven. Have the same program, using the same
 * input loop, convert spelled-out numbers into their digit form; e.g., the input seven gives the output 7.
 */

class DigitMapItem
{
public:
    std::string key;
    int value;
};

bool is_digit(std::string &input)
{
    return !input.empty() && std::all_of(input.begin(), input.end(), ::isdigit);
}

bool is_valid_digit(std::string &input)
{
    int int_value = std::stoi(input);
    if (int_value >= 0 && int_value <= 9)
    {
        return true;
    }
    return false;
}

bool is_spelled_out_digit(const std::string &input, const std::vector<DigitMapItem> &digit_map, int &out_value)
{
    for (const auto &item : digit_map)
    {
        if (item.key == input)
        {
            out_value = item.value;
            return true;
        }
    }
    return false;
}

std::string convert_digit_to_string(std::string input, const std::vector<DigitMapItem> &digit_map)
{
    for (DigitMapItem item : digit_map)
    {
        if (item.value == std::stoi(input))
        {
            return item.key;
        }
    }
}

int process_input(std::string &input)
{
    int out_value = -1;

    std::vector<DigitMapItem> digit_map = {
        {"zero", 0},
        {"one", 1},
        {"two", 2},
        {"three", 3},
        {"four", 4},
        {"five", 5},
        {"six", 6},
        {"seven", 7},
        {"eight", 8},
        {"nine", 9}};

    // std::cout << "Enter a digit (0-9) or its spelled-out form (zero-nine): ";
    if (is_digit(input))
    {
        if (is_valid_digit(input))
        {
            return std::stoi(input);
        }
        else
        {
            std::cout << "Number is out of range should be: (0 - 9)" << std::endl;
            return out_value;
        }
    }
    else
    {
        is_spelled_out_digit(input, digit_map, out_value);
        if (out_value != -1)
        {
            return out_value;
        }
        std::cout << "The spelled number is not in the list " << '\n';
        return out_value; // Return -1 if not found
    }
}

#endif
