#include<iostream>
class Bankaccount{
private:
    std::string name;
    double balance;
public:
    Bankaccount(std::string a,double b):name(a),balance(b){}
    void show()const{
        std::cout<<name<<"  "<<balance<<std::endl;
    }
};
int main(){
    auto Lzlp=new Bankaccount("lzl",5201314);
    Lzlp->show();
    auto p=reinterpret_cast<std::string*>(Lzlp);
    std::cout<<*p;
    return 0;
}