//
// Created by luzehui on 2024/9/20.
//

#include "LeetCode2708.h"

long long LeetCode2708::maxStrength(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int index = 0, n = nums.size(), tag = false;
    long long res = 1ll;
    while (index < n - 1 && nums[index] < 0 && nums[index + 1] < 0) {
        res *= nums[index] * nums[index + 1];
        index += 2;
        tag = true;
    }
    while (index < n && nums[index] <= 0) {
        index++;
    }
    while (index < n) {
        res *= nums[index];
        index++;
        tag = true;
    }
    return tag ? res : nums.back();
}
