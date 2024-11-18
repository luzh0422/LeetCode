//
// Created by luzehui on 2024/10/16.
//

#include "LeetCode3194.h"

double LeetCode3194::minimumAverage(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int left = 0, right = nums.size() - 1;
    double res = 100.0;
    while (left <= right) {
        res = min(res, (static_cast<double>(nums[left]) + static_cast<double>(nums[right])) / 2.0);
        left++;
        right--;
    }
    return res;
}
