//
// Created by 陆泽辉 on 2023/2/25.
//

#include "LeetCode1247.h"

int LeetCode1247::minimumSwap(string s1, string s2) {
    int XYCount = 0, YXCount = 0;
    int n = s1.size();
    for (int i = 0; i < n; i++) {
        if (s1[i] != s2[i]) {
            if (s1[i] == 'x') {
                XYCount++;
            } else {
                YXCount++;
            }
        }
    }
    int res = 0;
    res += XYCount / 2 + YXCount / 2;
    XYCount %= 2;
    YXCount %= 2;
    if (XYCount != YXCount) {
        return -1;
    }
    res += 2 * XYCount;
    return res;
}
