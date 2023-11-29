//
// Created by 陆泽辉 on 2022/8/14.
//

#include "LeetCode1422.h"

int LeetCode1422::maxScore(string s) {
    int left = s[0] == '0' ? 1 : 0;
    int right = 0;
    int n = s.size();
    for (int i = 1; i < n; i++) {
        if (s[i] == '1') {
            right++;
        }
    }
    int ret = left + right;
    for (int i = 1; i < n - 1; i++) {
        if (s[i] == '0') {
            left++;
        } else {
            right--;
        }
        ret = max(ret, left + right);
    }
    return ret;
}
