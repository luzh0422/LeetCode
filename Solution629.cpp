//
// Created by luzh on 2021/11/11.
//

#include "Solution629.h"

#include <vector>

using namespace std;

int Solution629::kInversePairs(int n, int k) {
    const int mod = 1000000007;
    vector<vector<int>> dp(2, vector<int>(k + 1));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= k; j++) {
            int cur = i & 1, prev = cur ^ 1;
            dp[cur][j] = (j - 1 >= 0 ? dp[cur][j - 1] : 0) - (j - i >= 0 ? dp[prev][j - i] : 0) + dp[prev][j];
            if (dp[cur][j] >= mod) {
                dp[cur][j] -= mod;
            } else if (dp[cur][j] < 0) {
                dp[cur][j] += mod;
            }
        }
    }
    return dp[n & 1][k];
}
