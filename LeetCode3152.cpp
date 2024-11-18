//
// Created by luzehui on 2024/8/14.
//

#include "LeetCode3152.h"

vector<bool> LeetCode3152::isArraySpecial(vector<int> &nums, vector<vector<int>> &queries) {
    int n = nums.size();
    vector<int> dp(n, 1);
    for (int i = 1; i < n; i++) {
        if (((nums[i - 1] ^ nums[i]) & 1) == 1) {
            dp[i] = dp[i - 1] + 1;
        }
    }
    int m = queries.size();
    vector<bool> res{};
    for (int i = 0; i < m; i++) {
        auto query = queries[i];
        int x = query[0], y = query[1];
        res.push_back(dp[y] >= (y - x + 1));
    }
    return res;
}
