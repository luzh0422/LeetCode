//
// Created by luzehui on 2024/8/11.
//

#include "LeetCode1035.h"

int LeetCode1035::maxUncrossedLines(vector<int> &nums1, vector<int> &nums2) {
//    vector<pair<int, int>> lines;
//    int res = 0;
//    for (int i = 0; i < nums1.size(); i++) {
//        int num1 = nums1[i];
//        int temp = 0;
//        for (int j = 0; j < nums2.size(); j++) {
//            int num2 = nums2[j];
//            if (num1 == num2) {
//                for (auto line : lines) {
//                    int line1 = line.first, line2 = line.second;
//                    if (line1 < i && line2 < j ||
//                        line1 > i && line2 > j) {
//                        temp++;
//                    }
//                }
//                lines.push_back({i, j});
//                res = max(res, temp);
//            }
//        }
//    }
//    return res;
    int m = nums1.size(), n = nums2.size();
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (nums1[i] == nums2[j]) {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            } else {
                dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
    }
    return dp[m][n];
}
