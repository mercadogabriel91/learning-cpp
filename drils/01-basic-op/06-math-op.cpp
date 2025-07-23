#include "../std_lib_facilities.h"

int findLargest(int num1, int num2, int num3)
{
    if (num1 > num2)
    {
        // A > B ?
        // YES
        if (num1 > num3)
        {
            // A > C ?
            // YES
            // A is the largest (num1 > num2 and num1 > num3)

            // Determine 2nd and 3rd largest
            if (num2 > num3)
            {
                // Order: num3, num2, num1
                cout << num3 << ", " << num2 << ", " << num1 << '\n';
            }
            else
            {
                // Order: num2, num3, num1
                cout << num2 << ", " << num3 << ", " << num1 << '\n';
            }
            return num1;
        }
        else
        {
            // NO
            // C > A > B (num3 > num1 > num2)
            cout << num2 << ", " << num1 << ", " << num3 << '\n';
            return num3;
        }
    }
    else
    {
        // NO (num2 >= num1)
        if (num2 > num3)
        {
            // B > C ?
            // YES
            // B is the largest (num2 > num1 and num2 > num3)

            if (num1 > num3)
            {
                // Order: num3, num1, num2
                cout << num3 << ", " << num1 << ", " << num2 << '\n';
            }
            else
            {
                // Order: num1, num3, num2
                cout << num1 << ", " << num3 << ", " << num2 << '\n';
            }
            return num2;
        }
        else
        {
            // NO
            // C >= B >= A (num3 >= num2 >= num1)
            cout << num1 << ", " << num2 << ", " << num3 << '\n';
            return num3;
        }
    }
}

void inputValues()
{
    int num1;
    int num2;
    int num3;

    cout << "Please enter three numbers: ";
    while (!(cin >> num1 >> num2 >> num3))
    {
        cout << "Invalid input. Please enter three integers: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    // Order the numbers by value
    cout << "Sorted order: " << '\n';
    findLargest(num1, num2, num3);
}

int main()
{
    inputValues();
    return 0;
}