//
// Created by luzehui on 25-4-1.
//

#include "LeetCode2140.h"

long long LeetCode2140::mostPoints(vector<vector<int>> &questions) {
    int n = questions.size();
    vector<long long> dp(n + 1, 0ll);
    for (int i = n - 1; i >= 0; i--) {
        dp[i] = max(dp[i + 1], questions[i][0] + dp[min(i + questions[i][1] + 1, n)]);
    }
    return dp[0];
}
