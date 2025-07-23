#include <iostream>
#include <limits>
#include <cmath> // for abs()

int getValidatedInteger()
{
    std::cout << "Please enter a number: ";
    int number;

    while (!(std::cin >> number))
    {
        std::cout << "Invalid input. Please enter an integer: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return number;
}

void performMathOperations(int val1, int val2)
{
    // Comparison
    if (val1 == val2)
    {
        std::cout << "Both values are equal\n";
    }
    else if (val1 > val2)
    {
        std::cout << val1 << " is larger than " << val2 << '\n';
    }
    else
    {
        std::cout << val2 << " is larger than " << val1 << '\n';
    }

    // Mathematical operations
    std::cout << "Sum: " << (val1 + val2) << '\n';
    std::cout << "Difference: " << std::abs(val1 - val2) << '\n';
    std::cout << "Product: " << (val1 * val2) << '\n';

    if (val2 != 0)
    {
        std::cout << "Ratio (first/second): " << static_cast<double>(val1) / val2 << '\n';
    }
    else
    {
        std::cout << "Cannot calculate ratio: division by zero\n";
    }
}

int main()
{
    int val1 = getValidatedInteger();
    int val2 = getValidatedInteger();
    performMathOperations(val1, val2);

    return 0;
}