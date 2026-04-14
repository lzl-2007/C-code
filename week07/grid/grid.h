#pragma once         //防止头文件被重复包含

#include <string>
#include <vector>

using Grid = std::vector<std::string>;  //给类型创建别名

Grid readGrid(std::istream &in);
Grid frameGrid(Grid const &, char SEP = '.');
// todo: to complete
void print(std::ostream &out, Grid const &grid);     //代指各种流
std::vector<unsigned> findEffectiveNumber(Grid const &grid,std::ostream &out);
