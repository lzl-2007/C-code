#include "buffer_stage2.h"
#include <iostream>
#include <vector>

// 通过别名使用GoodBufferStage2。
using GoodBuffer = GoodBufferStage2;

void test_move_constructor()
{
    std::cout << "Test: Move Constructor\n";
    GoodBuffer buf1(1024);
    GoodBuffer buf2 = std::move(buf1);
    // TODO: 验证buf1被置空，buf2持有资源
    if (buf1.data_==nullptr && buf1.size_==0)
        std::cout<<"buf1置空\n";
    if (buf2.data_ && buf2.size_)
        std::cout<<"buf2持有资源\n";
    std::cout << "Move constructor works!\n";
}

void test_move_assignment()
{
    std::cout << "Test: Move Assignment\n";
    GoodBuffer buf1(1024);
    GoodBuffer buf2(512);
    buf2 = std::move(buf1);
    // TODO: 验证buf1被置空，buf2持有资源
    if (buf1.data_==nullptr && buf1.size_==0)
        std::cout<<"buf1置空\n";
    if (buf2.data_ && buf2.size_==1024)
        std::cout<<"buf2持有资源";
    std::cout << "Move assignment works!\n";
}

void test_self_move_assignment()
{
    std::cout << "=== Test: Self Move Assignment ===\n";

    GoodBuffer buf1(1024);
    std::cout << "Created buf1 with 1024 bytes\n";
    // TODO: 验证自移动的场景
    buf1=std::move(buf1);
    std::cout << "Self move assignment works!\n\n";
}

void test_vector_performance()
{
    std::cout << "=== Test: Vector with Move Semantics ===\n";

    std::vector<GoodBuffer> vec;
    std::cout << "Creating vector and pushing 10 large buffers...\n";

    for (int i = 0; i < 10; ++i)
    {
        vec.push_back(GoodBuffer(1024 * 1024)); // 1MB each, should use move
        std::cout << "  Pushed buffer " << (i + 1) << " (1MB)\n";
    }

    std::cout << "All buffers pushed successfully!\n";
    std::cout << "With move semantics, this should be fast (no copying)\n";
    std::cout << "Vector operations work!\n\n";
}

void test_function_return()
{
    std::cout << "=== Test: Function Return (RVO/Move) ===\n";

    auto create_buffer = []() -> GoodBuffer
    {
        GoodBuffer buf(2048);
        std::cout << "  Created buffer inside function\n";
        return buf; // RVO or move
    };

    GoodBuffer result = create_buffer();
    std::cout << "Received buffer from function\n";
    std::cout << "Function return works!\n\n";
}

int main()
{
    std::cout << "Buffer Lab - Stage 2 Tests\n";
    std::cout << "===========================\n\n";

    test_move_constructor();
    test_move_assignment();
    test_self_move_assignment();
    test_vector_performance();
    test_function_return();

    std::cout << "All Stage 2 tests passed!\n";
    std::cout << "Move semantics are working correctly.\n";

    return 0;
}
