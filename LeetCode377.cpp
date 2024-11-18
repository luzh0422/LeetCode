//
// Created by luzehui on 2024/4/22.
//

#include "LeetCode377.h"

int LeetCode377::combinationSum4(vector<int> &nums, int target) {
    int res = combinationSum4(nums, target, 0);
    return res;
}

int LeetCode377::combinationSum4(vector<int> &nums, int target, int curr) {
    if (curr == target) {
        return 1;
    }
    if (curr > target) {
        return 0;
    }
    int res = 0;
    for (auto num : nums) {
        res += combinationSum4(nums, target, curr + num);
    }
    return res;
}
