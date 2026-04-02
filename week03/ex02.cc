#include<iostream>
using namespace std;
class bankcount{
private:
    string name;
    double balance;
public:
    bankcount(double a,string b):balance(a),name(b){}
    
    void create(double a,string b){
        name=b;
        balance=a;
    }
    virtual void print(){
        cout<<name<<' '<<balance<<endl;
    }
};

class littlecount :public bankcount{
public:
    littlecount(double a,string b):bankcount(a,b){};
    void print(){
        cout<<"szscf"<<endl;
    }
};
void doprint(bankcount a){
    a.print();
}
int main(){
    bankcount a(235.56,"dscx");
    littlecount b(345.76,"hhygf");
    doprint(a);
    doprint(b);
    return 0;
}