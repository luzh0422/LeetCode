//
// Created by luzehui on 2023/10/23.
//

#include "LeetCode1155.h"

#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

int LeetCode1155::numRollsToTarget(int n, int k, int target) {
    // dp[使用骰子的个数][当前数的总和] = dp[使用头子的个数 - 1][当前数的总和] + dp[使用骰子的个数][当前数的总和];
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0));
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            for (int l = 1; l <= j && l <= target; l++) {
                dp[i][j] = dp[i][j] + dp[i - 1][j - l];
                dp[i][j] %= MOD;
            }
        }
    }
    return dp[n][target];
//    int ans = 0;
//    for (int i = 1; i <= k; i++) {
//        ans = ans % MOD + backtrace(n - 1, k, target, i) % MOD;
//        ans %= MOD;
//    }
//    return ans;
}

int LeetCode1155::backtrace(int n, int k, int target, int curr) {
    if (target == curr) {
        return 1;
    } else if (curr > target || n == 0) {
        return 0;
    }
    int ans = 0;
    for (int i = 0; i < k; i++) {
        ans = ans % MOD + backtrace(n - 1, k, target, curr + i) % MOD;
        ans %= MOD;
    }
    return ans;
}
