//
// Created by luzehui on 2024/1/16.
//

#include "LeetCode2645.h"

int LeetCode2645::addMinimum(std::string word) {
    int n = word.size();
    vector<int> dp(n);
    dp[0] = 2;
    for (int i = 1; i < n; i++) {
        dp[i] = dp[i] + 2;
        if (word[i] > word[i - 1]) {
            dp[i] = dp[i] - 1;
        }
    }
    return dp[n - 1];
}
