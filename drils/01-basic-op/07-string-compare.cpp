#include "../std_lib_facilities.h"

void pirntOutStrings(string str1, string str2, string str3)
{
    if (str1 < str2 && str1 < str3)
    {
        // str1 is the smallest
        if (str2 < str3)
        {
            cout << str1 << ", " << str2 << ", " << str3 << '\n';
        }
        else
        {
            cout << str1 << ", " << str3 << ", " << str2 << '\n';
        }
    }
    else if (str2 < str1 && str2 < str3)
    {
        // str2 is the smallest
        if (str1 < str3)
        {
            cout << str2 << ", " << str1 << ", " << str3 << '\n';
        }
        else
        {
            cout << str2 << ", " << str3 << ", " << str1 << '\n';
        }
    }
    else
    {
        // str3 is the smallest
        if (str1 < str2)
        {
            cout << str3 << ", " << str1 << ", " << str2 << '\n';
        }
        else
        {
            cout << str3 << ", " << str2 << ", " << str1 << '\n';
        }
    }
}

void validateInput()
{
    string str1;
    string str2;
    string str3;

    cout << "Please enter three strings: " << '\n';
    while (!(cin >> str1 >> str2 >> str3))
    {
        cout << "Invalid input. Please enter three strings: " << '\n';
        cin.clear();                                         // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
    }

    pirntOutStrings(str1, str2, str3);
}

int main()
{
    validateInput();
    return 0;
}