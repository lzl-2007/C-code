#include<iostream>
#include<cstring>
class Buffer{
public:
    char* data_;
    size_t size_;
    explicit Buffer(size_t size):data_(new char[size]),size_(size){} //explicit拒绝隐式转换    默认构造函数
    Buffer(const Buffer & other):size_(other.size_),data_(new char[size_]){
        std::memcpy(data_,other.data_,size_);
    }
    ~Buffer(){
        delete[] data_;
        std::cout<<"delete!"<<std::endl;
    }
};

int main(){
    Buffer a(1024);
    //Buffer b=a;      //直接复制是浅复制，只复制指针不复制指向的数据
    
   
    std::cout<<a.size_;
    return 0;
}
