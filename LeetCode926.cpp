//
// Created by 陆泽辉 on 2022/6/11.
//

#include "LeetCode926.h"
#include <vector>

int LeetCode926::minFlipsMonoIncr(string s) {
    int n = s.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    /**
     * initialize;
     */
    if (s[0] == '0') {
        dp[0][0] = 0;
        dp[0][1] = 1;
    } else {
        dp[0][0] = 1;
        dp[0][1] = 0;
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == '0') {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        } else {
            dp[i][0] = dp[i - 1][0] + 1;
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]);
        }
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
}
