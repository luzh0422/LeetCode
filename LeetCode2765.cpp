//
// Created by luzehui on 2024/1/23.
//

#include "LeetCode2765.h"

int LeetCode2765::alternatingSubarray(vector<int> &nums) {
    int n = nums.size(), ans = 0;
    vector<int> dp(n, 1);
    if (nums[1] == nums[0] + 1) {
        dp[1] = 2;
    }
    ans = dp[1];
    for (int i = 2; i < n; i++) {
        if (abs(nums[i] - nums[i - 1]) == 1 && nums[i] == nums[i - 2]) {
            dp[i] = dp[i - 1] + 1;
        } else if (nums[i] == nums[i - 1] + 1) {
            dp[i] = 2;
        }
        ans = max(ans, dp[i]);
    }
    return ans == 1 ? -1 : ans;
}
