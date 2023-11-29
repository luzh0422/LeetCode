//
// Created by 陆泽辉 on 2022/11/16.
//

#include "LeetCode775.h"


bool LeetCode775::isIdealPermutation(vector<int> &nums) {
    int index = nums.size() - 1;
    int minVal = nums[index];
    for (int i = index - 2; i >= 0; i--, index--) {
        if (nums[i] > minVal) {
            return false;
        }
        minVal = min(minVal, nums[index]);
    }
    return true;
}
