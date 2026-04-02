#include <iostream>
#include <string>
#include <vector>

int main(){
    std::vector<std::string> msgs = {"hello", "world", "!", "\n"};
    for(auto const& msg: msgs)
    {
        std::cout << msg << ' ';
    }

    return 0;
}