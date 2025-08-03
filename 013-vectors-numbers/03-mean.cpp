#include <iostream>
#include <limits>
#include <string>
#include <vector>
#include <numeric> // Required for std::accumulate

/**
 * 3. Read a sequence of double values into a vector. Think of each value as the
 * distance between two cities along a given route. Compute and print the total
 * distance (the sum of all distances). Find and print the smallest and greatest
 * distance between two neighboring cities. Find and print the mean distance
 * between two neighboring cities.
 */

bool is_number(const std::string &s)
{
  if (s.empty())
  {
    return false;
  }

  size_t start = 0;
  // Handle optional sign
  if (s[0] == '-' || s[0] == '+')
  {
    start = 1;
    if (s.length() == 1)
      return false; // Just a sign isn't valid
  }

  bool has_dot = false;
  for (size_t i = start; i < s.length(); ++i)
  {
    if (s[i] == '.')
    {
      if (has_dot)
        return false; // Multiple dots
      has_dot = true;
    }
    else if (!std::isdigit(s[i]))
    {
      return false;
    }
  }

  return true;
}

bool validate_input(std::string &input)
{
  return input == "|";
}

bool is_valid(std::string &input, bool &is_reading)
{
  std::cin >> input;

  if (validate_input(input))
  {
    is_reading = false;
    std::cout << "Exiting program." << '\n';
    return false;
  }

  if (!is_number(input))
  {
    std::cout << "Breh, give me a number or | " << '\n';
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return false;
  }

  return true; // Valid number
}

void compute_values(std::vector<double> &distances)
{
  if (distances.size() > 0)
  {
    // Print total sum fo distances
    double total_sum = std::accumulate(distances.begin(), distances.end(), 0.0);
    std::cout << "The total sum is " << total_sum << '\n';

    // Print smallest and greatest
    std::cout << "Smallest distance: " << *std::min_element(distances.begin(), distances.end()) << '\n';
    std::cout << "Greatest distance: " << *std::max_element(distances.begin(), distances.end()) << '\n';

    // Print the mean
    double mean = total_sum / distances.size();
    std::cout << "The mean distance is: " << mean << '\n';
  }
}

int main()
{
  std::vector<double> distances;
  std::string read_number_value;
  bool is_reading = true;
  std::string input;

  // Output instructions
  std::cout << "Please enter a numeric value or press | to exit program" << '\n';

  while (is_reading)
  {
    if (is_valid(input, is_reading))
    {
      // Only convert if we have a valid number
      double numeric_value = std::stod(input);
      distances.push_back(numeric_value);
      std::cout << "Added: " << numeric_value << std::endl;
    }
  }
  compute_values(distances);

  return 0;
}