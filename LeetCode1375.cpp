//
// Created by 陆泽辉 on 2023/6/14.
//

#include "LeetCode1375.h"

int LeetCode1375::numTimesAllBlue(vector<int> &flips) {
    int maxEle = 0, n = flips.size();
    int res = 0;
    for (int i = 0; i < n; i++) {
        maxEle = max(flips[i], maxEle);
        if (i + 1 == maxEle) {
            res++;
        }
    }
    return res;
}
