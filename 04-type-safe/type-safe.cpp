#include "../std_lib_facilities.h"

int main()
{
    cout << "Please enter your first name and age\n";
    string name;       // string variable
    double ageInYears; // double variable

    cin >> name >> ageInYears;
    cout << "Hello, " << name << ". Your age expressed in months is " << ageInYears * 12 << ".\n";
}