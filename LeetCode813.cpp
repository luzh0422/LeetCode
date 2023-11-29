//
// Created by 陆泽辉 on 2022/11/28.
//

#include "LeetCode813.h"

/**
 * 属于把一个数组分成k段，求一个最值属性。
 * dp[i][k] 表示将nums[0 : i]分成k份最大平均值和。
 * 枚举一个能使dp[i][k]取最大值的分割点j，0 - j分割成k - 1份，j + 1 - i单独一份。
 */
double LeetCode813::largestSumOfAverages(vector<int> &nums, int k) {
    int n = nums.size();
    vector<vector<double>> dp(n + 1, vector<double>(k + 1, 0.0f));
    vector<double> prefix(n + 1, 0.0f);
    for (int i = 0; i < n; i++) {
        prefix[i + 1] = prefix[i] + static_cast<double>(nums[i]);
    }
    for(int i = 0; i < n; i++) {
        dp[i + 1][1] = prefix[i + 1] / (i + 1);
    }
    for (int i = 2; i <= n; i++) {
        for (int l = 2; l <= k; l++) {
            for (int j = 1; j < i; j++) {
                dp[i][l] = max(dp[i][l], dp[j][l - 1] + (prefix[i] - prefix[j]) / (i - j));
            }
        }
    }
    return dp[n][k];
}
