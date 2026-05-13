#include <chrono> // NOLINT
#include <iostream>
#include <memory>
#include <string>
#include <utility>

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
// Builds a binary tree of unique_ptr nodes (recursive).
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

// Builds a binary tree of shared_ptr nodes (recursive).
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

class Timer
{
 public:
  explicit Timer(std::string label_prefix)
      : label_prefix_(std::move(label_prefix)),
        start_(std::chrono::high_resolution_clock::now()) {}

  ~Timer()
  {
    const auto end = std::chrono::high_resolution_clock::now();
    const auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(
        end - start_);
    std::cout << label_prefix_ << duration.count() << " ms\n";
  }

  Timer(const Timer&) = delete;
  Timer& operator=(const Timer&) = delete;

 private:
  std::string label_prefix_;
  std::chrono::high_resolution_clock::time_point start_;
};

void test()
{
  std::cout << "=== smart pointer test ===\n"
            << std::endl;
  // 7. 常量命名：以 k 开头，混合大小写。
  const int kDepth = 20;

  std::cout << "---  test begin  ---\n"
            << std::endl;

  {
    std::unique_ptr<UniqueNode> root;
    {
      Timer construct_timer("[unique_ptr] construct: ");
      root = BuildUniqueTree(kDepth);
    }
    {
      Timer destroy_timer("[unique_ptr] destroy  : ");
      root.reset();
    }
  }

  std::cout << "------------------------------------------" << std::endl;

  {
    std::shared_ptr<SharedNode> root;
    {
      Timer construct_timer("[shared_ptr] construct: ");
      root = BuildSharedTree(kDepth);
    }
    {
      Timer destroy_timer("[shared_ptr] destroy  : ");
      root.reset();
    }
  }
}

int main()
{
  test();
  return 0;
}