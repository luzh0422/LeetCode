//
// Created by luzehui on 25-3-22.
//

#include "LeetCode2680.h"

long long LeetCode2680::maximumOr(vector<int> &nums, int k) {
    long long res = 0ll, s = 0ll, t = 0ll;
    for (auto num : nums) {
        s |= t & num;
        t |= num;
    }
    for (auto num : nums) {
        long long curr = t ^ num | s | (num << k);
        res = max(res, curr);
    }
    return res;
}
