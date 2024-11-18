//
// Created by luzehui on 2024/6/8.
//

#include "LeetCode3040.h"

int LeetCode3040::maxOperations(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp1(n, vector<int>(n, -1));
    int res = 0;
    res = max(res, maxOperations(nums, 0, n - 1, dp1, nums[0] + nums[1]));
    vector<vector<int>> dp2(n, vector<int>(n, -1));
    res = max(res, maxOperations(nums, 0, n - 1, dp2, nums[0] + nums[n - 1]));
    vector<vector<int>> dp3(n, vector<int>(n, -1));
    res = max(res, maxOperations(nums, 0, n - 1, dp3, nums[n - 1] + nums[n - 2]));
    return res;
}

int LeetCode3040::maxOperations(vector<int> &nums, int l, int r, vector<vector<int>> &dp, int target) {
    if (l >= r) {
        return 0;
    }
    if (dp[l][r] != -1) {
        return dp[l][r];
    }
    int res = 0;
    if (nums[l] + nums[l + 1] == target)
        res = max(res, 1 + maxOperations(nums, l + 2 ,r, dp, target));
    if (nums[l] + nums[r] == target)
        res = max(res, 1 + maxOperations(nums, l + 1, r, dp, target));
    if (nums[r] + nums[r - 1] == target)
        res = max(res, 1 + maxOperations(nums, l, r - 2, dp , target));
    dp[l][r] = res;
    return res;
}
