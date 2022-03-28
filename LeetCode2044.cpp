//
// Created by luzh on 2022/3/15.
//

#include "LeetCode2044.h"

int LeetCode2044::countMaxOrSubsets(vector<int> &nums) {
    int maxNum = 0;
    int n = nums.size();
    for (int i = 0; i < n; i++) {
        maxNum |= nums[i];
    }
    int ret = countMaxOrSubsets(nums, 0, 0, maxNum);
    return ret;
}

int LeetCode2044::countMaxOrSubsets(vector<int> &nums, int currIndex, int currNum, int maxNum) {
    int n = nums.size();
    int ret = 0;
    for (int i = currIndex; i < n; i++) {
        int temp = currNum | nums[i];
        if (temp == maxNum) {
            ret++;
        }
        ret += countMaxOrSubsets(nums, i + 1, temp, maxNum);
    }
    return ret;
}
