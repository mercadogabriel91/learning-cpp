#include <iostream>
#include <string>
#include "utils.h"

/*
 * 5. Write a program that performs as a very simple calculator. Your calculator should be able to handle the four basic math
 * operations — add, subtract, multiply, and divide — on two input values. Your program should prompt the user to enter
 * three arguments: two double values and a character to represent an operation. If the entry arguments are 35.6, 24.1, and
 * '+', the program output should be The sum of 35.6 and 24.1 is 59.7. In Chapter 6 we look at a much more
 * sophisticated simple calculator.
 *
 * 7. Modify the “mini calculator” from exercise 5 to accept (just) single-digit numbers written as either digits or spelled out.
 */

bool is_valid_op(char &op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

int main()
{
    std::string first_number_input = "0";
    std::string second_number_input = "0";
    int fist_number = 0;
    int second_number = 0;
    char op;

    std::cout << "Please enter two (single digit positive) numbers and one of the following operations: *, +, -, / " << '\n';
    ;

    std::cout << "First number please..." << '\n';
    std::cin >> first_number_input;
    int result = process_input(first_number_input);
    if (result != -1)
    {
        fist_number = result;
    }
    else
    {
        return 1;
    }

    std::cout << "Second number please..." << '\n';
    std::cin >> second_number_input;
    int result2 = process_input(second_number_input);
    if (result2 != -1)
    {
        second_number = result2;
    }
    else
    {
        return 1;
    }

    std::cout << "Please enter an operator now  *, +, -, /" << '\n';
    std::cin >> op;

    if (is_valid_op(op) && (fist_number != -1) && (second_number != -1))
    {
        switch (op)
        {
        case '+':
            std::cout << "The result of your sum is: " << '\n';
            std::cout << fist_number + second_number << std::endl;
            break;
        case '-':
            std::cout << "The result of your decrement is: " << '\n';
            std::cout << fist_number - second_number << std::endl;
            break;
        case '*':
            std::cout << "The result of your multiplication is: " << '\n';
            std::cout << fist_number * second_number << std::endl;
            break;
        default:
            if (second_number != 0)
            {
                std::cout << "The result of your division is: " << '\n';
                std::cout << fist_number / second_number << std::endl;
            }
            else
            {
                std::cout << "Division by two will go boom boom" << std::endl;
            }
        }
    }
    else
    {
        std::cout << "You need to enter a valid operator my dude " << std::endl;
    }

    return 0;
}