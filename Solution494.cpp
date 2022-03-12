//
// Created by luzh on 2021/6/7.
//

#include "Solution494.h"

int Solution494::findTargetSumWays(vector<int> &nums, int target) {
    int ans = 0;
    findTargetSumWays(nums, target, 0, 0, ans);
    return ans;
}

void Solution494::findTargetSumWays(vector<int> &nums, int target, int curr, int currIndex, int &ans) {
    if (currIndex == nums.size()) {
        if (curr == target) {
            ans += 1;
        }
        return;
    }
    int num = nums[currIndex];
    findTargetSumWays(nums, target, curr + num, currIndex + 1, ans);
    findTargetSumWays(nums, target, curr - num, currIndex + 1, ans);
    return;
}
