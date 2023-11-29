//
// Created by 陆泽辉 on 2022/11/27.
//

#include "LeetCode1752.h"

bool LeetCode1752::check(vector<int> &nums) {
    int minNum1 = nums[0];
    int maxNum2 = nums.back();
    int i = 0;
    while (i < nums.size() - 1) {
        if (nums[i] > nums[i + 1]) {
            break;
        }
        i++;
    }
    /**
     * 数列本身就是按递增排列；
     */
    if (i == nums.size() - 1) {
        return true;
    }
    i++;
    while (i < nums.size() - 1) {
        if (nums[i] > nums[i + 1]) {
            break;
        }
        i++;
    }
    return i == nums.size() - 1 && maxNum2 <= minNum1;
}
