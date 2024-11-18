//
// Created by luzehui on 2024/7/26.
//

#include "LeetCode2740.h"

int LeetCode2740::findValueOfPartition(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size();
    int res = INT_MAX;
    for (int i = 0; i < n - 1; i++) {
        res = min(res, nums[i + 1] - nums[i]);
    }
    return res;
}
