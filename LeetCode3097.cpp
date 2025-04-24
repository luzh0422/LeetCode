//
// Created by luzehui on 25-1-17.
//

#include "LeetCode3097.h"

int LeetCode3097::minimumSubarrayLength(vector<int> &nums, int k) {
    int left = 0, right = 1, n = nums.size();
    int res = INT_MAX;
    int num = nums[left];
    vector<int> bits(32, 0);
    for (int i = 0; i < 32; i++) {
        if (((1 << i) & num) > 0) {
            bits[i]++;
        }
    }
    while (left <= right && right <= n) {
        if (num >= k) {
            res = min(res, max(right - left, 1));
            for (int i = 0; i < 32; i++) {
                int mask = 1 << i;
                if ((mask & nums[left]) > 0) {
                    bits[i]--;
                    if (bits[i] == 0) {
                        num -= mask;
                    }
                }
            }
            left++;
        } else {
            right++;
            if (right <= n) {
                num |= nums[right - 1];
                for (int i = 0; i < 32; i++) {
                    int mask = 1 << i;
                    if ((mask & nums[right - 1]) > 0) {
                        bits[i]++;
                    }
                }
            }
        }
    }
    return res == INT_MAX ? -1 : res;
}
