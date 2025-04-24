//
// Created by luzehui on 25-1-27.
//

#include "LeetCode45.h"

int LeetCode45::jump(vector<int> &nums) {
    int n = nums.size();
    vector<int> dp(n, 0x3f3f3f3f);
    dp[0] = 0;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        for (int j = 1; j <= num; j++) {
            if (i + j < n) {
                dp[i + j] = min(dp[i + j], dp[i] + 1);
            }
        }
    }
    return dp[n - 1];
}
