#include "../std_lib_facilities.h"

int main()
{
    string first_name;
    string friend_name;
    char friend_gender = 0;
    int age;

    cout << "Please enter your name and press enter" << '\n';
    cin >> first_name;
    cout << "Hello and welcome " << first_name << '\n';
    cout << "Dear " << first_name << " enter the name of the person you want to talk to: ";
    cin >> friend_name;
    cout << "Hello, " << friend_name << " how are you? I am fine. I miss you." << '\n';
    cout << "enter 3rd person in question name: " << '\n';
    cin >> friend_name;
    cout << "Have you seen " << friend_name << " lately?" << '\n';
    cout << "please enter " << friend_name << " gender, m or f" << '\n';
    cin >> friend_gender;

    if (friend_gender == 'm')
        cout << "if you see " << friend_name << " please ask him to call me." << '\n';
    if (friend_gender == 'f')
        cout << "if you see " << friend_name << " pelase ask her to call me." << '\n';

    cout << "Please enter age" << '\n';
    cin >> age;

    if (age <= 0 || age >= 110)
        simple_error("you're kidding!");

    if (age < 12)
        cout << "Next year you will be " << age + 1 << ".";
    else if (age == 17)
        cout << "Next year you will be able to vote." << '\n';
    else if (age > 70)
        cout << "I hope you are enjoying retirement." << '\n';

    cout << "Yours sincerely, " << first_name << '\n';

    return 0;
}