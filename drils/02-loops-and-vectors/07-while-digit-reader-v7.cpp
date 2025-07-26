#include <cctype>
#include <iostream>
#include <string>
#include <vector>

/*
 * 7. Add a unit to each double entered; that is, enter values such as
 * 10cm, 2.5in, 5ft, or 3.33m. Accept the four units: cm, m, in, ft. Assume
 * conversion factors 1m == 100cm, 1in == 2.54cm, 1ft == 12in. Read the unit
 * indicator into a string. You may consider 12 m (with a space between the
 * number and the unit) equivalent to 12m (without a space).
 *
 * 8. Reject values without units or with “illegal” representations of units,
 * such as y, yard, meter, km, and gallons.
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

int main() {
  bool is_reading = true;
  std::string userInput;

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
      std::cout << userInput << '\n';
    } else {
      std::cout << "Thats some bs meeasuring units" << '\n';
    }
  }

  return 0;
}