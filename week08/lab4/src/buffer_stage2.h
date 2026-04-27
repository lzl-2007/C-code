#pragma once
#include <cstddef>
#include <cstring>
#include <utility>

class GoodBufferStage2
{ // 或者使用 GoodBuffer 作为最终版本
public:
    GoodBufferStage2(size_t size) : size_(size), data_(new char[size]{}) {}

    ~GoodBufferStage2()
    {
        delete[] data_;
    }

    // 复制构造和复制赋值（从阶段1复制过来）
    GoodBufferStage2(const GoodBufferStage2 &other):size_(other.size_),data_(new char[size_]{})
    {
        std::memcpy(data_,other.data_,size_);
    }

    friend void swap(GoodBufferStage2 &a,GoodBufferStage2 &b) noexcept{
        std::swap(a.size_,b.size_);
        std::swap(a.data_,b.data_);
    }
    // TODO: 实现复制赋值操作符
    GoodBufferStage2 &operator=(const GoodBufferStage2 &other)
    {
        GoodBufferStage2 tem(other);
        swap(tem,*this);
        return *this;
    }

    // TODO: 实现移动构造函数
    GoodBufferStage2(GoodBufferStage2 &&other) noexcept
    :size_(other.size_),data_(other.data_)
    {
        // 你的代码：转移资源，置空源对象
        other.size_=0;
        other.data_=nullptr;
    }

    // TODO: 实现移动赋值操作符
    GoodBufferStage2 &operator=(GoodBufferStage2 &&other) noexcept
    {
        // 你的代码：处理自赋值，释放旧资源，转移新资源
        if (&other==this){
            return *this;
        }
        delete[] data_;
        size_=other.size_;
        data_=other.data_;
        other.size_=0;
        other.data_=nullptr;
        return *this;
    }
    friend void test_move_assignment();
    friend void test_move_constructor();
private:
    size_t size_;
    char *data_;
};