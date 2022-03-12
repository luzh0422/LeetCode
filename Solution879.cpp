//
// Created by luzh on 2021/6/9.
//

#include "Solution879.h"

int Solution879::profitableSchemes(int n, int minProfit, vector<int> &group, vector<int> &profit) {
    int size = group.size();
    const int MOD = (int)1e9 + 7;
    /**
     * 前i项工作，参与员工数为j时，盈利为k时 的计划数量；
     */
    vector<vector<vector<int>>> dp(size + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= size; i++) {
        int members = group[i - 1];
        int earn = profit[i - 1];
        for (int j = 0; j <= n; j++) {
            for (int k = 0; k <= minProfit; k++) {
                if (j < members) {
                    dp[i][j][k] = dp[i - 1][j][k];
                } else {
                    dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - members][max(0, k - earn)]) % MOD;
                }
            }
        }
    }
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum = (sum + dp[size][i][minProfit]) % MOD;
    }
    return sum;
}
