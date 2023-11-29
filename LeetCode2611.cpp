//
// Created by 陆泽辉 on 2023/6/7.
//

#include "LeetCode2611.h"

#include <numeric>

int LeetCode2611::miceAndCheese(vector<int> &reward1, vector<int> &reward2, int k) {
    if (k == 0) {
        return accumulate(reward2.begin(), reward2.end(), 0);
    }
    int n = reward1.size();
    vector<int> dp(k + 1, 0);
    dp[0] = reward2[0];
    dp[1] = reward1[0];
    for (int i = 1; i < n; i++) {
        for (int j = min(i + 1, k); j > 0; j--) {
            if (j < i + 1) {
                dp[j] = max(dp[j] + reward2[i], dp[j - 1] + reward1[i]);
            } else {
                dp[j] = accumulate(reward1.begin(), reward1.begin() + j, 0);
            }
        }
        dp[0] += reward2[i];
    }
    return dp[k];
}
