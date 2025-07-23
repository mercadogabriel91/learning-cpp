#include "../std_lib_facilities.h"

int main()
{
    char c = 'x'; // c stores the number 120 (but treats it as a character)
    int i1 = c; // i1 gets the number 120 (and treats it as a number)
    int i2 = 'x';
    char c2 = i1;

    cout << c << ' ' << i1 << ' ' << c2 << '\n';
    return 0;
}