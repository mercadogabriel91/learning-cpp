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
 * 
 * Had to change the approach to something called "binary search" to ensure that the number can be guessed in 7 questions or less.
 * https://en.wikipedia.org/wiki/Binary_search 
 */

bool is_valid_input(char input)
{
    return (input == 'y' || input == 'Y' || input == 'n' || input == 'N');
}

int main()
{
    int low = 1;
    int high = 100;
    int guess;
    char response;
    int questions_asked = 0;
    const int MAX_QUESTIONS = 7;

    std::cout << "Think of a number between 1 and 100, and I'll guess it in "
              << MAX_QUESTIONS << " questions or less!\n\n";

    while (low <= high && questions_asked < MAX_QUESTIONS)
    {
        // Calculate the middle point
        guess = low + (high - low) / 2;
        questions_asked++;

        std::cout << "Question " << questions_asked << ": ";
        std::cout << "Is your number " << guess << " or less? (y/n): ";

        std::cin >> response;

        if (!is_valid_input(response))
        {
            std::cout << "Please enter 'y' for yes or 'n' for no.\n";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            questions_asked--; // Don't count invalid questions
            continue;
        }

        if (response == 'y' || response == 'Y')
        {
            // The number is <= guess, so search the lower half (including guess)
            high = guess;
        }
        else
        {
            // The number is > guess, so search the upper half
            low = guess + 1;
        }

        // Check if we've found it
        if (low == high)
        {
            std::cout << "\nI found it! Your number is " << low << "!\n";
            std::cout << "It took me " << questions_asked << " questions.\n";
            return 0;
        }

        std::cout << "Current range: " << low << " to " << high
                  << " (remaining possibilities: " << (high - low + 1) << ")\n\n";
    }

    // This should never happen with proper binary search
    std::cout << "Something went wrong - couldn't find your number in "
              << MAX_QUESTIONS << " questions.\n";
    std::cout << "Final range: " << low << " to " << high << "\n";

    return 0;
}