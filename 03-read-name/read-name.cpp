#include "../std_lib_facilities.h"

void ioName()
{
    string name;
    cout << "Please enter your name (followed by Enter key): \n";
    cin >> name;
    cout << "Hello and welcome, " << name << "!\n";
}

int main()
{
    ioName();
    return 0;
}