//
// Created by luzehui on 2024/3/1.
//

#include "LeetCode2369.h"

bool LeetCode2369::validPartition(vector<int> &nums) {
    int n = nums.size();
    vector<bool> dp(n + 1, false);
    dp[0] = true;
    for (int i = 1; i <= n; i++) {
        if (i >= 2) {
            dp[i] = dp[i - 2] && validTwo(nums[i - 2], nums[i - 1]);
        }
        if (i >= 3) {
            dp[i] = dp[i] || (dp[i - 3] && validThree(nums[i - 3], nums[i - 2], nums[i - 1]));
        }
    }
    return dp[n];
}

bool LeetCode2369::validTwo(int num1, int num2) {
    return num1 == num2;
}

bool LeetCode2369::validThree(int num1, int num2, int num3) {
    return (num1 == num2 && num1 == num3) || (num1 + 1 == num2 && num2 + 1 == num3);
}


