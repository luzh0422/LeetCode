//
// Created by luzh on 2021/8/29.
//

#include "Solution1588.h"

int Solution1588::sumOddLengthSubarrays(vector<int> &arr) {
    int size = arr.size();
    int ans = 0;
    for (int i = 1; i <= size; i += 2) {
        for (int j = 0; j < size; j++) {
            ans += sumOddLengthSubarrays(arr, j, i);
        }
    }
    return ans;
}

int Solution1588::sumOddLengthSubarrays(vector<int> &arr, int start, int length) {
    int size = arr.size();
    int ans = 0;
    int step = 0;
    for (int i = start; i < size; i++) {
        if (step == length) {
            break;
        }
        ans += arr[i];
        step++;
    }
    if (step == length) {
        return ans;
    }
    return 0;
}
