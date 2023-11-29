//
// Created by 陆泽辉 on 2022/5/12.
//

#include "LeetCode944.h"

int LeetCode944::minDeletionSize(vector<string> &strs) {
    int n = strs.size();
    int m = strs[0].size();
    int count = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 1; j < n; j++) {
            if (strs[j][i] < strs[j - 1][i]) {
                count++;
                break;
            }
        }
    }
    return count;
}
