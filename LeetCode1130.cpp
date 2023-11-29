//
// Created by 陆泽辉 on 2023/5/31.
//

#include "LeetCode1130.h"

// 重点arr是树的中序遍历；
// dp[i][j]是指区间[i, j]的数组构成的树的非叶结点的最小值；
// dp[i][j]可以分为[i, k]的数组作为左子树，[k + 1][j]的数组作为右子树，以及两个子树的非叶结点的最大值相乘作为当前节点。
// dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mval[i][k] * mval[k + 1][j]);
int LeetCode1130::mctFromLeafValues(vector<int> &arr) {
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, INT_MAX / 4));
    vector<vector<int>> mval(n, vector<int>(n));
    for (int j = 0; j < n; j++) {
        mval[j][j] = arr[j];
        dp[j][j] = 0; // 此时只有一个节点，没有非叶子节点。
        for (int i = j - 1; i >= 0; i--) { // 区间动态规划问题，要从小区间开始计算。
            mval[i][j] = max(arr[i], mval[i + 1][j]); // 区间[i, j]的最大值；
            for (int k = i; k < j; k++) {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + mval[i][k] * mval[k + 1][j]); // 区间[i, j]非叶节点的最小值；
            }
        }
    }
    return dp[0][n - 1];
}
