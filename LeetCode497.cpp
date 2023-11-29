//
// Created by 陆泽辉 on 2022/6/9.
//

#include "LeetCode497.h"

LeetCode497::LeetCode497(vector<vector<int>> &rects) {
    mRects = rects;
    int n = rects.size();
    sums.resize(n + 1);
    sums[0] = 0;
    for (int i = 0; i < n; i++) {
        sums[i + 1] = sums[i] + (rects[i][2] - rects[i][0] + 1) * (rects[i][3] - rects[i][1] + 1);
    }
    totalSum = sums[n];
}

vector<int> LeetCode497::pick() {
    int n = sums.size();
    int randomSum = rand() % (totalSum + 1) + 1;
    int l = 0, r = n - 1;
    while (l < r) {
        int middle = (l + r) / 2;
        if (sums[middle] >= randomSum) {
            r = middle;
        } else {
            l = middle + 1;
        }
    }
    auto currRect = mRects[r];
    int left = currRect[0];
    int bottom = currRect[1];
    int right = currRect[2];
    int top = currRect[3];
    int currX = rand() % (right - left + 1) + left;
    int currY = rand() % (top - bottom + 1) + bottom;
    return {currX, currY};
}


