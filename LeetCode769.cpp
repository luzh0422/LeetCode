//
// Created by 陆泽辉 on 2022/10/13.
//

#include "LeetCode769.h"

namespace {
    int getNextStep(vector<int>& steps, int start, int end) {
        for (int i = start; i <= end; i++) {
            if (i + steps[i] > end) {
                return getNextStep(steps, i, i + steps[i]);
            }
        }
        return end;
    }
}

int LeetCode769::maxChunksToSorted(vector<int> &arr) {
    int n = arr.size();
    vector<int> steps(n, 0);
    for (int i = 0; i < n; i++) {
        steps[i] = arr[i] - i;
    }
    int ret = 0;
    int i = 0;
    while (i < n) {
        if (steps[i] <= 0) {
            ret++;
            i++;
        } else {
            i = getNextStep(steps, i, i + steps[i]);
        }
    }
    return ret;
}
