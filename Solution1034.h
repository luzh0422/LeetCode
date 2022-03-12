//
// Created by luzh on 2021/12/7.
//

#ifndef LEETCODE_SOLUTION1034_H
#define LEETCODE_SOLUTION1034_H

#include <vector>

using namespace std;

class Solution1034 {
public:
    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color);

private:
    void backtrack(vector<vector<int>>& grid, vector<vector<int>>& visit, vector<pair<int, int>>& positions, pair<int, int> curr);
};


#endif //LEETCODE_SOLUTION1034_H
