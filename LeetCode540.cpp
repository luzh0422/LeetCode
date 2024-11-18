//
// Created by luzehui on 2024/11/10.
//

#include "LeetCode540.h"

int LeetCode540::singleNonDuplicate(vector<int> &nums) {
    int left = 0, right = nums.size() - 1;
    int res = 0;
    while (left < right) {
        res ^= nums[left];
        res ^= nums[right];
        left++;
        right--;
    }
    res ^= nums[left];
    return res;
}
