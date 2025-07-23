#include <iostream>
#include <vector>
#include <string>

std::vector<std::string> instructions = {"get up", "make sure to avoid obstacles", "locate the door on the current room if there are any", "walk twards the door", "open the door", "walk through the door", "locate the kitchen", "walk towards the kitchen", "open the kithen door if there is one", "step inside the kitchen"};

void gotoKitchen()
{
    for (std::string instruction : instructions)
    {
        std::cout << instruction << " \n";
    }
}

int main()
{
    gotoKitchen();
    return 0;
}