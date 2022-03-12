//
// Created by luzh on 2021/10/23.
//

#include "HUAWEI1.h"

int HUAWEI1::maxProfit(vector<int> prices) {
    int n = prices.size();
    if (n == 0) return 0;
    vector<vector<int>> dp(n, vector<int>(2));
    /**
     * initialize;
     */
    // 第0天不持有股票；
    dp[0][0] = 0;
    // 第0天持有股票；
    dp[0][1] = -prices[0];
    for (int i = 1; i < n; i++) {
        /**
         * 第i天不持有股票；
         */
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
        /**
         * 第i天持有股票；
         */
        dp[i][1] = max(dp[i - 1][1], -prices[i]);
    }
    return dp[n - 1][0];
}
