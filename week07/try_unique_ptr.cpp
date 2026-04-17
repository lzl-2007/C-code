#include<memory>
#include<iostream>
#include<memory>

class Animal{
    std::string name;
    int *code;
    std::unique_ptr<int> num;
public:
    Animal(std::string a,int c):name(a){
        code=new int[c];
        num=std::make_unique<int>();
        *num=c;
        if (*num<0){
            throw std::invalid_argument("out of the range");
        }
        std::cout<<"succeed to make the class Animal"<<std::endl;
    }
    virtual void activate(int n)const{
        std::cout<<n<<"th time to say "<<*num<<" animals is lively"<<std::endl;
    }
    virtual ~Animal(){
        delete[] code;
        std::cout<<"succeed to delete Animal"<<std::endl;
    }
};
class Dog:public Animal{
    int age_;
public:
    Dog(int a,int age):Animal("Dog",a),age_(age){
        if (age>50){
            throw std::invalid_argument("the number is out of the range");
        }
        std::cout<<"succeed to make the class Dog"<<std::endl;
    }
    void activate(int n)const override{
        std::cout<<n<<"th timt to say ,the "<<age_<<" -year-old dog is lively"<<std::endl;
    }
    ~Dog(){
        std::cout<<"succeed to delete Dog"<<std::endl;
    }
};
int main(){
    try{
        //Dog dog=Dog(10,13);
        std::unique_ptr<Dog> dog=std::make_unique<Dog>(3,5);
        dog.get()->activate(4);
        /*void** vtable=*reinterpret_cast<void***>(&dog);
        void (*acptr)(Dog*,int n)=reinterpret_cast<void(*)(Dog*,int n)>(*vtable);
        acptr(&dog,9);*/
    }
    catch (...) {
        std::cerr << "Error: "<< std::endl;
        return 1;
    }
    return 0;
}