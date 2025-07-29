#include <cctype>
#include <iostream>
#include <string>
#include <vector>

/*
 * 9. Keep track of the sum of values entered (as well as the smallest and the
 * largest) and the number of values entered. When the loop ends, print the
 * smallest, the largest, the number of values, and the sum of values. Note that
 * to keep the sum, you have to decide on a unit to use for that sum; use
 * meters.
 *
 * 10. Keep all the values entered (converted into meters) in a vector. At the
 * end, write out those values.
 *
 * 11. Before writing out the values from the vector, sort them (that’ll make
 * them come out in increasing order).
 */

bool validate_str_format(const std::string &str) {
  bool hasLetter = false;
  bool hasNumber = false;

  for (char c : str) {
    if (std::isalpha(c)) {
      hasLetter = true;
    } else if (std::isdigit(c)) {
      hasNumber = true;
    }

    // Optimization: if both conditions are met, no need to continue
    if (hasLetter && hasNumber) {
      return true;
    }
  }

  return (hasLetter && hasNumber);
}

std::string extract_unit(const std::string &str) {
  std::vector<char> units = {};

  for (char c : str) {
    if (std::isalpha(c)) {
      units.push_back(c);
    }
  }

  std::string extractedUnits(units.begin(), units.end());

  return extractedUnits;
}

bool containsSubstring(const std::string &extractedUnits,
                       const std::string &valid_units) {
  // Split the valid units string and check for exact matches
  std::string valid_units_copy = valid_units;
  size_t pos = 0;
  std::string token;

  while ((pos = valid_units_copy.find(", ")) != std::string::npos) {
    token = valid_units_copy.substr(0, pos);
    if (token == extractedUnits) {
      return true;
    }
    valid_units_copy.erase(0, pos + 2); // +2 for ", "
  }

  // Check the last token
  if (valid_units_copy == extractedUnits) {
    return true;
  }

  return false;
}

bool is_valid_input(const std::string &input) {
  std::string valid_units = "cm, m, in, ft";
  bool is_valid_str_format = validate_str_format(input);
  std::string units = extract_unit(input);
  bool is_valid_unit = containsSubstring(units, valid_units);

  return (is_valid_str_format && is_valid_unit);
}

double extract_number(const std::string &input) {
  std::string number_str =
      input.substr(0, input.find_first_not_of("0123456789."));
  return std::stod(number_str);
}

double convert_to_meters(const std::string &input) {
  const double m_to_cm = 100;
  const double cm_to_m = 1 / m_to_cm;
  const double in_to_cm = 2.54;
  const double ft_to_in = 12;
  const double ft_to_cm = ft_to_in * in_to_cm;

  std::string units = extract_unit(input);
  double number = extract_number(input);

  if (units != "m") {
    if (units == "cm") {
      number /= m_to_cm;
    } else if (units == "in") {
      number *= (in_to_cm * cm_to_m);
    } else if (units == "ft") {
      number *= (ft_to_cm * cm_to_m);
    }
  }

  return number;
}

void find_min_max(double new_number, double current_max, double current_min) {
  if (new_number > current_max) {
    std::cout << "That's the largest value we have seen so far" << '\n';
  }
  if (new_number < current_min) {
    std::cout << "That's the smallest value we have seen so far" << '\n';
  } else if (new_number == current_max || new_number == current_min) {
    std::cout << "Bruh" << '\n';
  }
}

int main() {
  bool is_reading = true;
  bool first_number = true;
  std::string userInput;
  double total_sum = 0;
  double new_number = 0;
  double max_so_far, min_so_far;
  std::vector<double> values;

  while (is_reading) {
    std::cout
        << "Please enter one digit and a unit (cm, m, in, ft) or '|' to exit"
        << '\n';

    if (std::cin.peek() == '|') {
      is_reading = false;
      std::cout << "Exiting program." << '\n';
      return 0;
    }

    std::getline(std::cin, userInput);

    if (is_valid_input(userInput)) {
      double vlue_in_meters = convert_to_meters(userInput);
      total_sum += vlue_in_meters;
      new_number = vlue_in_meters;

      if (first_number) {
        max_so_far = min_so_far = new_number;
        first_number = false;
      } else {
        // Check before updating
        find_min_max(new_number, max_so_far, min_so_far);

        // Update max/min
        max_so_far = std::max(max_so_far, new_number);
        min_so_far = std::min(min_so_far, new_number);
      }

      // Add the value to the vector and sort it
      values.push_back(vlue_in_meters);
      std::sort(values.begin(), values.end());

      // Print the values in increasing order
      std::cout << "Values in increasing order: ";
      for (double value : values) {
        std::cout << value << " ";
      }
      // Print the total sum
      std::cout << "Total sum expressed in meters:: " << total_sum << '\n';
    } else {
      std::cout << "Thats some bs meeasuring units" << '\n';
    }
  }

  return 0;
}