//
// Created by luzehui on 2024/6/30.
//

#include "LeetCode494.h"

int LeetCode494::findTargetSumWays(vector<int> &nums, int target) {
    return dfs(nums, target, 0, 0);
}

int LeetCode494::dfs(vector<int> &nums, int target, int index, int res) {
    int n = nums.size();
    if (index == n) {
        if (res == target)
            return 1;
        else
            return 0;
    }
    int temp = 0;
    temp += dfs(nums, target, index + 1, res + nums[index]);
    temp += dfs(nums, target, index + 1, res - nums[index]);
    return temp;
}
