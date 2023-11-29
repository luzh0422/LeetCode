//
// Created by 陆泽辉 on 2023/5/15.
//

#include "LeetCode1072.h"

#include <unordered_map>
#include <string>

int LeetCode1072::maxEqualRowsAfterFlips(vector<vector<int>> &matrix) {
    int m = matrix.size(), n = matrix[0].size();
    unordered_map<string, int> mp;
    for (int i = 0; i < m; i++) {
        string s = string(n, '0');
        for (int j = 0; j < n; j++) {
            // 如果 matrix[i][0] 为 1，则对该行元素进行翻转
            s[j] = '0' + (matrix[i][j] ^ matrix[i][0]);
        }
        if (mp.count(s)) {
            mp[s]++;
        } else {
            mp.emplace(s, 1);
        }
    }
    int res = 0;
    for (auto &[k, v] : mp) {
        res = max(res, v);
    }
    return res;
}
