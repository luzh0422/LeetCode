//
// Created by luzehui on 2024/9/11.
//

#include "LeetCode2555.h"

int LeetCode2555::maximizeWin(vector<int> &prizePositions, int k) {
    int n = prizePositions.size(), l = 0, r = 0, res = 0;
    vector<int> dp(n + 1, 0);
    while (r < n) {
        if (prizePositions[r] - prizePositions[l] <= k) {
            res = max(res, r - l + 1 + dp[l]);
            dp[r + 1] = max(dp[r], r - l + 1);
            r++;
        } else {
            l++;
        }
    }
    return res;
}
