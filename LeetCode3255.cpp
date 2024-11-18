//
// Created by luzehui on 2024/11/7.
//

#include "LeetCode3255.h"

vector<int> LeetCode3255::resultsArray(vector<int> &nums, int k) {
    int n = nums.size();
    vector<int> dp(n, 1);
    vector<int> res(n - k + 1, -1);
    if (n == 1 && k == 1) {
        res[0] = nums[0];
    }
    for (int i = 1; i < n; i++) {
        if (nums[i] == nums[i - 1] + 1) {
            dp[i] = dp[i - 1] + 1;
        }
        if (i >= k - 1 && dp[i] >= k) {
            res[i - k + 1] = nums[i];
        }
    }
    return res;
}
