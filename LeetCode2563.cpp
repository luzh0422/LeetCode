//
// Created by luzehui on 25-4-20.
//

#include "LeetCode2563.h"

long long LeetCode2563::countFairPairs(vector<int> &nums, int lower, int upper) {
    std::sort(nums.begin(), nums.end());
    long long res = 0ll;
    for (int i = 0; i < nums.size(); i++) {
        auto lowerIter = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]);
        auto upperIter = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]);
        res += distance(lowerIter, upperIter);
    }
    return res;
}
