#include <iostream>
#include <string>
/*
 * 5. Write a program that performs as a very simple calculator. Your calculator should be able to handle the four basic math
 * operations — add, subtract, multiply, and divide — on two input values. Your program should prompt the user to enter
 * three arguments: two double values and a character to represent an operation. If the entry arguments are 35.6, 24.1, and
 * '+', the program output should be The sum of 35.6 and 24.1 is 59.7. In Chapter 6 we look at a much more
 * sophisticated simple calculator.
 */

bool is_valid_op(char &op)
{
    return (op == '+' || op == '-' || op == '*' || op == '/');
}

int main()
{
    double num1;
    double num2;
    char op;

    std::cout << "Please enter two numbers and one of the following operations: *, +, -, / " << std::endl;
    std::cout << "Like so: 4 4 + "<< " . The exppected result should be 8 " << std::endl;
    std::cin >> num1 >> num2 >> op;

    if (is_valid_op(op))
    {
        switch (op)
        {
        case '+':
            std::cout << num1 + num2 << std::endl;
            break;
        case '-':
            std::cout << num1 - num2 << std::endl;
            break;
        case '*':
            std::cout << num1 * num2 << std::endl;
            break;
        default:
            if (num2 != 0)
            {
                std::cout << num1 / num2 << std::endl;
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