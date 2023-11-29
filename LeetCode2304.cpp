//
// Created by luzehui on 2023/11/22.
//

#include "LeetCode2304.h"

int LeetCode2304::minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
    int m = grid.size(), n = grid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, 0x3f3f3f3f));
    for (int i = 0; i < n; i++) {
        dp[0][i] = grid[0][i];
    }
    for (int i = 1; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dp[i][j] = min(dp[i][j], dp[i - 1][k] + moveCost[grid[i - 1][k]][j]);
            }
            dp[i][j] += grid[i][j];
        }
    }
    int res = 0x3f3f3f3f;
    for (int i = 0; i < n; i++) {
        res = min(res, dp[m - 1][i]);
    }
    return res;
}
