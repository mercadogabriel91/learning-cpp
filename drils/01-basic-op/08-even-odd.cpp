#include "../std_lib_facilities.h"

bool isEven(int n)
{
    return n % 2 == 0;
}

int takeAndValidateInteger()
{
    int n;
    while (!(cin >> n))
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid input. Please enter an integer: " << '\n';
    }

    return n;
}

void processInput()
{
    cout << "Please enter an integer: " << '\n';
    int n = takeAndValidateInteger();
    bool even = isEven(n);
    if (even)
    {
        cout << n << " is even." << '\n';
    }
    else
    {
        cout << n << " is odd." << '\n';
    }
}

int main()
{
    processInput();
    return 0;
}