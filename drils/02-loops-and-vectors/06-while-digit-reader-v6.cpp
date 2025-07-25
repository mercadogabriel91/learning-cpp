#include <algorithm>
#include <iostream>
#include <limits>

/*
 *   1. Write a program that consists of a while-loop that (each time around the
 * loop) reads in two ints and then prints them. Exit the program when a
 * terminating '|' is entered.
 *  ------
 *   2. Change the program to write out the smaller value is: followed by the
 * smaller of the numbers and the larger value is: followed by the larger value.
 * ------
 *   3. Augment the program so that it writes the line the numbers are equal
 * (only) if they are equal.
 * ------
 *   4. Change the program so that it uses doubles instead of ints.
 * ------
 *   5. Change the program so that it writes out the numbers are almost equal
 * after writing out which is the larger and the smaller if the two numbers
 * differ by less than 1.0/100.
 * ------
 *  6. Now change the body of the loop so that it reads just one double each
 * time around. Define two variables to keep track of which is the smallest and
 * which is the largest value you have seen so far. Each time through the loop
 * write out the value entered. If it’s the smallest so far, write the smallest
 * so far after the number. If it is the largest so far, write the largest so
 * far after the number.
 */

void compute_numbers(double new_number, double current_max,
                     double current_min) {
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
  double new_number = 0;
  double max_so_far, min_so_far;
  bool first_number = true;

  while (is_reading) {
    std::cout << "Please enter one digit" << '\n';

    if (std::cin.peek() == '|') {
      is_reading = false;
      std::cout << "Exiting program." << '\n';
      return 0;
    } else if (!(std::cin >> new_number)) {
      std::cout << "thats some bs" << '\n';
      std::cin.clear();
      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    } else {
      if (first_number) {
        max_so_far = min_so_far = new_number;
        first_number = false;
      } else {
        // Check before updating
        compute_numbers(new_number, max_so_far, min_so_far);

        // Update max/min
        max_so_far = std::max(max_so_far, new_number);
        min_so_far = std::min(min_so_far, new_number);
      }

      std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
  }

  return 0;
}