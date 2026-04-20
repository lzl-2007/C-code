#include "grid.h"

#include <array>
#include <cctype>
#include <iostream>

static size_t maxGridLine(Grid const &grid) {
    size_t ret{0};
    for (auto const &line : grid)
        ret = std::max(ret, line.size());
    return ret + 2;
}

inline bool isSymbol(char c) { return (c != '.' && !isdigit(c)); }//较小的简单函数可以inline成为内联代码减小开销
//判定是不是能让周围数值有效的符号
bool isSymbolAdjacent(char c, size_t i, size_t j, Grid const &grid) {  //这个函数用来判定数值本身是否有效
    std::array<std::pair<int, int>, 8> positions{              //pair进行简单的打包
        {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}}};
    for (const auto [delta_i, delta_j] : positions) {
        auto c = grid[i + delta_i][j + delta_j];
        if (isSymbol(c)) {
            return true;
        }
    }

    return false;
}

Grid readGrid(std::istream &in) {
    Grid grid;
    std::string line;
    while (std::getline(in, line)) {
        if (line.size() == 0)
            break;
        grid.push_back(line);
    }
    return grid;
}

Grid frameGrid(Grid const &grid, char SEP) {//构造一个新的易于处理的grid
    Grid framed;
    auto max = maxGridLine(grid);          //取出行中的最大元素个数加2作为新grid的边长

    framed.push_back(std::string(max, SEP));    //第一行填充满占位符
    for (auto const &line : grid) {
        std::string new_line =
            '.' + line + std::string(max - 2 - line.size(), '.') + '.';//中间的行开始一个占位符，加上原本字符，不足的继续占位
        framed.push_back(new_line);
    }
    framed.push_back(std::string(max, SEP));//最后一行也占满

    return framed;//这是一个处理过的grid
}

// todo: implement two functions:
void print(std::ostream &out, Grid const &grid){
    for (auto line : grid){
        for (auto a : line){
            out<<a<<' ';
        }
        out<<std::endl;
    }
}
std::vector<unsigned> findEffectiveNumber(Grid const &grid,std::ostream &out){
    std::vector<unsigned> numbers;
    out<<"有效数字有："<<'\n';
    int interval=0;//为了输出美观
    for (int i = 1;i<grid.size()-1;i++){
        std::string line=grid[i];
        std::string strnum="";
        bool judge=0;
        for (int j=1;j<line.size()-1;j++){
            char str=line[j];
            if (str>='0' && str<='9'){
                strnum.push_back(str);
                if (isSymbolAdjacent(str, i, j, grid))
                    judge=1;
            }
            else{
                if (strnum.size()){
                    if(judge==1){
                        numbers.push_back(std::stoi(strnum));
                        out<<strnum<<"  ";
                        interval++;
                        if (interval%15==0)out<<'\n';
                        judge=0;
                        strnum="";
                    }
                    else strnum="";

                }
            }
            
        }
        if (strnum.size()){              //末端处理，如果数字在最后
            if(judge==1){
                numbers.push_back(std::stoi(strnum));
                out<<strnum<<"  ";
                interval++;
                if (interval%15==0)out<<'\n';
                judge=0;
                strnum="";
            }
            else strnum="";
        }
    }
    out<<'\n';
    return numbers;
}
/*
input1的输出:
. . . . . . . . . . . . 
. 4 6 7 . . 1 1 4 . . .
. . . . * . . . . . . .
. . . 3 5 . . 6 3 3 . .
. . . . . . . # . . . .
. 6 1 7 * . . . . . . .
. . . . . . + . 5 8 . .
. . . 5 9 2 . . . . . .
. . . . . . . 7 5 5 . .
. . . . $ . * . . . . .
. . 6 6 4 . 5 9 8 . . .
. . . . . . . . . . . .
有效数字有：
467  35  633  617  592  755  664  598
numbers size: 8 total: 4361
*/
//input2的输出请见output.txt，从上到下的输出分别是：需要求和的有效数字列举，最终求和数字数量和求和结果,grid的print结果按要求省略