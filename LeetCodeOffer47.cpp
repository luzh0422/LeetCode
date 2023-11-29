//
// Created by 陆泽辉 on 2023/3/8.
//

#include "LeetCodeOffer47.h"

int LeetCodeOffer47::maxValue(vector<vector<int>> &grid) {
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> visits(n, vector<int>(m, -1));
    return backtrack(grid, visits, 0, 0, n, m);
}

int LeetCodeOffer47::backtrack(vector<vector<int>> &grid, vector<vector<int>>& visits, int currRow, int currCol, int n, int m) {
    if (visits[currRow][currCol] != -1) {
        return visits[currRow][currCol];
    }
    int curr = grid[currRow][currCol];
    if (currRow == n - 1 && currCol == m - 1) {
        return curr;
    }
    int rightVal = 0, downVal = 0;
    if (currRow < n - 1) {
        downVal = backtrack(grid, visits, currRow + 1, currCol, n, m);
    }
    if (currCol < m - 1) {
        rightVal = backtrack(grid, visits, currRow, currCol + 1, n, m);
    }
    visits[currRow][currCol] = curr + max(rightVal, downVal);
    return curr + max(rightVal, downVal);
}
