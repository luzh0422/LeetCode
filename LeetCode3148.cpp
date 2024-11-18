//
// Created by luzehui on 2024/8/15.
//

#include "LeetCode3148.h"

int LeetCode3148::maxScore(vector<vector<int>> &grid) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> minNums(m, vector<int>(n, INT_MAX));
    minNums[0][0] = grid[0][0];
    int ans = INT_MIN;
    for (int i = 1; i < m; i++) {
        ans = max(ans, grid[i][0] - minNums[i - 1][0]);
        minNums[i][0] = min(minNums[i - 1][0], grid[i][0]);
    }
    for (int i = 1; i < n; i++) {
        ans = max(ans, grid[0][i] - minNums[0][i - 1]);
        minNums[0][i] = min(minNums[0][i - 1], grid[0][i]);
    }
    for (int i = 1; i < m; i++) {
        for (int j = 1; j < n; j++) {
            minNums[i][j] = min(minNums[i - 1][j], minNums[i][ j - 1]);
            ans = max(ans, grid[i][j] - minNums[i][j]);
            minNums[i][j] = min(minNums[i][j], grid[i][j]);
        }
    }
    return ans;
}
