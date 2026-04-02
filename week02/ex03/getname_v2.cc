// chapt01/getname_v2.cpp
// ask for a person's name, and greet the person


#include <iostream>
#include <string>

std::string getUserName()
{
    std::cout<<"Please enter your first name:";
    std::string name;
    std::cin >> name;

    return name;
}

void greetUser(std::string name)
{
    std::cout<<"Hello"<<name;
}

int main()
{
    std::string name = getUserName();
    greetUser(name);
}
