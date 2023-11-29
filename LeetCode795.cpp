//
// Created by 陆泽辉 on 2022/11/24.
//

#include "LeetCode795.h"

int LeetCode795::numSubarrayBoundedMax(vector<int> &nums, int left, int right) {
    return numSubarrayBoundedMax(nums, right + 1) - numSubarrayBoundedMax(nums, left);
}

int LeetCode795::numSubarrayBoundedMax(vector<int> &nums, int right) {
    int index = 0, maxVal = 0;
    int ret = 0;
    int n = nums.size();
    int curr = 0;
    while (index < n) {
        int num = nums[index];
        maxVal = max(maxVal, num);
        if (maxVal < right) {
            curr += 1;
            ret += curr;
        } else {
            curr = 0;
            maxVal = 0;
        }
        index++;
    }
    return ret;
}
