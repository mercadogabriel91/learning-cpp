#include <iostream>
#include <limits>
#include <string>
#include <vector>

/**
 * 3. Read a sequence of double values into a vector. Think of each value as the
 * distance between two cities along a given route. Compute and print the total
 * distance (the sum of all distances). Find and print the smallest and greatest
 * distance between two neighboring cities. Find and print the mean distance
 * between two neighboring cities.
 */

bool is_integer(const std::string &s)
{
  if (s.empty())
  {
    return false;
  }
  // Handle optional leading sign
  size_t start_index = 0;
  if (s[0] == '-' || s[0] == '+')
  {
    start_index = 1;
  }
  // Check if remaining characters are digits
  return std::all_of(s.begin() + start_index, s.end(), ::isdigit);
}

bool validate_input(std::string &input)
{
  return input == "|";
}

std::string read_value(bool &is_reading)
{
  bool is_valid_input = false;
  std::string input;
  std::cin >> input;

  bool is_number = is_integer(input);

  if (!is_number)
  {
    is_valid_input = validate_input(input);
    if (is_valid_input)
    {
      is_reading = false;
      std::cout << "Exiting program." << '\n';
    }
    else
    {
      std::cout << "Breh, give me a number or | " << '\n';
      std::cin.clear();
      std::cin.ignore();
    }
  }

  return input;
}

int main()
{
  std::vector<double> distances;
  std::string read_number_value;
  bool is_reading = true;

  // Output instructions
  std::cout << "Please enter a numeric value " << "or press | to exit program "
            << '\n';

  while (true)
  {
    if (!is_reading)
    {
      break;
    }

    read_number_value = read_value(is_reading);
    double numeric_value = std::stod(read_number_value); // TODO: FIX the handling of non numeric characters 
    //   distances.push_back(numeric_value);

    // max_so_far = std::max(max_so_far, new_number);
    // min_so_far = std::min(min_so_far, new_number);
  }

  return 0;
}