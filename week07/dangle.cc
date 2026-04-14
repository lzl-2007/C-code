#include<iostream>

int *dangling(){
    int *x=new int(42);  //改成在堆上分配内存
    return x;
}
void f(){
    int *p=dangling();
    std::cout<<*p<<std::endl;
    //delete p;
}
int main(){
    f();
    return 0;
}
//直接运行的输出:Segmentation fault(其实是直接报错)
//有时能跑最危险，因为如果在调试时碰巧输出了正确值，在真正使用时会出现意外的程序泄露崩溃等问题
