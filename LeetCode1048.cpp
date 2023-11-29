//
// Created by 陆泽辉 on 2023/4/27.
//

#include "LeetCode1048.h"

int LeetCode1048::longestStrChain(vector<string> &words) {
    std::sort(words.begin(), words.end(), [](string& word1, string& word2) -> bool {
        return word1.size() < word2.size();
    });
    int n = words.size();
    vector<int> dp(n, 1);
    int res = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (words[i].size() - words[j].size() > 1) {
                break;
            }
            if (words[i].size() - words[j].size() == 0) {
                continue;
            }
            if (isStrChain(words[j], words[i])) {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    return res;
}

bool LeetCode1048::isStrChain(string &word1, string &word2) {
    int i = 0, j = 0;
    int n = word1.size(), m = word2.size();
    for (; j < m; j++) {
        if (word1[i] == word2[j]) {
            i++;
        }
        if (i >= n) {
            break;
        }
    }
    return i >= n;
}
