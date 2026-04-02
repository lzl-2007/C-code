#include<iostream>
#include<chrono>
void caltime(){
    auto start=std::chrono::high_resolution_clock::now();
    int a=1;
    auto end=std::chrono::high_resolution_clock::now();
    std::chrono::duration<double,std::milli> dtime=end-start;
    std::cout<<dtime.count();
}
int main(){
    caltime();
    return 0;
}