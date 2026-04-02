#include<iostream>
int main(){
    int x=1,y=3,z=5;
    std::cout<<&x<<" "<<&y<<" "<<&z<<"\n";
    int*p1=new int;
    int *p2=new int;
    int *p3=new int;
    std::cout<<p1<<" "<<p2<<" "<<p3<<"\n";

    return 0;
}