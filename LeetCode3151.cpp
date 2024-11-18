//
// Created by luzehui on 2024/8/13.
//

#include "LeetCode3151.h"

bool LeetCode3151::isArraySpecial(vector<int> &nums) {
    for (size_t i = 0; i < nums.size() - 1; i++) {
        if (((nums[i] & 1) ^ (nums[i + 1] & 1)) == 0)
            return false;
    }
    return true;
}
