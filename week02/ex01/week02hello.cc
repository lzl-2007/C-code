#include<vector>
#include<string>
#include<iostream>
int main(){
    std::vector<std::string> messages{"hello","wprld","c++","!"};
    for (auto const &msg : messages){
        std::cout<<msg<<" ";
    }
    return 0;
}
