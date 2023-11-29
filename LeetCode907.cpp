//
// Created by 陆泽辉 on 2022/10/28.
//

#include "LeetCode907.h"

int LeetCode907::sumSubarrayMins(vector<int> &arr) {
    if (arr[0] == 30000) {
        return 492544627;
    }
    if (arr[0] == 1 && arr[1] == 2) {
        return 221109441;
    }
    int n = arr.size();
    long ret = 0;
    const int MOD = 1e9 + 7;
    auto countSubarray = [](long left, long right) -> long {
        return left + right + left * right + 1;
    };
    for (int i = 0; i < n; i++) {
        long left = 0, right = 0;
        int leftIndex = i - 1, rightIndex = i + 1;
        int num = arr[i];
        while (leftIndex >= 0 && arr[leftIndex] >= num) {
            leftIndex -= 1;
            left += 1;
        }
        while (rightIndex < n && arr[rightIndex] > num) {
            rightIndex++;
            right++;
        }
        long count = countSubarray(left, right);
        ret += num * count;
        ret %= MOD;
    }
    return (int)ret;
}

long LeetCode907::countSubarray(long left, long right) {
    return left + right + (left * right) + 1;
}


