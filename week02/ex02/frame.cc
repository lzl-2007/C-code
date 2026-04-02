// chapt01/frame.cpp
// frame name


#include <iostream>
#include <string>
#include <cmath>

const int kWidth = 40;

int main()
{
    std::cout<<"Please enter your first name:";

    std::string name;
    std::cin >> name;

    // build the message that we intend to write
    const std::string greeting = "Hello, " + name + "!";
    const int width = std::max(kWidth, static_cast<int>(greeting.size()) + 2);
    const std::string spaces(width, ' ');
    const std::string second = "* " + spaces + " *";
    const std::string first(second.size(), '*');

    // write it all
    std::cout<<"";
    std::cout<<first;
    std::cout<<second;
    std::cout<<greeting<<spaces.size();
    std::cout<<second;
    std::cout<<first;
}
