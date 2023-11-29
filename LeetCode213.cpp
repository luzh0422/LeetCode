//
// Created by 陆泽辉 on 2023/9/17.
//

#include "LeetCode213.h"

int LeetCode213::rob(vector<int> &nums) {
    int n = nums.size();
    if (n == 0) {
        return 0;
    } else if (n == 1) {
        return nums[0];
    } else if (n == 2) {
        return max(nums[0], nums[1]);
    }
    return max(rob(nums, 0, n - 1), rob(nums, 1, n));
}

int LeetCode213::rob(vector<int> &nums, int start, int end) {
    vector<vector<int>> dp(end - start, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = nums[start];
    for (int i = 1; i < end - start; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        dp[i][1] = dp[i - 1][0] + nums[start + i];
    }
    return max(dp[end - start - 1][0], dp[end - start - 1][1]);
}
