//
// Created by 陆泽辉 on 2022/10/10.
//

#include "LeetCode801.h"

/**
 * 设置dp[i][0]表示位置i不交换的最小次数；
 * 设置dp[i][1]表示位置i交换的最小次数；
 * 设置a1 = nums1[i], a2 = nums2[i - 1], b1 = nums2[i], b2 = nums2[i - 1];
 * 想要满足题目中的限定条件，必须满足下面条件之一：
 * 1. a1 > a2 && b1 > b2;
 * 2. a1 > b2 && b1 > a2;
 * 1）如果只满足条件1，不满足条件2；
 * dp[i][0] = dp[i - 1][0]; // i 和 i - 1都不更换；
 * dp[i][1] = dp[i - 1][1] + 1; // i 和 i - 1都发生更换；
 * 2）如果只满足条件2， 不满足条件1；
 * dp[i][0] = dp[i - 1][1]; // i - 1更换，i不更换；
 * dp[i][i - 1] = dp[i - 1][0] + 1; // i - 1不更换，i更换；
 * 3）同时满足条件1，2
 * dp[i][0] = min(dp[i - 1][1], dp[i - 1][0]); // i不更换，取i - 1更换、不更换的最小值；
 * dp[i][1] = min(dp[i - 1][1], dp[i - 1][0]) + 1; // i更换，取i - 1更换、不更换的最小值 + 1；
 * @param nums1
 * @param nums2
 * @return
 */
int LeetCode801::minSwap(vector<int> &nums1, vector<int> &nums2) {
    int n = nums1.size();
    vector<vector<int>> dp(n, vector<int>(2, 0));
    dp[0][0] = 0;
    dp[0][1] = 1;
    for (int i = 1; i < n; i++) {
        if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1] && nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]) {
            dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
            dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + 1;
        } else if (nums1[i] > nums1[i - 1] && nums2[i] > nums2[i - 1]) {
            dp[i][0] = dp[i - 1][0];
            dp[i][1] = dp[i - 1][1] + 1;
        } else if (nums1[i] > nums2[i - 1] && nums2[i] > nums1[i - 1]){
            dp[i][0] = dp[i - 1][1];
            dp[i][1] = dp[i - 1][0] + 1;
        } else {
            return -1;
        }
    }
    return min(dp[n - 1][0], dp[n - 1][1]);
}
