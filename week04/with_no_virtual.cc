#include<iostream>
#include<cstddef>
struct NoVirtual{
    int x,y,z;
};

struct WithVirtual{
    virtual void foo(){
        std::cout<<"[foo] Called! x is:"<<x<<std::endl;
        }
    virtual void bar(int val){
        std::cout<<"[bar] Called with val:"<<val<<"  y is:"<<y<<std::endl;
        }
    int x,y,z;
};
int main(){
    std::cout<<"sizeof Novirtual:"<<sizeof(NoVirtual)<<std::endl;
    std::cout<<"sizeof withvirtual:"<<sizeof(WithVirtual)<<std::endl;
    NoVirtual object1;
    WithVirtual object2;
    object2.x=0;
    object2.y=0;
    std::cout<<"object size:"<<sizeof(object2)<<std::endl;
    void **vtable=*reinterpret_cast<void***>(&object2);
    void (*fooptr)(WithVirtual*)=reinterpret_cast<void(*)(WithVirtual*)>(vtable[0]);
    void (*barptr)(WithVirtual*,int)=reinterpret_cast<void(*)(WithVirtual*,int)>(vtable[1]);
    std::cout<<"calling foo via vtable:";
    fooptr(&object2);
    std::cout<<"calling bar via vtable:";
    barptr(&object2,8); 
    std::cout<<"Offset of x:"<<offsetof(WithVirtual,x);
    return 0;
}