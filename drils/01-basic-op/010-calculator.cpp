#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

std::string getValidInput()
{
    std::string input;
    std::vector<std::string> allowedStrings = {"plus", "minus", "mul", "multiplication", "division", "div", "+", "-", "*", "/"};
    bool isValid = false;

    while (!isValid)
    {
        std::cout << "Enter one of the following options: " << '\n';
        for (const std::string &s : allowedStrings)
        {
            std::cout << s << " ";
        }
        std::cout << ": ";
        std::getline(std::cin, input);

        // Check if the input exists in the allowedStrings vector
        if (std::find(allowedStrings.begin(), allowedStrings.end(), input) != allowedStrings.end())
        {
            isValid = true;
        }
        else
        {
            std::cout << "Invalid input. Please try again." << std::endl;
        }
    }

    return input;
}

std::string defineOperation()
{
    std::string operationInput;
    operationInput = getValidInput();

    if (operationInput == "plus" || operationInput == "+")
    {
        return "+";
    }
    else if (operationInput == "minus" || operationInput == "-")
    {
        return "-";
    }
    else if (operationInput == "mul" || operationInput == "multiplication" || operationInput == "*")
    {
        return "*";
    }
    else if (operationInput == "division" || operationInput == "div" || operationInput == "/")
    {
        return "/";
    }
    else
    {
        std::cerr << "Error: Invalid operation selected." << std::endl;
        return "ERROR";
    }
}

double calculate(const double &a, const double &b, const std::string &operation)
{

    if (operation == "+")
    {
        return a + b;
    }
    else if (operation == "-")
    {
        return a - b;
    }
    else if (operation == "*")
    {
        return a * b;
    }
    else if (operation == "/")
    {
        if (b == 0)
        {
            std::cerr << "Error: Division by zero." << std::endl;
            return 0; // or handle error appropriately
        }
        return a / b;
    }
    else
    {
        std::cerr << "Error: Invalid operation." << std::endl;
        return 0; // or handle error appropriately
    }
}

std::pair<double, double> getNumbers()
{
    std::cout << "Please enter two numbers: " << '\n';
    double number1;
    double number2;

    while (!(std::cin >> number1 >> number2))
    {
        std::cin.clear();                                                   // clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // discard invalid input
        std::cout << "Invalid input. Please enter two valid numbers: ";
    }

    return {number1, number2};
}

int main()
{
    std::string operation = defineOperation();
    auto [number1, number2] = getNumbers();
    double result = calculate(number1, number2, operation);
    std::cout << "The result of " << number1 << " " << operation << " " << number2 << " is: " << result << std::endl;

    return 0;
}