//
// Created by 陆泽辉 on 2023/3/9.
//

#include "LeetCode2379.h"
#include <vector>

int LeetCode2379::minimumRecolors(string blocks, int k) {
    int n = blocks.size(), res = INT_MAX;
    vector<int> WPrefix(n + 1, 0);
    for (int i = 0; i < n; i++) {
        if (blocks[i] == 'W') {
            WPrefix[i + 1] = WPrefix[i] + 1;
        } else {
            WPrefix[i + 1] = WPrefix[i];
        }
        if (i + 1 >= k) {
            res = min(WPrefix[i + 1] - WPrefix[i + 1 - k], res);
        }
    }
    return res;
}
