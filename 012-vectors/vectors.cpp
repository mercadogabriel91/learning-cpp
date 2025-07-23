#include <iostream>
#include <vector>
#include <string>

void run_word_filter()
{
    std::vector<std::string> blacklisted_words = {"badword1", "badword2", "badword3"};

    std::string new_word;
    std::cout << "Please enter a word: " << '\n';
    std::cin >> new_word;
    for (std::string word : blacklisted_words)
    {
        if (new_word == word)
        {
            std::cout << "This word is not allowed." << '\n';
            return;
        }
    }
    std::cout << "the word is: " << new_word << '\n';
}

int main()
{
    run_word_filter();
    return 0;
}

// int main()
// {
//     std::vector<int> v = {1, 2, 3, 4, 5};
//     v.push_back(6);
//     for (const int x : v)
//     {
//         std::cout << x << '\n';
//     }

//     return 0;
// }