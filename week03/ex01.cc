#include<iostream>
struct pad{
    int b;
    char a;
    char c;
   
};
int main(){
    static_assert(alignof(int)==4);
    std::cout<<alignof(float);
    return 0;
}