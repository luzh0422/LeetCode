//
// Created by luzehui on 2023/11/15.
//

#include "LeetCode2656.h"

int LeetCode2656::maximizeSum(vector<int> &nums, int k) {
    int maxVal = *max_element(nums.begin(), nums.end());
    return maxVal * k + (k * (k + 1)) / 2;
}
