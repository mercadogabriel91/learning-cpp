#include "../std_lib_facilities.h"

string lowerCaseInput(string value)
{
    string result;
    for (char c : value)
    {
        result += tolower(c);
    }

    return result;
}

int mapStringToDigit(string value)
{
    string curatedValue = lowerCaseInput(value);
    if (curatedValue == "zero")
    {
        return 0;
    }
    else if (curatedValue == "one")
    {
        return 1;
    }
    else if (curatedValue == "two")
    {
        return 2;
    }
    else if (curatedValue == "three")
    {
        return 3;
    }
    else if (curatedValue == "four")
    {
        return 4;
    }
    else
    {
        return -1;
    }
}

void validateInput()
{
    string input;
    cout << "Please enter a number in words between zero and four: " << '\n';

    while (!(cin >> input))
    {
        cin.clear();                                         // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "Invalid input. Please enter a number in words between zero and four: " << '\n';
    }

    int result = mapStringToDigit(input);
    if (result == -1)
    {
        cout << "Not a number I know." << '\n';
    }
    else
    {
        cout << "The digit is: " << result << '\n';
    }
}

int main()
{
    validateInput();
    return 0;
}