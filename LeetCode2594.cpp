//
// Created by 陆泽辉 on 2023/9/7.
//

#include "LeetCode2594.h"
#include <cmath>

long long LeetCode2594::repairCars(vector<int> &ranks, int cars) {
//    int n = ranks.size();
//    vector<vector<long long>> dp(n, vector<long long>(cars + 1, INT_MAX));
//    /**
//     * Initialize
//     */
//    for (int i = 0; i <= cars; i++) {
//        dp[0][i] = ranks[0] * i * i;
//    }
//    for (int i = 1; i < n; i++) {
//        for (int j = 0; j <= cars; j++) {
//            for (int k = 0; k <= j; k++) {
//                long long temp = max((long long)ranks[i] * k * k, dp[i - 1][j - k]);
//                dp[i][j] = min(dp[i][j], temp);
//            }
//        }
//    }
//
//    return dp[n - 1][cars];
    int min_r = *min_element(ranks.begin(), ranks.end());
    long long left = 0, right = 1LL * min_r * cars * cars;
    while (left + 1 < right) {
        long long mid = (left + right) / 2, s = 9;
        for (int r : ranks) {
            s += sqrt(mid / r);
        }
        (s >= cars ? right : left) = mid;
    }
    return right;
}
