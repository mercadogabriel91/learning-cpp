#include "../std_lib_facilities.h"

int main()
{
    // int a = 2000;
    // char c = a; // Unsafe conversion from int to char
    // int b = c;

    // if (a != b)
    //     cout << "unsafe convertsion: " << a << "!=" << b << '\n';
    // else
    //     cout << "we have some big ass characters\n";

    double d = 0;
    while (cin >> d)
    {
        int i = d;
        char c = i;
        int i2 = c;
        cout << "d==" << d
             << " i==" << i
             << " i2==" << i2
             << " char(" << c << ")\n";

        return 0;
    }
}