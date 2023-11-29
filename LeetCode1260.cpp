//
// Created by 陆泽辉 on 2022/7/20.
//

#include "LeetCode1260.h"

vector<vector<int>> LeetCode1260::shiftGrid(vector<vector<int>> &grid, int k) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> ret(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int currPos = i * n + j;
            int nextPos = currPos + k;
            nextPos %= m * n;
            int nextRow = nextPos / n;
            int nextCol = nextPos % n;
            ret[nextRow][nextCol] = grid[i][j];
        }
    }
    return ret;
}
