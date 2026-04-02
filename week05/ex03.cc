#include<iostream>
#include <memory> 
class Animal{
    int num;
public:
    Animal(int a):num(a){
        if (num<0){
            throw std::invalid_argument("不能是负数");
        }
    }
    virtual void print()const{
        std::cout<<num;
    }
    ~Animal(){
        try{
            std::cout<<num;
        }catch(...){
            std::cout<<"error";
        }
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
    Animal cat(-34);
    cat.print();
    auto p=std::make_unique<Animal>(12);
    p->print();
    std::unique_ptr<int> p1=std::make_unique<int> (12);
    return 0;
}