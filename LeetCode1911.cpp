//
// Created by 陆泽辉 on 2023/7/11.
//

#include "LeetCode1911.h"

long long LeetCode1911::maxAlternatingSum(vector<int> &nums) {
    int n = nums.size();
    /**
     * dp[i][0]: 当前的数在子序列中的偶数位存在，最大子序列值；
     * dp[i][1]: 当前的数在子序列中的奇数位存在，最大子序列值；
     */
    vector<vector<long long>> dp(n, vector<long long>(2, 0));
    dp[0][1] = nums[0];
    for (int i = 1; i < n; i++) {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] - nums[i]);
        dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] + nums[i]);
    }
    return max(dp[n - 1][0], dp[n - 1][1]);
}
