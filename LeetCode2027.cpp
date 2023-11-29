//
// Created by 陆泽辉 on 2022/12/27.
//

#include "LeetCode2027.h"

int LeetCode2027::minimumMoves(string s) {
    int n = s.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') {
            res++;
            i += 2;
        }
    }
    return res;
}
