//
// Created by luzehui on 2024/10/1.
//

#include "LeetCode983.h"

int LeetCode983::mincostTickets(vector<int> &days, vector<int> &costs) {
    int n = days.back();
    vector<int> dp(n + 1, 0);
    for (int i = 1; i <= n; i++) {
        if (find(days.begin(), days.end(), i) != days.end()) {
            dp[i] = min(dp[i - 1] + costs[0],
                        min(dp[max(i - 7, 0)] + costs[1], dp[max(i - 30, 0)] + costs[2]));
        } else {
            dp[i] = dp[i - 1];
        }
    }
    return dp.back();
}
