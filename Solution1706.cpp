//
// Created by luzh on 2022/2/24.
//

#include "Solution1706.h"
#include <stack>

vector<int> Solution1706::findBall(vector<vector<int>> &grid) {
    vector<int> ret = {};
    int m = grid.size();
    int n = grid[0].size();
    stack<pair<int, int>> stk;
    for (int i = n - 1; i >= 0; i--) {
        stk.push({0, i});
    }
    while (!stk.empty()) {
        auto point = stk.top();
        stk.pop();
        int row = point.first;
        int column = point.second;
        if (row == m) {
            ret.push_back(column);
        } else {
            if (grid[row][column] == 1) {
                if (column == n - 1 || grid[row][column + 1] == -1) {
                    ret.push_back(-1);
                } else {
                    stk.push({row + 1, column + 1});
                }
            } else if (grid[row][column] == -1) {
                if (column == 0 || grid[row][column - 1] == 1) {
                    ret.push_back(-1);
                } else {
                    stk.push({row + 1, column - 1});
                }
            }
        }

    }
    return ret;
}
