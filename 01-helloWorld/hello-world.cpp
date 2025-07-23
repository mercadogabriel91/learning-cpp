#include "../std_lib_facilities.h"

string returnHelloString() {
    return "Hello world!\n";
}

string returnHereWeGo() {
    return "Here we go!\n";
}

void coutMessage() {
    cout << returnHelloString();
    cout << returnHereWeGo();
}

int main() // C++ programs start by executing the function main
{
    coutMessage();
    keep_window_open();
    return 0;
}