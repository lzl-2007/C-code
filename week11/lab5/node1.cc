#include <chrono>
#include <iostream>
#include <memory>
#include <string>

// Fixed: Use consistent naming and handle negative depth
struct UniqueNode {
    int data;
    std::unique_ptr<UniqueNode> left;
    std::unique_ptr<UniqueNode> right;

    explicit UniqueNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

std::unique_ptr<UniqueNode> BuildUniqueTree(int depth) {
    if (depth <= 0) {
        return nullptr;
    }
    auto node = std::make_unique<UniqueNode>(depth);
    node->left = BuildUniqueTree(depth - 1);
    node->right = BuildUniqueTree(depth - 1);
    return node;
}

struct SharedNode {
    int data;
    std::shared_ptr<SharedNode> left;
    std::shared_ptr<SharedNode> right;

    explicit SharedNode(int val) : data(val), left(nullptr), right(nullptr) {}
};

std::shared_ptr<SharedNode> BuildSharedTree(int depth) {
    if (depth <= 0) {
        return nullptr;
    }
    auto node = std::make_shared<SharedNode>(depth);
    node->left = BuildSharedTree(depth - 1);
    node->right = BuildSharedTree(depth - 1);
    return node;
}

// Improved Timer class
class Timer {
private:
    std::string str_;
    std::chrono::time_point<std::chrono::high_resolution_clock> start_;

public:
    explicit Timer(const std::string& str)
        : str_(str), start_(std::chrono::high_resolution_clock::now()) {}

    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start_);
        std::cout << str_ << duration.count() << " ms\n";
    }
};

void RunSmartPointerTest() {
    const int kDepth = 20;
    std::cout << "--- Smart Pointer Performance Test ---\n\n";

    // Unique pointer test
    {
        std::unique_ptr<UniqueNode> root;
        {
            Timer t("[unique_ptr] construct: ");
            root = BuildUniqueTree(kDepth);
        }
        {
            Timer t("[unique_ptr] destroy:   ");
            root.reset();
        }
    }

    std::cout << "\n------------------------------------------\n\n";

    // Shared pointer test
    {
        std::shared_ptr<SharedNode> root;
        {
            Timer t("[shared_ptr] construct: ");
            root = BuildSharedTree(kDepth);
        }
        {
            Timer t("[shared_ptr] destroy:   ");
            root.reset();
        }
    }
}

int main() {
    RunSmartPointerTest();
    return 0;
}