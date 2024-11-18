//
// Created by luzehui on 2024/11/9.
//

#ifndef LEETCODE_LEETCODE3242_H
#define LEETCODE_LEETCODE3242_H

#include <vector>
#include <unordered_map>

using namespace std;

class NeighborSum {
public:
    NeighborSum(vector<vector<int>>& grid);

    int adjacentSum(int value);

    int diagonalSum(int value);

private:
    unordered_map<int, int> records;
    vector<vector<int>> mGrid;
    int m = 0, n = 0;
};


#endif //LEETCODE_LEETCODE3242_H
