//
// Created by luzehui on 2024/7/8.
//

#include "LeetCode724.h"

int LeetCode724::pivotIndex(vector<int> &nums) {
    int n = nums.size();
    vector<int> preSum(n + 1, 0);
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += nums[i];
        preSum[i + 1] = sum;
    }
    for (int i = 0; i < n; i++) {
        if (preSum[i] == sum - preSum[i + 1]) {
            return i;
        }
    }
    return -1;
}
