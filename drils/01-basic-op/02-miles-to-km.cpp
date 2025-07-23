#include <iostream>
#include <limits>

double milesToKmConverter(double miles)
{
    return miles * 1.609344;
}

double getValidatedInput()
{
    double miles;
    std::cout << "Please enter the number of miles to convert to kilometers: ";

    while (!(std::cin >> miles))
    {
        std::cout << "Invalid input. Please enter a number: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }

    return miles;
}

int main()
{
    double miles = getValidatedInput();
    double kilometers = milesToKmConverter(miles);

    std::cout << miles << " miles equals " << kilometers << " kilometers.\n";

    return 0;
}