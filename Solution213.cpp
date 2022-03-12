//
// Created by luzh on 2021/4/15.
//

#include "Solution213.h"

/**
 * 难点在于第一间和最后一间不能同时偷窃；
 * @param nums
 * @return
 */
int Solution213::rob(vector<int> &nums) {
    int size = nums.size();
    if (size == 0) {
        return 0;
    } else if (size == 1) {
        return nums[0];
    } else if (size == 2) {
        return max(nums[0], nums[1]);
    }
    /**
     * 要不第0间屋子不偷，要不第size - 1间屋子不偷；
     */
    return max(rob(nums, 0, size - 1), rob(nums, 1, size));
}

int Solution213::rob(vector<int> &nums, int start, int end) {
    vector<vector<int>> dp(end - start, vector<int>(2));
    dp[0][0] = 0;
    dp[0][1] = nums[start];
    for (int i = 1; i < end - start; i++) {
        dp[i][0] = max(dp[i - 1][1], dp[i - 1][0]);
        dp[i][1] = dp[i - 1][0] + nums[start + i];
    }
    return max(dp[end - start - 1][0], dp[end - start - 1][1]);
}


