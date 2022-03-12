//
// Created by luzh on 2021/7/15.
//

#include "Solution1846.h"

int Solution1846::maximumElementAfterDecrementingAndRearranging(vector<int> &arr) {
    int size = arr.size();
    if (size == 0) {
        return -1;
    }
    std::sort(arr.begin(), arr.end());
    arr[0] = 1;
    for (int i = 1; i < size; i++) {
        /**
         * 根据规则只能对数字做减法，不能做加法；
         */
        arr[i] = min(arr[i], arr[i - 1] + 1);
    }
    return arr.back();
}
