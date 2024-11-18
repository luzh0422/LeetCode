//
// Created by luzehui on 2024/2/5.
//

#include "LeetCode1696.h"
#include <set>

int LeetCode1696::maxResult(vector<int> &nums, int k) {
    int n = nums.size();
    multiset<int, greater<int>> cache;
    vector<int> dp(n, INT_MIN);
    dp[0] = nums[0];
    cache.insert(dp[0]);
    for (int i = 1; i < n; i++) {
        if (i > k) {
            cache.erase(cache.find(dp[i - k - 1]));
        }
        dp[i] = nums[i] + *(cache.begin());
        cache.insert(dp[i]);
    }
    return dp[n - 1];
}
