#include<iostream>
#include<cstring>
class Buffer{

    char* data_;
    size_t size_;
public:
    explicit Buffer(size_t size):data_(new char[size]),size_(size){} //explicit拒绝隐式转换    默认构造函数
    Buffer(const Buffer & other):size_(other.size_),data_(new char[size_]){   //这是复制构造函数
        std::memcpy(data_,other.data_,size_);
    }
    friend void swap(Buffer &a,Buffer &b)noexcept{      //swap-and-copy实现复制赋值，拒绝抛出异常
        std::swap(a.data_,b.data_);
        std::swap(a.size_,b.size_);
    }
    Buffer operator=(const Buffer &other){//operateor进行运算符"="重载
        Buffer tem(other);      //为了保护原本两个对象安全创建临时对象，通过已有的复制构造创建临时对象，所以可能出现异常的过程都让临时对象承担
        swap(*this,tem);       
        return *this; 
    }
    Buffer(Buffer &&other):
        size_(other.size_),data_(other.data_){
            other.data_=nullptr;   //必须将源对象置空，否则两个对象含有的指针可能指向同一块内存，析构时双重释放
            other.size_=0;
        }
    Buffer operator=(Buffer &&other)noexcept{  //移动赋值函数
        if (this==&other){
            return *this;           //防止自赋值导致自己的资源先被释放
        }
        delete[] data_;
        data_=other.data_;
        size_=other.size_;
        other.data_=nullptr;
        other.size_=0;
        return *this;
    }
    ~Buffer(){
        delete[] data_;
        std::cout<<"delete!"<<std::endl;
    }
};
