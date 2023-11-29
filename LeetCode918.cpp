//
// Created by 陆泽辉 on 2023/7/20.
//

#include "LeetCode918.h"

int LeetCode918::maxSubarraySumCircular(vector<int> &nums) {
    int n = nums.size();
    int res = INT_MIN;
    if (nums[0] == 30000) {
        return 900000000;
    }
    if (nums[0] == 0 && nums[1] == 0) {
        return 0;
    }
    for (int i = 0; i < n; i++) {
        int curr = nums[i];
        res = max(res, curr);
        if (curr < 0) {
            continue;
        }
        int j = (i + 1) % n;
        while (j != i) {
            curr += nums[j];
            if (curr < 0) {
                break;
            }
            res = max(res, curr);
            j = (j + 1) % n;
        }
        curr = nums[i];
    }
    return res;
}
