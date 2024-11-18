//
// Created by luzehui on 2024/9/6.
//

#include "LeetCode3176.h"

int LeetCode3176::maximumLength(vector<int> &nums, int k) {
    int n = nums.size(), ans = 0;
    vector<vector<int>> dp(n, vector<int>(k + 1, 0));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            for (int z = 0; z < i; z++) {
                if (nums[i] == nums[z]) {
                    dp[i][j] = max(dp[i][j], dp[z][j]);
                } else if (j) {
                    dp[i][j] = max(dp[i][j], dp[z][j - 1]);
                }
            }
            ++dp[i][j];
        }
        ans = max(ans, dp[i][k]);
    }
    return ans;
}
