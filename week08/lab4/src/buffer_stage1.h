#pragma once
#include <cstddef>
#include <cstring>
#include <utility>  
class GoodBuffer
{
public:
    GoodBuffer(size_t size) : size_(size), data_(new char[size]{}) {}

    ~GoodBuffer()
    {
        delete[] data_;
    }

    // TODO: 实现复制构造函数
    GoodBuffer(const GoodBuffer &other):size_(other.size_),data_(new char[size_]{})
    {
        std::memcpy(data_,other.data_,size_);
    }
    friend void swap(GoodBuffer &a,GoodBuffer &b) noexcept{
        std::swap(a.size_,b.size_);
        std::swap(a.data_,b.data_);
    }
    // TODO: 实现复制赋值操作符
    GoodBuffer &operator=(const GoodBuffer &other)
    {
        GoodBuffer tem(other);
        swap(tem,*this);
        return *this;
    }

private:
    size_t size_;
    char *data_;
};