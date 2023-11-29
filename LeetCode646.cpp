//
// Created by 陆泽辉 on 2022/9/3.
//

#include "LeetCode646.h"

int LeetCode646::findLongestChain(vector<vector<int>> &pairs) {
    std::sort(pairs.begin(), pairs.end(), [](vector<int>& pair1, vector<int>& pair2) -> bool {
        if (pair1[0] < pair2[0] || pair1[0] == pair2[0] && pair1[1] < pair2[1]) {
            return true;
        } else {
            return false;
        }
    });
    int n = pairs.size();
    vector<int> dp(n, 1);
    int ret = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (pairs[i][0] > pairs[j][1]) {
                dp[i] = max(dp[i], dp[j] + 1);
                ret = max(ret, dp[i]);
            }
        }
    }
    return ret;
}
