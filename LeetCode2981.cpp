//
// Created by luzehui on 2024/5/29.
//

#include "LeetCode2981.h"
#include <vector>

/**
 * 巧妙运用二维数组存储字符串长度；
 * @param s
 * @return
 */
int LeetCode2981::maximumLength(std::string s) {
    int n = s.size();
    vector<vector<int>> records(26, vector<int>(n + 1, 0));
    int res = -1;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
            if (s[j] != s[i]) {
                break;
            }
            if (++records[s[i] - 'a'][j - i + 1] >= 3) {
                res = max(res, j - i + 1);
            }
        }
    }
    return res;
}
