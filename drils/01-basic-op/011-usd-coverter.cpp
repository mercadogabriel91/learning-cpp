#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <cstdlib>
#include <vector>

// Function to set terminal to raw mode (disable line buffering)
void enableRawMode()
{
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag &= ~(ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Function to restore terminal to normal mode
void disableRawMode()
{
    struct termios raw;
    tcgetattr(STDIN_FILENO, &raw);
    raw.c_lflag |= (ICANON | ECHO);
    tcsetattr(STDIN_FILENO, TCSAFLUSH, &raw);
}

// Function to read a key press
int getKey()
{
    int ch = getchar();

    // Check for escape sequence (arrow keys)
    if (ch == 27)
    { // ESC character
        ch = getchar();
        if (ch == 91)
        { // '[' character
            ch = getchar();
            switch (ch)
            {
            case 65:
                return 1; // Up arrow
            case 66:
                return 2; // Down arrow
            }
        }
    }
    else if (ch == 10 || ch == 13)
    { // Enter key (LF or CR)
        return 3;
    }

    return 0; // Unknown key
}

/*
    Function to display options and handle selection
    This function allows the user to select a currency from a list
    and returns the index of the selected currency.
*/
int selectCurrency()
{
    int selectedOption = 0;
    const int numOptions = 3;
    bool selecting = true;
    std::string options[numOptions] = {"Rmb", "Euros", "Pounds"};

    enableRawMode();

    while (selecting)
    {
        system("clear"); // Clear screen
        std::cout << "Select the currency you want to convert to USD: " << std::endl;

        for (int i = 0; i < numOptions; ++i)
        {
            if (i == selectedOption)
            {
                std::cout << "-> "; // Highlight selected option
            }
            else
            {
                std::cout << "   ";
            }
            // std::cout << "Option " << i + 1 << std::endl;
            std::cout << options[i] << std::endl;
        }

        std::cout << "\nUse arrow keys to navigate, Enter to select" << std::endl;

        int key = getKey();

        switch (key)
        {
        case 1: // Up arrow
            if (selectedOption > 0)
            {
                selectedOption--;
            }
            break;
        case 2: // Down arrow
            if (selectedOption < numOptions - 1)
            {
                selectedOption++;
            }
            break;
        case 3: // Enter key
            selecting = false;
            break;
        }
    }

    disableRawMode();
    std::cout << "\nYou selected Option " << options[selectedOption] << std::endl;
    return selectedOption;
}

/*
   This function maps the selected currency index to a conversion rate
   For simplicity, let's assume some fixed rates
*/
double mapCurrencyToRate(int currencyIndex)
{
    std::vector<double> rates = {
        .14,  // Rmb
        1.17, // Euros
        1.35  // Pounds
    };

    return rates[currencyIndex];
}

double calculateUsdValue(double const &rate)
{
    double amount;
    std::cout << "Enter the amount in selected currency: ";
    while (!(std::cin >> amount))
    {
        std::cout << "Invalid input. Please enter a valid number: ";
        std::cin.clear();                                                   // Clear the error flag
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Discard invalid input
    }

    std::cout << "The equivalent USD value is: " << amount * rate << '\n';

    return amount * rate;
}

int main()
{

    int selectedCurrencyIdx = selectCurrency();
    double rate = mapCurrencyToRate(selectedCurrencyIdx);
    calculateUsdValue(rate);

    return 0;
}