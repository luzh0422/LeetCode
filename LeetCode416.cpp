//
// Created by luzehui on 25-4-7.
//

#include "LeetCode416.h"

bool LeetCode416::canPartition(vector<int> &nums) {
    int n = nums.size();
    if (n < 2) {
        return false;
    }
    int sum = 0;
    int maxNum = 0;
    for (auto num: nums) {
        sum += num;
        maxNum = max(maxNum, num);
    }
    if (sum & 1) {
        return false;
    }
    int target = sum / 2;
    if (maxNum > target) {
        return false;
    }
    /**
     * 前i个数字是否可以恰好构成Target；
     */
    vector<vector<int>> dp(n, vector<int>(target + 1, 0));
    for (int i = 0; i < n; i++) {
        dp[i][0] = true;
    }
    dp[0][nums[0]] = true;
    for (int i = 1; i < n; i++) {
        int num = nums[i];
        for (int j = 1; j <= target; j++) {
            if (j >= num) {
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - num]; // dp[i][j] = 不取nums[i]构成target-j | 取nums[i]构成target-j；
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[n - 1][target];
}
