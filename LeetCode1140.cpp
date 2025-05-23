//
// Created by 陆泽辉 on 2023/2/22.
//

#include "LeetCode1140.h"
#include <numeric>

/**
 * dp[i][m]表示 i 到 len - 1，分为m时，取得的最大值；
 * @param piles
 * @return
 */
int LeetCode1140::stoneGameII(vector<int> &piles) {
    int n = piles.size();
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MIN));
    for (int i = n; i >= 0; i--) {
        for (int m = 1; m <= n; m++) {
            if (i == n) {
                dp[i][m] = 0;
            } else {
                int sum = 0;
                for (int x = 1; x <= 2 * m; x++) {
                    if (i + x > n) {
                        break;
                    }
                    sum += piles[i + x - 1];
                    dp[i][m] = max(dp[i][m], sum - dp[i + x][min(n, max(m, x))]);
                }
            }
        }
    }
    return dp[0][1] + accumulate(piles.begin(), piles.end(), 0) / 2;
}
