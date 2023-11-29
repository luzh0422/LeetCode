//
// Created by 陆泽辉 on 2023/4/22.
//

#include "LeetCode1027.h"
#include <unordered_map>
#include <vector>

int LeetCode1027::longestArithSeqLength(vector<int> &nums) {
    int n = nums.size();
    vector<vector<int>> dp(n, vector<int>(1001, 1));
    int res = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            int delta = nums[i] - nums[j] + 500;
            int curr = max(dp[i][delta], dp[j][delta] + 1);
            dp[i][delta] = curr;
            res = max(res, curr);
        }
    }
    return res;
}
