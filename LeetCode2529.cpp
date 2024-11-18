//
// Created by luzehui on 2024/4/9.
//

#include "LeetCode2529.h"

int LeetCode2529::maximumCount(vector<int> &nums) {
    auto iter = lower_bound(nums.begin(), nums.end(), 0);
    int negativeCount = distance(nums.begin(), iter);
    while (iter != nums.end() && *iter == 0) {
        iter++;
    }
    int positiveCount = distance(iter, nums.end());
    return max(negativeCount, positiveCount);
}
