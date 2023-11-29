//
// Created by 陆泽辉 on 2023/9/19.
//

#include "LeetCode2560.h"

int LeetCode2560::minCapability(vector<int> &nums, int k) {
    int n = nums.size();
    if (n == 0) {
        return -1;
    } else if (n == 1) {
        if (k == 1) {
            return nums[0];
        }
        return -1;
    }
    auto check = [&](int val) -> bool {
        vector<int> dp(n, 0);
        if (nums[0] <= val) {
            dp[0] = 1;
        }
        if (nums[1] <= val) {
            dp[1] = 1;
        } else {
            dp[1] = dp[0];
        }
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2]);
            if (nums[i] <= val) {
                dp[i] = max(dp[i - 1], dp[i - 2] + 1);
            }
        }
        return dp[n - 1] >= k;
    };
    int left = 0, right = *max_element(nums.begin(), nums.end());
    while (left + 1 < right) {
        int middle = (left + right) / 2;
        if (check(middle)) {
            right = middle;
        } else {
            left = middle;
        }
    }
    return right;
}
