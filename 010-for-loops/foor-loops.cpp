#include <iostream>
#include <string>
#include <cctype>
#include <utility>

std::pair<char, char> return_chars_by_number(const int &n)
{
    char letter = 'a' + n;
    char upper_letter = toupper(letter);
    return {letter, upper_letter};
}

int main()
{
    const int max_char_length = 26;
    for (int i = 0; i < max_char_length; ++i)
    {
        auto [letter, upper_letter] = return_chars_by_number(i);
        std::cout << "Iteration number: " << i << " letter: " << letter << " / " << upper_letter << '\n';
    }

    return 0;
}