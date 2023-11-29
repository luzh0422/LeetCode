//
// Created by 陆泽辉 on 2022/9/8.
//

#include "LeetCode667.h"

vector<int> LeetCode667::constructArray(int n, int k) {
    vector<int> answer;
    /**
     * 1 ~ n - k，顺序排序，每两个相邻数之间相差1；
     */
    for (int i = 1; i < n - k; i++) {
        answer.push_back(i);
    }
    /**
     * n - k ~ n，交叉排列[n - k, n, n - k + 1, n - 1 .... n]，则每个相邻之间的差值由 k ~ 1，共有k个。
     */
    for (int i = n - k, j = n; i <= j; ++i, --j) {
        answer.push_back(i);
        if (i != j) {
            answer.push_back(j);
        }
    }
    return answer;
}
