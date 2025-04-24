//
// Created by luzehui on 25-1-16.
//

#include "LeetCode3095.h"

int LeetCode3095::minimumSubarrayLength(vector<int> &nums, int k) {
    int n = nums.size(), res = INT_MAX;
    for (int i = 0; i < n; i++) {
        int num = nums[i];
        if (num >= k) {
            return 1;
        }
        for (int j = i + 1; j < n; j++) {
            num |= nums[j];
            if (num >= k) {
                res = min(res, j - i + 1);
                break;
            }
        }
    }
    return res == INT_MAX ? -1 : res;
}
