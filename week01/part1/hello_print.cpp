#include <iostream>
#include <format>

int main(){
    auto a{10.}, b{20.};
    std::cout << std::format("{:.2f} + {:.2f} = {:.2f}",a, b, a+b);

    return 0;
}