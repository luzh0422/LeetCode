//
// Created by luzehui on 2024/8/6.
//

#include "LeetCode3129.h"

const int MOD = 1e9 + 7;

int LeetCode3129::dfs(int zero, int one, int lastBit, int limit, vector<vector<vector<int>>>& memo) {
    if (zero == 0) {
        return (lastBit == 0 || one > limit) ? 0 : 1;
    } else if (one == 0) {
        return (lastBit == 1 || zero > limit) ? 0 : 1;
    }
    if (memo[zero][one][lastBit] == -1) {
        int res = 0;
        if (lastBit == 0) {
            res = (dfs(zero - 1, one, 0, limit, memo) + dfs(zero - 1, one, 1, limit, memo)) % MOD;
            if (zero > limit) {
                res = (res - dfs(zero - limit - 1, one, 1, limit, memo) + MOD) % MOD;
            }
        } else {
            res = (dfs(zero, one - 1, 0, limit, memo) + dfs(zero, one, 1, limit, memo)) % MOD;
            if (one > limit) {
                res = (res - dfs(zero, one - limit - 1, 0, limit, memo) + MOD) % MOD;
            }
        }
        memo[zero][one][lastBit] = res % MOD;
    }
    return memo[zero][one][lastBit];
}

int LeetCode3129::numberOfStableArrays(int zero, int one, int limit) {
    vector<vector<vector<int>>> memo(zero + 1, vector<vector<int>>(one + 1, vector<int>(2, -1)));
    return (dfs(zero, one, 0, limit, memo) + dfs(zero, one, 1, limit, memo)) % MOD;
}
