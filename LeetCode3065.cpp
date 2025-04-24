//
// Created by luzehui on 25-1-14.
//

#include "LeetCode3065.h"

int LeetCode3065::minOperations(vector<int> &nums, int k) {
    int res = 0;
    for (auto& num : nums) {
        if (num < k)
            res++;
    }
    return res;
}
