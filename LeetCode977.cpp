//
// Created by luzehui on 2024/9/8.
//

#include "LeetCode977.h"

vector<int> LeetCode977::sortedSquares(vector<int> &nums) {
    int index = 0;
    while (index < nums.size() && nums[index] < 0) {
        index++;
    }
    int left = index - 1, right = index;
    vector<int> res;
    while (left >= 0 && right < nums.size()) {
        if (abs(nums[left]) < abs(nums[right])) {
            res.push_back(pow(nums[left], 2));
            left--;
        } else {
            res.push_back(pow(nums[right], 2));
            right++;
        }
    }
    while (left >= 0) {
        res.push_back(pow(nums[left], 2));
        left--;
    }
    while (right < nums.size()) {
        res.push_back(pow(nums[right], 2));
        right++;
    }
    return res;
}
