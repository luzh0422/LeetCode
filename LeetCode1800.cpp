//
// Created by 陆泽辉 on 2022/10/7.
//

#include "LeetCode1800.h"

int LeetCode1800::maxAscendingSum(vector<int> &nums) {
    int ret = nums[0];
    int curr = nums[0];
    int n = nums.size();
    for (int i = 1; i < n; i++) {
        if (nums[i] > nums[i - 1]) {
            curr += nums[i];
        } else {
            curr = nums[i];
        }
        ret = max(ret, curr);
    }
    return ret;
}
