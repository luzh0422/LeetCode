//
// Created by luzehui on 2024/4/10.
//

#include "LeetCode1702.h"

string LeetCode1702::maximumBinaryString(std::string s) {
    int idx = -1, n = s.size();
    for (int i = 0; i < n; i++) {
        if (s[i] == '0') {
            idx = i;
            break;
        }
    }
    if (idx == -1) {
        return s;
    }
    std::sort(s.begin() + idx, s.end());
    int r = n;
    for (int i = idx; i < n; ++i) {
        if (s[i] == '1') {
            r = i;
            break;
        }
    }
    for (int i = idx; i < r - 1; ++i) {
        s[i] = '1';
    }
    return s;
}
