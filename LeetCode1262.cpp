//
// Created by 陆泽辉 on 2023/6/19.
//

#include "LeetCode1262.h"

int LeetCode1262::maxSumDivThree(vector<int> &nums) {
    int n = nums.size();
    // dp表示前i个数字，除以3，余数为0、1、2时，最大的数；
    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[0][0] = 0;
    dp[0][1] = INT_MIN;
    dp[0][2] = INT_MIN;
    for (int i = 0; i < n; i++) {
        if (nums[i] % 3 == 0) {
            dp[i + 1][0] = dp[i][0] + nums[i];
            dp[i + 1][1] = dp[i][1] + nums[i];
            dp[i + 1][2] = dp[i][2] + nums[i];
        } else if (nums[i] % 3 == 1) {
            dp[i + 1][0] = max(dp[i][0], dp[i][2] + nums[i]);
            dp[i + 1][1] = max(dp[i][1], dp[i][0] + nums[i]);
            dp[i + 1][2] = max(dp[i][2], dp[i][1] + nums[i]);
        } else {
            dp[i + 1][0] = max(dp[i][0], dp[i][1] + nums[i]);
            dp[i + 1][1] = max(dp[i][1], dp[i][2] + nums[i]);
            dp[i + 1][2] = max(dp[i][2], dp[i][0] + nums[i]);
        }
    }
    return dp[n][0];
}
