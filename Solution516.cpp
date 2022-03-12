//
// Created by luzh on 2021/8/12.
//

#include "Solution516.h"

#include <vector>

int Solution516::longestPalindromeSubseq(string s) {
    int size = s.size();
    vector<vector<int>> dp(size, vector<int>(size, 0));
    for (int i = 0; i < size; i++) {
        dp[i][i] = 1;
    }
    /**
     * 为什么i要逆循环，因为在状态转移发成中要用到dp[i + 1][j - 1]，在这个时候，dp[i + 1][j - 1]一定应该是已经计算好的值；
     */
    for (int i = size - 1; i >= 0; i--) {
        const char c1 = s.at(i);
        for (int j = i + 1; j < size; j++) {
            const char c2 = s.at(j);
            if (c1 == c2) {
                dp[i][j] = dp[i + 1][j - 1] + 2;
            } else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
    }
    return dp[0][size - 1];
}
