//
// Created by luzehui on 25-4-17.
//

#include "LeetCode2176.h"

int LeetCode2176::countPairs(vector<int> &nums, int k) {
    int res = 0;
    for (int i = 0; i < nums.size(); i++) {
        for (int j = i + 1; j < nums.size(); j++) {
            if (i * j % k == 0 && nums[i] == nums[j]) {
                 res++;
            }
        }
    }
    return res;
}
