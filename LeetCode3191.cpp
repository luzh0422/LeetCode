//
// Created by luzehui on 2024/10/18.
//

#include "LeetCode3191.h"

int LeetCode3191::minOperations(vector<int> &nums) {
    int res = 0, n = nums.size();
    for (int i = 0; i < n - 2; i++) {
        if (nums[i] == 0) {
            res++;
            nums[i] ^= 1;
            nums[i + 1] ^= 1;
            nums[i + 2] ^= 1;
        }
    }
    if (nums[n - 2] == 0 || nums[n - 1] == 0) {
        return -1;
    }
    return res;
}
