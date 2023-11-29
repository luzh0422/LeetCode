//
// Created by 陆泽辉 on 2022/8/26.
//

#include "LeetCode1464.h"

int LeetCode1464::maxProduct(vector<int> &nums) {
    std::sort(nums.begin(), nums.end(), less<int>());
    return (nums[0] - 1) * (nums[1] - 1);
}
