#include "bad_buffer.h"
#include "buffer_stage1.h"
#include <iostream>
#include <vector>

// TODO: 实现以下测试函数

void test_bad_copy_constructor()
{
    std::cout << "=== Test BadBuffer: Copy Constructor ===\n";
    // TODO: 创建BadBuffer对象并复制，观察崩溃
    BadBuffer buf1(1024);
    BadBuffer buf2 = buf1;  // 崩溃！
}

void test_bad_copy_assignment()
{
    std::cout << "=== Test BadBuffer: Copy Assignment ===\n";
    // TODO: 创建两个BadBuffer对象并赋值，观察崩溃
    BadBuffer buf1(1024);
    BadBuffer buf2(1024);
    buf2=buf1;
}

void test_bad_vector()
{
    std::cout << "=== Test BadBuffer: Vector Operations ===\n";
    std::vector<BadBuffer> vec;
    BadBuffer buf1(1024);
    vec.push_back(buf1);
}

void test_good_buffer()
{
    std::cout << "\n=== Test GoodBuffer: All Operations ===\n";
    // TODO: 使用GoodBuffer验证问题已修复
    GoodBuffer buf1(1024);
    GoodBuffer buf2 = buf1; // 应该正常工作
    GoodBuffer buf3(512);
    buf3 = buf1; // 应该正常工作

    std::vector<GoodBuffer> vec;
    vec.push_back(GoodBuffer(1024));
    vec.push_back(GoodBuffer(2048));

    std::cout << "All tests passed!\n";
}

int main()
{
    // 注意：BadBuffer的测试会崩溃，请逐个取消注释测试
    //test_bad_copy_constructor();
    //test_bad_copy_assignment();
    // test_bad_vector();

    test_good_buffer();
    return 0;
}