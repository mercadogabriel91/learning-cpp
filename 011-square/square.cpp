#include <iostream>

int square(const int &x)
{
    int result = 0;
    for (int i = 0; i < x; ++i)
    {
        result += x;
    }

    return result;
}

int main()
{
    int number = 9;
    int result = square(number);
    std::cout << "The square of " << number << " is " << result << std::endl;

    return 0;
}