//
// Created by luzh on 2021/5/24.
//

#include "Solution664.h"

#include <vector>

int Solution664::strangePrinter(string s) {
    int sSize = s.size();
    vector<vector<int>> dp(sSize, vector<int>(sSize));
    for (int i = sSize - 1; i >= 0; i--) {
        /**
         * 初始化，只有一个字符时，打印次数为1；
         */
        dp[i][i] = 1;
        for (int j = i + 1; j < sSize; j++) {
            if (s[i] == s[j]) {
                dp[i][j] = dp[i][j - 1];
            } else {
                int minn = INT_MAX;
                for (int k = i; k < j; k++) {
                    minn = min(minn, dp[i][k] + dp[k + 1][j]);
                }
                dp[i][j] = minn;
            }
        }
    }
    return dp[0][sSize - 1];
}
