#include<iostream>
class Animal{
public:
    std::string name;
    int num;

    Animal(std::string a,int b):name(a),num(b){};
    virtual void print()const{
        std::cout<<"there are "<<num<<" aninmals"<<std::endl;
    }
};
class Dog :Animal{
    std::string color;
public:
    Dog(std::string a,int b,std::string c):Animal(a,b),color(c){};
    void print() const{
        std::cout<<"there are "<<num<<color<<"dogs"<<std::endl;
    }
};
int main(){
    
    Animal dog1("cidy",12);
    dog1.print();
    Dog lz("lz",2,"red");
    lz.print();
    void ** vtable=*reinterpret_cast<void***>(&dog1);
    void (*vptr1)(Animal*)=reinterpret_cast<void(*)(Animal*)>(vtable[0]);
    vptr1(&dog1);

    return 0;
}