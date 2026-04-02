#include<iostream>
class Stock{
private:
    std::string company;
    int num;
public:
    Stock(std::string s,int x):company(s),num(x){};

    void print() const{
        std::cout<<num;
    }
    double total()const{return num;}
    const Stock & topval(const Stock & s) const{
        if (s.num>num) return s;
        else return *this;
    }
    ~Stock(){
        std::cout<<"bye";
    }
} ;


int main(){
    std::string str;
    getline(std::cin,str);
    int y;
    std::cin>>y;
    Stock stock1(str,y);
    stock1.print();
    Stock stock2("axda da",323);
    const Stock & top=stock1.topval(stock2);
    top.print();
    return 0;
}