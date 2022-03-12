//
// Created by luzh on 2021/8/18.
//

#include "Solution552.h"

#include <vector>

using namespace std;

int Solution552::checkRecord(int n) {
    const int MOD = 1000000007;
    vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(2, vector<int>(3)));
    dp[0][0][0] = 1;
    for (int i = 1; i <= n; i++) {
        /**
         * 以 P 结尾的数量；
         */
        for (int j = 0; j <= 1; j++) {
            for (int k = 0; k <= 2; k++) {
                dp[i][j][0] = (dp[i][j][0] + dp[i - 1][j][k]) % MOD;
            }
        }
        /**
         * 以 A 结尾的数量；
         */
         for (int k = 0; k <= 2; k++) {
             dp[i][1][0] = (dp[i][1][0] + dp[i - 1][0][k]) % MOD;
         }
         /**
          * 以 P 结尾的数量；
          */
         for (int j = 0; j <= 1; j++) {
             for (int k = 1; k <= 2; k++) {
                 dp[i][j][k] = (dp[i][j][k] + dp[i - 1][j][k - 1]) % MOD;
             }
         }
    }
    int sum = 0;
    for (int j = 0; j <= 1; j++) {
        for (int k = 0; k <= 2; k++) {
            sum = (sum + dp[n][j][k]) % MOD;
        }
    }
    return sum;
}
