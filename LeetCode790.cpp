//
// Created by 陆泽辉 on 2022/11/12.
//

#include "LeetCode790.h"
#include <vector>

using namespace std;

int LeetCode790::numTilings(int n) {
    const long long int MOD = 1e9 + 7;
    vector<vector<long long>> dp(n + 1, vector<long long>(4, 0));
    dp[0][3] = 1;
    for (int i = 1; i <= n; i++) {
        dp[i][0] = dp[i - 1][3];
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % MOD;
        dp[i][3] = dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2] + dp[i - 1][3];
    }
    return dp[n][3];
}
