//
// Created by luzehui on 2024/7/9.
//

#include "LeetCode3101.h"

long long LeetCode3101::countAlternatingSubarrays(vector<int> &nums) {
    long long distance = 1ll, res = 0ll;
    size_t n = nums.size();
    for (size_t i = 0; i < n - 1; i++) {
        if (nums[i] == nums[i + 1]) {
            res += (distance + 1) * distance / 2;
            distance = 1ll;
        } else {
            distance++;
        }
    }
    res += (distance + 1) * distance / 2;
    return res;
}
