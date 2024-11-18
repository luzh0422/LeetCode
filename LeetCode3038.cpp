//
// Created by luzehui on 2024/6/7.
//

#include "LeetCode3038.h"

int LeetCode3038::maxOperations(vector<int> &nums) {
    int n = nums.size();
    int curr = -1, res = 0;
    for (int i = 0; i < n - 1; i++) {
        if (curr == -1) {
            curr = nums[i] + nums[++i];
            res++;
        } else if (curr == nums[i] + nums[++i]) {
            res++;
        } else {
            break;
        }
    }
    return res;
}
