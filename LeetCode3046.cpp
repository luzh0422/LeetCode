//
// Created by luzehui on 24-12-28.
//

#include "LeetCode3046.h"

bool LeetCode3046::isPossibleToSplit(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int first = 0, second = 1, n = nums.size();
    while (second < n - 1) {
        if (nums[first] == nums[second + 1]) {
            return false;
        }
        first += 1;
        second += 1;
    }
    return true;
}
