//
// Created by luzehui on 2024/8/25.
//

#include "LeetCode698.h"
#include <numeric>

bool LeetCode698::canPartitionKSubsets(vector<int> &nums, int k) {
    int sum = accumulate(nums.begin(), nums.end(), 0);
    if (sum % k != 0) {
        return false;
    }
    int per = sum / k;
    int n = nums.size();
    vector<int> dp(1 << n, true);
    function<bool(int, int)> dfs = [&](int s, int p) -> bool {
        if (s == 0) {
            return true;
        }
        if (p == per) {
            return dfs(s, 0);
        }
        if (p > per) {
            return false;
        }
        if (!dp[s]) {
            return dp[s];
        }
        dp[s] = false;
        for (int i = 0; i < n; i++) {
            if ((s >> i) & 1) {
                s ^= (1 << i);
                if (dfs(s, p + nums[i])) {
                    return true;
                }
                s ^= (1 << i);
            }
        }
        return false;
    };
    return dfs((1 << n) - 1, 0);
}
