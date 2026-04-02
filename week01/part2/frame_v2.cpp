// chapt01/frame_v2.cpp
// frame name

#include <iostream>
#include <string>
using namespace std;

std::string getUserName()
{
    cout << "Please enter your first name:";
    string name;
    cin >> name;

    return name;
}

std::string frameUserName(std::string name)
{
    // build the message that we intend to write
    const string greeting = "Hello, " + name + "!";
    const string spaces(greeting.size(), ' ');
    const string second = "* " + spaces + " *";
    const string first(second.size(), '*');
    const string content = "* " + greeting + " *";

    return first + '\n' + second + '\n' + content + '\n' + second + '\n' + first + '\n';
}

int main()
{
    std::string name = getUserName();
    std::cout << frameUserName(name);

    return 0;
}
