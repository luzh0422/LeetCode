//
// Created by 陆泽辉 on 2023/3/27.
//

#include "LeetCode1638.h"

int LeetCode1638::countSubstrings(string s, string t) {
    int res = 0;
    int n = s.size(), m = t.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            int count = 0;
            for (int k = 0; i + k < n && j + k < m; k++) {
                if (s[i + k] != t[j + k]) {
                    count++;
                }
                if (count == 1) {
                    res++;
                } else if (count > 1) {
                    break;
                }
            }
        }
    }
    return res;
}
