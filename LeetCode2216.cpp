//
// Created by luzehui on 2023/11/21.
//

#include "LeetCode2216.h"

int LeetCode2216::minDeletion(vector<int> &nums) {
    int n = nums.size();
    int res = 0;
    int i = 0;
    while (i < n - 1) {
        if ((i - res) % 2 == 0 && nums[i] == nums[i + 1]) {
            res++;
        }
        i++;
    }
    if ((n - res) % 2 == 1) {
        res++;
    }
    return res;
}
