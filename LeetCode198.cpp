//
// Created by 陆泽辉 on 2023/9/16.
//

#include "LeetCode198.h"

int LeetCode198::rob(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    /**
     * init；
     */
    dp[0][0] = 0;
    dp[0][1] = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        dp[i][1] = dp[i - 1][0] + nums[i];
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}
