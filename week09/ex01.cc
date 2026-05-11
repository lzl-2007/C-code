#include<iostream>
#include<memory>

int main(){
    auto p1=std::make_unique<int>(34);
    auto p2=std::move(p1);
    std::cout<<*p2;
    return 0;
}