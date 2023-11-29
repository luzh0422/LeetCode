//
// Created by 陆泽辉 on 2022/12/11.
//

#include "LeetCode1827.h"

int LeetCode1827::minOperations(vector<int> &nums) {
    int res = 0;
    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] <= nums[i - 1]) {
            int temp = nums[i - 1] - nums[i] + 1;
            res += temp;
            nums[i] += temp;
        }
    }
    return res;
}
