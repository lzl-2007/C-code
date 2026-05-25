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
  if (depth<=0){
    return nullptr;
  }
  std::unique_ptr<UniqueNode> node=std::make_unique<UniqueNode>(depth);
  node->left=BuildUniqueTree(depth-1);
  node->right=BuildUniqueTree(depth-1);
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
  if (depth<=0){
    return nullptr;
  }
  auto node=std::make_shared<SharedNode>(depth);
  node->left=BuildSharedTree(depth-1);
  node->right=BuildSharedTree(depth-1);
  return node;
}

// TODO: 实现Timer类，利用 RAII 机制，在对象生命周期结束时自动打印耗时。
class Timer{
private:
  std::string str_;
  std::chrono::time_point<std::chrono::high_resolution_clock> start_;
public:
Timer(std::string str):str_(str),start_(std::chrono::high_resolution_clock::now()){
}
~Timer(){
  auto nowtime = std::chrono::high_resolution_clock::now();
  auto duration =
        std::chrono::duration_cast<std::chrono::milliseconds>(nowtime - start_);
  std::cout <<str_ <<  duration.count() << " ms\n";
}

};
void test_with_timer()
{
  const int kDepth = 25;
  std::cout << "---  test begin  ---\n" << std::endl;

  {
    std::unique_ptr<UniqueNode> root;
    {
      Timer t("unique_ptr construct ");
      root = BuildUniqueTree(kDepth);
    } // Timer 销毁，输出构建时间

    {
      Timer t("unique_ptr destroy  ");
      root.reset();
    } // Timer 销毁，输出销毁时间
  }

  std::cout << "\n------------------------------------------\n";

  {
    std::shared_ptr<SharedNode> root;
    {
      Timer t("shared_ptr construct");
      root = BuildSharedTree(kDepth);
    }

    {
      Timer t("shared_ptr destroy  ");
      root.reset();
    }
  }
}
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
  test_with_timer();
  return 0;
}
/*
输出解释：
释放比构建所花的时间更长，因为堆的释放比构建有更高的开销（销毁时面对的地址更加碎片化）
shared_ptr比unique_ptr所花的时间更长，因为shared_ptr需要分配内存给节点本身和控制块，而unique_ptr只要分配给节点本身，所以运行更快。
*/
/*
kdepth=20的输出：
---  test begin  ---
unique_ptr construct 511 ms
unique_ptr destroy  21506 ms                                                                                                     
------------------------------------------                                                                       
shared_ptr construct2959 ms                                                                                      
shared_ptr destroy  62553 ms  
*/
/*
kdepth=24的输出：
---  test begin  ---
unique_ptr construct 7952 ms
unique_ptr destroy  225232 ms                                                                                                                                                                                  
------------------------------------------                                                                       
shared_ptr construct17311 ms                                                                                     
shared_ptr destroy  1103462 ms     
*/
/*
kdepth=25的输出：
 ---  test begin  ---                                                                                                         
unique_ptr construct 15308 ms                                                                                    
unique_ptr destroy  479810 ms                                                                                                                                                                                         
------------------------------------------                                                                       
shared_ptr construct100314 ms                                                                                    
shared_ptr destroy  2980164 ms 
*/
/*
kdepth=26的运行时间过长，难以完整运行。。
*/
/*
随着深度变大所花时间大概呈现2的指数增加
*/
/*
review.md提出的错误已在两个代码中同时修改
*/