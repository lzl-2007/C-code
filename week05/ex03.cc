#include<iostream>
#include <memory> 
class Animal{
    int num;
public:
    Animal(int a):num(a){}
    virtual void print()const{
        std::cout<<num;
    }
};
int main(){
    std::cout<<"hellogit";
    int *a=new int[3];
    a[0]=1;
    a[1]=2;
    a[2]=3;
    std::cout<<a[0];
    delete[] a;
    Animal cat(1234);
    cat.print();
    auto p=std::make_unique<Animal>(12);
    p->print();
    return 0;
}