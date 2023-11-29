//
// Created by 陆泽辉 on 2022/5/13.
//

#include "LeetCode01_05.h"
#include <vector>

bool LeetCode01_05::oneEditAway(string first, string second) {
    int m = first.size(), n = second.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    /**
     * initialize;
     */
    for (int i = 0; i <= m; i++) {
        dp[i][0] = i;
    }
    for (int i = 0; i <= n; i++) {
        dp[0][i] = i;
    }
    for (int i = 1; i <= m; ++i) {
        for (int j = 1; j <= n; ++j) {
            if (first[i - 1] == second[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1];
            } else {
                dp[i][j] = min(min(dp[i - 1][j], dp[i][j - 1]), dp[i - 1][j - 1]) + 1;
            }
        }
    }
    return dp[m][n] <= 1;
}
