//
// Created by luzehui on 2024/8/28.
//

#include "LeetCode3144.h"
#include <vector>

int LeetCode3144::minimumSubstringsInPartition(std::string s) {
    int n = s.size();
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 1; i < n; i++) {
        vector<int> cache(26, 0);
        dp[i + 1] = dp[i] + 1;
        for (int j = i; j >= 0; j--) {
            cache[s[j] - 'a']++;
            int num = 0;
            bool tag = false;
            for (int k = 0; k < 26; k++) {
                if (cache[k] != 0) {
                    if (num == 0) {
                        num = cache[k];
                    } else if (num != cache[k]) {
                        tag = true;
                        break;
                    }
                }
            }
            if (!tag) {
                dp[i + 1] = min(dp[i + 1], dp[j] + 1);
            }
        }
    }
    return dp[n];
}
