//
// Created by 陆泽辉 on 2022/7/9.
//

#include "LeetCode873.h"
#include <unordered_map>

int LeetCode873::lenLongestFibSubseq(vector<int> &arr) {
    unordered_map<int, int> indicates;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        indicates[arr[i]] = i;
    }
    vector<vector<int>> dp(n, vector<int>(n, 0));
    int ret = 0;
    for (int i = 2; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            int temp = arr[i] - arr[j];
            if (temp >= arr[j]) {
                break;
            }
            if (indicates.count(temp)) {
                int tempIndex = indicates[temp];
                dp[i][j] = max(dp[j][tempIndex] + 1, 3);
            }
            ret = max(ret, dp[i][j]);
        }
    }
    return ret;
}
