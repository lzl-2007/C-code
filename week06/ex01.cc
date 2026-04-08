#include<iostream>

struct Mystery1{
    char a;
    double b;
    int c;
    char d;
};

struct Mystery2{
    double b;
    int c;
    char a;
    char d;
};

int main(){
    std::cout<<"sizeof Mystery1="<<sizeof(Mystery1)<<std::endl;
    std::cout<<"sizeof Mystery2="<<sizeof(Mystery2)<<std::endl;
    std::cout<<"offset of Mystery1 a:"<<offsetof(Mystery1,a)<<std::endl;
    std::cout<<"offset of Mystery1 b:"<<offsetof(Mystery1,b)<<std::endl;
    std::cout<<"offset of Mystery1 c:"<<offsetof(Mystery1,c)<<std::endl;
    std::cout<<"offset of Mystery1 d:"<<offsetof(Mystery1,d)<<std::endl;
    std::cout<<"offset of Mystery2 b:"<<offsetof(Mystery2,b)<<std::endl;
    std::cout<<"offset of Mystery2 c:"<<offsetof(Mystery2,c)<<std::endl;
    std::cout<<"offset of Mystery2 a:"<<offsetof(Mystery2,a)<<std::endl;
    std::cout<<"offset of Mystery2 d:"<<offsetof(Mystery2,d)<<std::endl;
    return 0;
}
/*输出：
sizeof Mystery1=24
sizeof Mystery2=16
offset of Mystery1 a:0
offset of Mystery1 b:8
offset of Mystery1 c:16
offset of Mystery1 d:20
offset of Mystery2 b:0
offset of Mystery2 c:8
offset of Mystery2 a:12
offset of Mystery2 d:13
*/