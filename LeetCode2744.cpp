//
// Created by luzehui on 2024/1/17.
//

#include "LeetCode2744.h"

int LeetCode2744::maximumNumberOfStringPairs(vector<std::string> &words) {
    int n = words.size(), ans = 0;
    vector<int> tag(n, 0);
    for (int i = 0; i < n; i++) {
        if (tag[i] == 1) {
            continue;
        }
        for (int j = i + 1; j < n; j++) {
            if (words[i].size() == words[j].size()) {
                int m = words[i].size(), step = 0;
                while (step < m) {
                    if (words[i][step] != words[j][m - step - 1]) {
                        break;
                    }
                    step++;
                }
                if (m == step) {
                    ans++;
                    tag[i] = 1;
                    tag[j] = 1;
                    break;
                }
            }
        }
    }
    return ans;
}
