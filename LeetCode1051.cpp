//
// Created by 陆泽辉 on 2022/6/13.
//

#include "LeetCode1051.h"

int LeetCode1051::heightChecker(vector<int> &heights) {
    int ret = 0, n = heights.size();
    vector<int> expected(heights.begin(), heights.end());
    sort(expected.begin(), expected.end(), less<int>());
    for (int i = 0; i < n; i++) {
        if (heights[i] != expected[i]) {
            ret++;
        }
    }
    return ret;
}
