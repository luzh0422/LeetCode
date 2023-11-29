//
// Created by 陆泽辉 on 2022/6/10.
//

#include "LeetCode730.h"

#include <vector>
#include <unordered_set>

int LeetCode730::countPalindromicSubsequences(string s) {
    int n = s.size();
    const int MOD = 1000000007;
    vector<vector<int>> dp(n, vector<int>(n, 0));
    unordered_set<string> uS;
    for (int i = 0; i < n; i++) {
        dp[i][i] = 1;
        uS.insert(string(1,s[i]));
    }
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (s[i] == s[j]) {
                if (j - i == 1 || dp[i + 1][j - 1] == 1) {
                    dp[i][j] = 1;
                    uS.insert(s.substr(i, j - i));
                }
            }
        }
    }
    return uS.size() % MOD;
}
