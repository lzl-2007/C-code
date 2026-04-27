#pragma once

#include <cstddef>

class BadBuffer
{
public:
    BadBuffer(size_t size) : size_(size), data_(new char[size]{}) {}
    ~BadBuffer() { delete[] data_; }

private:
    size_t size_;
    char *data_;
};
