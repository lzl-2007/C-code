// chapt01/frame_v2.cpp
// frame name


#include <iostream>
#include <string>

const int kWidth = 40;

std::string getUserName()
{
    std::cout<<"Please enter your first name:";
    std::string name;
    std::cin >> name;

    return name;
}

std::string frameUserName(std::string name)
{
    // build the message that we intend to write
    const std::string greeting = "Hello, " + name + "!";
    const int width = std::max(kWidth, static_cast<int>(greeting.size()) + 2);

    const std::string spaces(width, ' ');
    const std::string second = "* " + spaces + " *";
    const std::string first(second.size(), '*');


    return first + '\n' + second + '\n' + greeting + '\n' + second + '\n' + first + '\n';
}

int main()
{
    std::string name = getUserName();
    std::cout<<frameUserName(name);
}
