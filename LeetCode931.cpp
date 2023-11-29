//
// Created by 陆泽辉 on 2023/7/13.
//

#include "LeetCode931.h"

int LeetCode931::minFallingPathSum(vector<vector<int>> &matrix) {
    int res = 0x3f3f3f3f;
    int n = matrix.size();
    vector<vector<int>> dp(n, vector<int>(n, res));
    for (int i = 0; i < n; i++) {
        for (int j = -1; j <= 1; j++) {
            res = min(res, matrix[0][i] + dfs(1, i + j, matrix, dp));
        }
    }
    return res;
}

int LeetCode931::dfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp) {
    int n = matrix.size();
    if (col < 0 || col >= n) {
        return 0x3f3f3f3f;
    }
    if (row == n - 1) {
        return matrix[row][col];
    }
    if (dp[row][col] < 0x3f3f3f3f) {
        return dp[row][col];
    }
    int res = 0x3f3f3f3f;
    for (int i = -1; i <= 1; i++) {
        res = min(res, matrix[row][col] + dfs(row + 1, col + i, matrix, dp));
    }
    dp[row][col] = res;
    return res;
}
