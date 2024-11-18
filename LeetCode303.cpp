//
// Created by luzehui on 2024/3/18.
//

#include "LeetCode303.h"

NumArray::NumArray(vector<int> &nums) {
    int preSum = 0;
    preSums.push_back(preSum);
    for (auto num : nums) {
        preSum += num;
        preSums.push_back(preSum);
    }
}

int NumArray::sumRange(int left, int right) {
    return preSums[right] - preSums[left - 1];
}
