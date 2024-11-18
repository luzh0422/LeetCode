//
// Created by luzehui on 2024/9/13.
//

#include "LeetCode2860.h"

int LeetCode2860::countWays(vector<int> &nums) {
    std::sort(nums.begin(), nums.end());
    int n = nums.size(), res = 0;
    for (int i = 0; i < n + 1; i++) {
        bool tag = true;
        if (i > 0) {
            if (nums[i - 1] >= i) {
                tag = false;
            }
        }
        if (i < n) {
            if (nums[i] <= i) {
                tag = false;
            }
        }
        if (tag) {
            res++;
        }
    }
    return res;
}
