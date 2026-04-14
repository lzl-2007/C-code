#include "grid.h"

#include <fstream>
#include <iostream>
#include <numeric>

int main() {
    std::ifstream in{"input2.txt"};

    auto grid = readGrid(in);
    grid = frameGrid(grid);

    
    std::ofstream file{"output.txt"};
    //print(file, grid);
    auto numbers = findEffectiveNumber(grid,file);
    auto  total = std::accumulate(numbers.begin(), numbers.end(), 0);
    file << "numbers size: " << numbers.size() << " total: " << total
              << '\n';
}