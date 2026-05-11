#include <chrono> // NOLINT
#include <iostream>
#include <memory>
#include <string>
#include <utility>
#include <vector>

// 1. 命名：类名和结构体名使用 PascalCase。
// 2. 内存：struct成员变量名使用小写；class成员变量名使用小写加下划线。
struct UniqueNode
{
  int data;
  std::unique_ptr<UniqueNode> left;
  std::unique_ptr<UniqueNode> right;

  explicit UniqueNode(int val)
      : data(val), left(nullptr), right(nullptr) {}
};

// 3. 函数名：使用 PascalCase（Google 对普通函数和方法的命名要求）。
// TODO: 实现 BuildUniqueTree 函数，构建一个使用 unique_ptr 的二叉树。
std::unique_ptr<UniqueNode> BuildUniqueTree(int depth)
{
  if (depth <= 0)
    return nullptr;
  // 4. 使用 std::make_unique (C++14)，符合规范中对所有权明确性的要求。
  auto node = std::make_unique<UniqueNode>(depth);
  node->left = BuildUniqueTree(depth - 1);
  node->right = BuildUniqueTree(depth - 1);
  return node;
}

struct SharedNode
{
  int data;
  std::shared_ptr<SharedNode> left;
  std::shared_ptr<SharedNode> right;

  // 5. 构造函数：单参数构造函数应标记为 explicit，防止隐式转换。
  explicit SharedNode(int val)
      : data(val), left(nullptr), right(nullptr) {}
};

// TODO: 实现 BuildSharedTree 函数，构建一个使用 shared_ptr 的二叉树。
std::shared_ptr<SharedNode> BuildSharedTree(int depth)
{
  if (depth <= 0)
    return nullptr;
  // 6. 优先使用 std::make_shared，能减少一次内存分配（控制块与对象连续分配）。
  auto node = std::make_shared<SharedNode>(depth);
  node->left = BuildSharedTree(depth - 1);
  node->right = BuildSharedTree(depth - 1);
  return node;
}

// TODO: 实现Timer类，利用 RAII 机制，在对象生命周期结束时自动打印耗时。

void test()
{
  std::cout << "=== smart pointer test ===\n"
            << std::endl;
  // 7. 常量命名：以 k 开头，混合大小写。
  const int kDepth = 20;

  std::cout << "---  test begin  ---\n"
            << std::endl;

  {
    auto start = std::chrono::high_resolution_clock::now();
    auto root = BuildUniqueTree(kDepth);
    auto built = std::chrono::high_resolution_clock::now();

    root.reset();
    auto destroyed = std::chrono::high_resolution_clock::now();

    auto duration_build =
        std::chrono::duration_cast<std::chrono::milliseconds>(built - start);
    auto duration_destroy =
        std::chrono::duration_cast<std::chrono::milliseconds>(destroyed - built);

    std::cout << "[unique_ptr] construct: " << duration_build.count() << " ms\n";
    std::cout << "[unique_ptr] destroy  : " << duration_destroy.count() << " ms\n";
  }

  std::cout << "------------------------------------------" << std::endl;

  {
    auto start = std::chrono::high_resolution_clock::now();
    auto root = BuildSharedTree(kDepth);
    auto built = std::chrono::high_resolution_clock::now();

    root.reset();
    auto destroyed = std::chrono::high_resolution_clock::now();

    auto duration_build =
        std::chrono::duration_cast<std::chrono::milliseconds>(built - start);
    auto duration_destroy =
        std::chrono::duration_cast<std::chrono::milliseconds>(destroyed - built);

    std::cout << "[shared_ptr] construct: " << duration_build.count() << " ms\n";
    std::cout << "[shared_ptr] destroy  : " << duration_destroy.count() << " ms\n";
  }
}

int main()
{
  test();
  return 0;
}