//
// Created by 陆泽辉 on 2023/4/19.
//

#include "LeetCode1043.h"

int LeetCode1043::maxSumAfterPartitioning(vector<int> &arr, int k) {
    int n = arr.size();
    vector<int> d(n + 1);
    for (int i = 1; i <= n; i++) {
        int maxValue = arr[i - 1];
        /**
         * 这个遍历用了从后向前遍历，完美的选择了范围内的最大值；
         */
        for (int j = i - 1; j >= 0 && j >= i - k; j--) {
            /**
             * dp[i]表示arr[0]、arr[1]、...、arr[i - 1]的最大值；
             */
            d[i] = max(d[i], d[j] + maxValue * (i - j));
            if (j > 0) {
                maxValue = max(maxValue, arr[j - 1]);
            }
        }
    }
    return d[n];
}
