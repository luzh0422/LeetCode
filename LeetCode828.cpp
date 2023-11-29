//
// Created by 陆泽辉 on 2022/9/6.
//

#include "LeetCode828.h"

/**
 * 统计每个字符作为单一字符，在子串中，对整个字符串的贡献值。
 */
int LeetCode828::uniqueLetterString(string s) {
    int n = s.size();
    int ret = 0;
    for (int i = 0; i < n; i++) {
        char c = s[i];
        int left = i - 1;
        int right = i + 1;
        while (left >= 0 && s[left] != c) {
            left--;
        }
        while (right < n && s[right] != c) {
            right++;
        }
        ret += (i - left) * (right - i);
    }
    return ret;
}

int LeetCode828::countUniqueChars(string &s) {
    return -1;
}
