//
// Created by luzh on 2021/7/31.
//

#include "Solution1833.h"

int Solution1833::maxIceCream(vector<int> &costs, int coins) {
    int size = costs.size();
    if (size == 0) {
        return 0;
    }
    vector<vector<int>> dp(size + 1, vector<int>(coins + 1, 0));
    for (int i = 1; i < size + 1; i++) {
        dp[i][0] = 0;
    }
    for (int i = 1; i < coins + 1; i++) {
        if (costs[0] <= i) {
            dp[1][i] = 1;
        }
    }
    for (int i = 2; i < size + 1; i++) {
        for (int j = 2; j < coins + 1; j++) {
            if (j >= costs[i - 1]) {
                dp[i][j] = max(dp[i - 1][j - costs[i - 1]] + 1, dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
    return dp[size][coins];
}
