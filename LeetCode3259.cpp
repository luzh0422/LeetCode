//
// Created by luzehui on 2024/11/1.
//

#include "LeetCode3259.h"

long long LeetCode3259::maxEnergyBoost(vector<int> &energyDrinkA, vector<int> &energyDrinkB) {
    int n = energyDrinkA.size();
    vector<vector<long long>> dp(n + 1, vector<long long>(2, 0ll));
    dp[1][0] = energyDrinkA[0];
    dp[1][1] = energyDrinkB[0];
    for (int i = 2; i <= n; i++) {
        dp[i][0] = max(dp[i - 2][1], dp[i - 1][0]) + energyDrinkA[i - 1];
        dp[i][1] = max(dp[i - 2][0], dp[i - 1][1]) + energyDrinkB[i - 1];
    }
    return max(dp[n][0], dp[n][1]);
}
