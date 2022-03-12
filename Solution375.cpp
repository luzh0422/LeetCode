//
// Created by luzh on 2021/11/12.
//

#include "Solution375.h"
#include <vector>

using namespace std;

int Solution375::getMoneyAmount(int n) {
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));
    /**
     * initialize;
     */
    for (int i = 1; i < n; i++) {
        dp[i][i + 1] = i;
        for (int j = i + 2; j <= n; j++) {
            dp[i][j] = INT_MAX;
        }
    }
    for (int i = n; i > 0; i--) {
        for (int j = i + 1; j <= n; j++) {
            for (int k = i + 1; k < j; k++) {
                dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
            }
        }
    }
    return dp[1][n];
}
