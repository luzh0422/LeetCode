//
// Created by luzehui on 2024/6/14.
//

#include "LeetCode2786.h"

long long LeetCode2786::maxScore(vector<int> &nums, int x) {
    int n = nums.size();
    vector<long long> dp(n, INT_MIN);
    long long res = nums[0];
    dp[0] = nums[0];
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if ((nums[i] - nums[j]) % 2 == 0) {
                dp[i] = max(dp[i], dp[j] + nums[i]);
                break;
            } else {
                dp[i] = max(dp[i], dp[j] + nums[i] - x);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}
