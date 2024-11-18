//
// Created by luzehui on 2024/10/19.
//

#include "LeetCode3192.h"

int LeetCode3192::minOperations(vector<int> &nums) {
    int n = nums.size(), res = 0;
    for (int i = 0; i < n; i++) {
        int temp = res % 2;
        if (temp == 1 && (nums[i] ^ 1) == 0 || temp == 0 && nums[i] == 0) {
            res++;
        }
    }
    return res;
}
